/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:49:59 by ann               #+#    #+#             */
/*   Updated: 2022/06/20 09:52:46 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <limits>
#include <iterator>
#include "iterator.hpp"
#include "additional.hpp"

namespace ft
{

	template <typename T> class vectorIterator;

	template < typename T, typename _Alloc = std::allocator<T> > 
	class	vector
	{
	public:
		/*			Member Types			*/
    	typedef T 											value_type;
    	typedef _Alloc										allocator_type;
		typedef value_type&									reference;
		typedef const value_type&							const_reference;
    	typedef typename allocator_type::pointer			pointer;
    	typedef typename allocator_type::const_pointer		const_pointer;
		typedef	ft::vectorIterator<T>						iterator; /*i also need the const version*/
		typedef ft::reverse_iterator<iterator>				reverse_iterator; /*i also need the const version*/
		typedef std::ptrdiff_t 									difference_type;
    	typedef size_t										size_type;

	private:
		/*			Private Members			*/
		pointer _start;
		pointer _end;
		pointer _end_of_memory;
		allocator_type	_myAlloc;

		void	realloc_vec(size_type new_capacity){
			/* allocate and construct copies of previous memory */
			pointer temp = _myAlloc.allocate(new_capacity);
			size_type temp_size = this->size();
			for (size_type i = 0; i < temp_size; ++i)
				_myAlloc.construct(temp + i, *(this->_start + i));

			/* destroy and deallocate */
			for (size_type i = 0; i < temp_size; ++i) _myAlloc.destroy(this->_start + i);
			_myAlloc.deallocate(this->_start, temp_size);
			
			/* replace the old memory (maybe i could use swap) */
			this->_start = temp;
			this->_end = temp + temp_size;
			this->_end_of_memory = temp + new_capacity;
		}
	public:

		/*			Constuctors			*/
		explicit vector (const allocator_type& alloc = allocator_type()): _start(0), _end(0), _end_of_memory(0), _myAlloc(alloc) {}

		explicit vector( size_type count, const_reference value = value_type(), const allocator_type& alloc = allocator_type())
			: _myAlloc(alloc){
			this->_start = _myAlloc.allocate(count);
			for (size_type i = 0; i < count; ++i) _myAlloc.construct(this->_start + i, value);
			this->_end = this->_start + count;
			this->_end_of_memory = this->_end;
		}

		template< class InputIt, typename enable_if< !is_integral<InputIt>::value >::type >
		vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type())
			: _myAlloc(alloc){
			for (; first != last; ++first) push_back(*first);
		}

		/*		Copy constructor and copy assignment		*/
		vector(const vector& other) : _myAlloc(other._myAlloc){
			this->_start = _myAlloc.allocate(other.capacity());

			for (size_type i = 0; i < other.size(); ++i) _myAlloc.construct(this->_start + i, other[i]);
			this->_end = this->_start + other.size();
			this->_end_of_memory = this->_start + other.capacity();
		}

		vector<value_type> & operator=(const vector& other){
			if (this != &other)
			{
				_myAlloc = other._myAlloc;

				clear();
				if (this->capacity())
					_myAlloc.deallocate(this->_start, this->capacity());
		
				this->_start = _myAlloc.allocate(other.capacity());
				for (size_type i = 0; i < other.size(); ++i) _myAlloc.construct(this->_start + i, other[i]);
				this->_end = this->_start + other.size();
				this->_end_of_memory = this->_start + other.capacity();
			}
			return *(this);
		}

		/*			Destructor		*/
		~vector(){		
			clear();
			_myAlloc.deallocate(this->_start, this->capacity());
		}

		/*			Allocator		*/

		allocator_type get_allocator() const{
			return _myAlloc;
		}

		/*			Element access		*/
		reference	at(size_type pos){
			if (pos < this->size()) return *(this->_start + pos);
			throw std::out_of_range("vector::range_check error");
		}

		const_reference at(size_type pos) const{
			if (pos < this->size()) return *(this->_start + pos);
			throw std::out_of_range("vector::range_check error");
		}

		reference	operator[](size_type pos){
			return  *(this->_start + pos);
		}

		const_reference operator[] (size_type pos) const{
			return  *(this->_start + pos);
		}

		reference	front(){
			return *(this->_start);
		}

		const_reference front() const{
			return *(this->_start);
		}

		reference	back(){
			return *(this->_end - 1);
		}

		const_reference back() const{
			return *(this->_end - 1);
		}

		// T* data(){
		// 	return (this->_start);
		// }

		// const T* data() const{
		// 	return (this->_start);
		// }

		/*			Iterators			*/
		iterator	begin(void){
			return (iterator(this->_start));
		}

		// const_iterator begin() const{
		// 	return (iterator(this->_start));
		// }

		iterator	end(void){
			return (iterator(this->_end));
		}
		
		reverse_iterator	rbegin(void){
			return (reverse_iterator(end()));
		}

		reverse_iterator	rend(void){
			return (reverse_iterator(begin()));
		}

		/*			Capacity			*/
		bool	empty(void) const{
			return (this->_start == this->_end);
		}
		
		size_type	size(void) const{
			return (static_cast<size_type>(this->_end - this->_start));
		}

		size_type	max_size() const{
			return (_myAlloc.max_size());
		}

		void resize(size_type new_size, T value = T() ){
			if (new_size < this->size())
			{
				/* maybe when i figure out how to implement erase() i can use erase here */
				for (size_type i = new_size; i < this->size(); ++i) _myAlloc.destroy(this->_start + i);
				this->_end = this->_start + new_size;
			}
			else if (new_size > this->size())
				for (size_type i = this->size(); i < new_size; ++i) this->push_back(value);
		}

		size_type	capacity(void) const{
			return (static_cast<size_type>(this->_end_of_memory - this->_start));
		}

		void	reserve(size_type new_cap){
			if (new_cap > this->max_size()) throw std::length_error("Invalid reserve() input");
			if (new_cap > this->capacity())
				realloc_vec(new_cap);
		}


		/*			Modifiers			*/
		
		void assign( size_type count, const_reference value ){
			this->clear();
			if (count > this->capacity())
				realloc_vec(count);
			for (size_type i = 0; i < count; ++i) _myAlloc.construct(this->_start + i, value);
			this->_end = this->_start + count;
		}

		template< class InputIt, typename enable_if< !is_integral<InputIt>::value >::type >
		void assign(InputIt first, InputIt last)
		{
			// size_type count = static_cast<size_type>(&*last - &*first);
			size_type count = static_cast<size_type>(last - first);
			this->clear();
			if (count > this->capacity())
				realloc_vec(count);
			for (size_type i = 0; first != last; ++first, ++i) _myAlloc.construct(this->_start + i, *first);
			this->_end = this->_start + count;
		}

		void	push_back(const_reference value){
			if (this->_start == this->_end_of_memory)
				realloc_vec(1);
			else if (this->size() == this->capacity())
				realloc_vec(this->capacity() * 2);
			_myAlloc.construct(this->_start + this->size(), value);
			++this->_end;
		}

		void pop_back(){
			_myAlloc.destroy(--this->_end);
		}

		void clear(){
			for (size_type i = 0; i < this->size(); ++i) _myAlloc.destroy(this->_start + i);
			this->_end = this->_start;
		}

		iterator erase( iterator pos ){
			pointer temp = &(*pos);
			
			for (; pos < this->end() - 1; ++pos, ++temp)
				_myAlloc.construct(temp, *(temp + 1));
			_myAlloc.destroy(temp);
			--this->_end;

			return (pos);
		}
		
		/* PLS CONTINUE WORKING ON THIS */
		iterator erase( iterator first, iterator last )
		{		
			pointer save = &(*first);
			pointer st = &(*first);
			pointer re = &(*first);
			size_type count = 0;
			
			for (; first != last; ++first, ++count)
				_myAlloc.destroy(st++);
			for (; last != this->end(); ++last, ++st)
				_myAlloc.construct(save++, *st);
			this->_end -= count;

			return (iterator(re));
			
		}

		iterator insert( iterator pos, const T& value ){
			push_back(value);
			
			// std::cout << "pos " << &*pos << " and end - 1 is " << &*(this->end() - 2) << std::endl;
			if (pos == this->end() - 1)
				_myAlloc.construct(&(*(this->end() - 1)), *(this->end() - 2));
			else
			{
				for (iterator it = this->end() - 2; it != pos - 1 && it != this->begin() - 1; --it)
					{_myAlloc.construct(&(*it) + 1, *(it)); std::cout << "I AM HERE\n";} /* backwards copying to avoid overlapping (similar to memmove) */	
			}
			/*ENABLE IF TO FIX THIS*/
			// for (ft::reverse_iterator<iterator> rit = this->rbegin(); rit != pos - 1 && rit != this->rend(); ++rit) /**/
				// alloc.construct(&(*rit) + 1, *(rit)); /* backwards copying to avoid overlapping (similar to memmove) */
			_myAlloc.construct(&(*pos), value);
			// for (iterator it = this->begin(); it != end(); ++it)	std::cout << *it << std::endl;
			return (pos);
		}

		void insert( iterator pos, size_type count, const T& value ){
			for (size_type i = 0; i < count; ++i) push_back(value);
			
			for (iterator it = this->end() - count - 1; it != pos - 1 && it != this->begin() - 1; --it)
				_myAlloc.construct(&(*it) + count, *(it)); /* backwards copying to avoid overlapping (similar to memmove) */
			// for (iterator it = this->begin(); it != end(); ++it)	std::cout << *it << std::endl;
			for (size_type i = 0; i < count; ++i, ++pos)
				{_myAlloc.construct(&(*pos), value); std::cout << "HOWOWO " << i << std::endl;}
			// for (iterator it = this->begin(); it != end(); ++it)	std::cout << *it << std::endl;
			
		}

		// template< class InputIt >
		// voidinsert( iterator pos, InputIt first, InputIt last );
	
		void swap( vector& other ){
			/*replace with iterators later and maybe use XOR to swap */
			/* orr just use copy constructor */
			vector temp(other);
			other = *this;
			*this = temp;
		}

		/*		Non-member functions	*/
		// template< class TYPE, class Alloc >
		// friend bool operator==( const ft::vector<TYPE,Alloc>& lhs, const ft::vector<TYPE,Alloc>& rhs ){
		// 	if (lhs.size() != rhs.size())
		// 		return false;
		// 	for (size_type i = 0; i < lhs.size(); ++i)
		// 		if (lhs[i] != rhs[i]) return false;
		// 	return true;
		// }

		// template< class TYPE, class Alloc >
		// friend bool operator!=( const ft::vector<TYPE,Alloc>& lhs, const ft::vector<TYPE,Alloc>& rhs ){
		// 	return !(lhs == rhs);
		// }

		// template< class TYPE, class Alloc >
		// friend bool operator<( const ft::vector<TYPE,Alloc>& lhs, const ft::vector<TYPE,Alloc>& rhs ){
		// 	return (ft::lexicographical_compare(lhs, rhs));
		// }
		// template< class TYPE, class Alloc >
		// friend bool operator<=( const ft::vector<TYPE,Alloc>& lhs, const ft::vector<TYPE,Alloc>& rhs ){
		// 	return (ft::lexicographical_compare(lhs, rhs));
		// }
		
		// template< class TYPE, class Alloc >
		// friend bool operator>( const ft::vector<TYPE,Alloc>& lhs, const ft::vector<TYPE,Alloc>& rhs ){
		// 	return (ft::lexicographical_compare(rhs, lhs));
		// }
		// template< class TYPE, class Alloc >
		// friend bool operator>=( const ft::vector<TYPE,Alloc>& lhs, const ft::vector<TYPE,Alloc>& rhs ){
		// 	return (ft::lexicographical_compare(rhs, lhs));
		// }

	};

	/*		std::swap specialization		*/
	template< class T, class Alloc >
	void swap( ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs ){
		lhs.swap(rhs);
	}

	/*		ft::vector iterator				*/
	template <typename T>
	class vectorIterator
	{
		// friend class vector<T>;
		// typedef typename	vector<T>::value_type* pointer;
	
	vectorIterator	base(void) {return *(this);}
	public:
		typedef typename ft::vector<T>::difference_type   difference_type;
		typedef typename ft::vector<T>::value_type        value_type;
		typedef typename ft::vector<T>::pointer           pointer;
		typedef typename ft::vector<T>::reference         reference;
		typedef typename std::random_access_iterator_tag iterator_category;
		vectorIterator(void) {it_start = 0;}
		vectorIterator(pointer temp) {it_start = temp;}
		vectorIterator(vectorIterator const & iter) {it_start = iter.it_start;}
		vectorIterator & operator=(vectorIterator const & iter) {this->it_start = iter.it_start; return *(this);}
		~vectorIterator() {}

		/*YOU HAVE TO IMPLEMENT '->' also !!!*/
		reference	operator*(void){
			return *(this->it_start);
		}

		reference	operator->(void){
			return (this->it_start);
		}

		vectorIterator operator++(void){
			++this->it_start;
			return (*this);
		}

		vectorIterator operator++(int){
			vectorIterator temp;
			temp.it_start = this->it_start++;
			return (temp);
		}

		vectorIterator operator--(void){
			--this->it_start;
			return (*this);
		}

		vectorIterator operator--(int){
			vectorIterator temp;
			temp.it_start = this->it_start--;
			return (temp);
		}

		// bool	operator<(const vectorIterator & rhs) {return (this->it_start < rhs.it_start);}
		// bool	operator<=(const vectorIterator & rhs) {return (this->it_start <= rhs.it_start);}
		// bool	operator>(const vectorIterator & rhs) {return (this->it_start > rhs.it_start);}
		// bool	operator>=(const vectorIterator & rhs) {return (this->it_start >= rhs.it_start);}
		// bool	operator==(const vectorIterator & rhs) {return (this->it_start == rhs.it_start);}
		// bool	operator!=(const vectorIterator & rhs) {return (this->it_start != rhs.it_start);}

		vectorIterator		operator+(const vectorIterator & rhs) const
		{
			vectorIterator temp(*this);
			temp = this->it_start + rhs.it_start;
			return (temp);
		}
		vectorIterator		operator+(difference_type n) const
		{
			vectorIterator temp(*this);
			temp = this->it_start + n;
			return (temp);
		}
		vectorIterator &	operator+=(difference_type n)
		{
			this->it_start += n;
			return *(this);
		}
		vectorIterator		operator-(const vectorIterator & rhs) const
		{
			vectorIterator temp(*this);
			temp = this->it_start - rhs.it_start;
			return (temp);
		}
		vectorIterator		operator-(difference_type n) const
		{
			vectorIterator temp(*this);
			temp = this->it_start - n;
			return (temp);
		}
		vectorIterator &	operator-=(difference_type n) 
		{
			this->it_start -= n;
			return *(this);
		}
		reference	operator[](difference_type n) {return (this->it_start[n]);}

	friend bool operator==(const vectorIterator & lhs, const vectorIterator & rhs){
		return lhs.it_start == rhs.it_start;
	}

	friend bool operator!=(const vectorIterator & lhs, const vectorIterator & rhs){
		return lhs.it_start != rhs.it_start;
	}

	friend bool operator>(const vectorIterator & lhs, const vectorIterator & rhs){
		return lhs.it_start > rhs.it_start;
	}

	friend bool operator>=(const vectorIterator & lhs, const vectorIterator & rhs){
		return lhs.it_start >= rhs.it_start;
	}

	friend bool operator<(const vectorIterator & lhs, const vectorIterator & rhs){
		return lhs.it_start < rhs.it_start;
	}

	friend bool operator<=(const vectorIterator& lhs, const vectorIterator & rhs){
		return lhs.it_start <= rhs.it_start;
	}

	friend typename vectorIterator::difference_type operator-(const vectorIterator & lhs, const vectorIterator & rhs){
		return lhs.it_start - rhs.it_start;
	}

	friend vectorIterator operator+(typename vectorIterator::difference_type n, const vectorIterator& it){
		return vectorIterator(it + n);
	}

	private:
		pointer	it_start;
	};
	
	/*	Nonmember operators		*/



	// template< class Iter >
	// bool operator!=( Iter & lhs, Iter & rhs){
	// 	return lhs.base() != rhs.base();
	// }

	

}

#endif