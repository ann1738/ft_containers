/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:49:59 by ann               #+#    #+#             */
/*   Updated: 2022/06/19 08:42:38 by ann              ###   ########.fr       */
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
		typedef typename std::ptrdiff_t   difference_type;
		typedef typename std::random_access_iterator_tag iterator_category;
		/*			Member Types			*/
    	typedef T 							value_type;
		typedef value_type&					reference;
		typedef const value_type&			const_reference;
    	typedef std::size_t					size_type;
    	typedef _Alloc						allocator_type;
    	typedef typename allocator_type::pointer	pointer; //check this
    	typedef typename allocator_type::const_pointer	const_pointer;

		
		// typedef	std::iterator<pointer, value_type>	iterator;
		// typedef	std::iterator<const_pointer, value_type>	const_iterator;
		typedef		ft::vectorIterator<T>		iterator;
		typedef 	ft::reverse_iterator<iterator>		reverse_iterator;
	private:
		/*			Private Members			*/
		pointer _start;
		pointer _end;
		pointer _end_of_memory;
	public:

		/*		Copy constructor and copy assignment		*/
		vector(const vector& other){
			allocator_type alloc = allocator_type();
			this->_start = alloc.allocate(other.capacity());

			for (size_type i = 0; i < other.size(); ++i) alloc.construct(this->_start + i, other[i]);
			this->_end = this->_start + other.size();
			this->_end_of_memory = this->_start + other.capacity();
		}

		vector<value_type> & operator=(const vector& other){
			if (this != &other)
			{
				allocator_type alloc = allocator_type();

				for (size_type i = 0; i < this->size(); ++i) alloc.destroy(this->_start + i);
				if (this->capacity())
					alloc.deallocate(this->_start, this->capacity());
				
				this->_start = alloc.allocate(other.capacity());

				for (size_type i = 0; i < other.size(); ++i) alloc.construct(this->_start + i, other[i]);
				this->_end = this->_start + other.size();
				this->_end_of_memory = this->_start + other.capacity();
			}
			return *(this);
		}

		/*			Constuctors			*/
		vector(void): _start(0), _end(0), _end_of_memory(0) {}

		explicit vector( const allocator_type& alloc ):  _start(0), _end(0), _end_of_memory(0) {static_cast<void>(alloc);}

		template< class InputIt >
		vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type()){
			static_cast<void>(alloc);
			for (; first != last; ++first) push_back(*first);
		}

		explicit vector( size_type count, const_reference value = value_type(), allocator_type alloc = allocator_type())
		{
			this->_start = alloc.allocate(count);
			/*not needed*/
			this->_end = this->_start;
			this->_end_of_memory = this->_end + count;
			/************/

			for (size_type i = 0; i < count; ++i) alloc.construct(this->_start + i, value);
			this->_end = this->_start + count;
			this->_end_of_memory = this->_end;
		}

		/*			Destructor		*/
		~vector(){
			allocator_type alloc = allocator_type();
		
			for (size_type i = 0; i < this->size(); ++i) alloc.destroy(this->_start + i);
			alloc.deallocate(this->_start, this->capacity());
		}

		void assign( size_type count, const T& value ){
			allocator_type alloc = allocator_type();
			this->clear();
			if (count > this->capacity())
				this->reserve(count);
			for (size_type i = 0; i < count; ++i) alloc.construct(this->_start + i, value);
			this->_end = this->_start + count;
		}

		template< class InputIt >
		void assign( InputIt first, InputIt last )
		{
			size_type count = static_cast<size_type>(&*last - &*first);
			allocator_type alloc = allocator_type();
			this->clear();
			if (count > this->capacity())
				this->reserve(count);
			for (size_type i = 0; i < count; ++i) alloc.construct(this->_start + i, *first);
			this->_end = this->_start + count;
		}

		allocator_type get_allocator() const{
			return allocator_type();
		}

		/*			Element access		*/
		reference	at(size_type pos){
			if (pos < this->size()) return *(this->_start + pos);
			throw std::out_of_range("vector::range_check error");
		}

		const_reference at( size_type pos ) const{
			if (pos < this->size()) return *(this->_start + pos);
			throw std::out_of_range("vector::range_check error");
		}

		reference	operator[](size_type pos){
			return  *(this->_start + pos);
		}

		const_reference operator[](size_type pos) const{
			return  *(this->_start + pos);
		}

		reference	front(void){
			return *(this->_start);
		}

		const_reference front() const{
			return *(this->_start);
		}

		reference	back(void){
			return *(this->_end - 1);
		}

		const_reference back() const{
			return *(this->_end - 1);
		}

		T* data(){
			return (this->_start);
		}

		const T* data() const{
			return (this->_start);
		}

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
			return (std::numeric_limits<difference_type>::max());
		}

		void	reserve(size_type new_cap){
			if (new_cap > this->max_size()) throw std::length_error("Invalid reserve() input");
			if (new_cap > this->capacity())
			{
				allocator_type alloc = allocator_type();
				/* allocate and construct copies of previous memory */
				pointer temp = alloc.allocate(new_cap);
				size_type temp_size = this->size();
				for (size_type i = 0; i < this->size(); ++i)
					alloc.construct(temp + i, *(this->_start + i));

				/* destroy and deallocate */
				for (size_type i = 0; i < temp_size; ++i) alloc.destroy(this->_start + i);
				alloc.deallocate(this->_start, temp_size);
				
				/* replace the old memory (maybe i could use swap) */
				this->_start = temp;
				this->_end = temp + temp_size + 1;
				this->_end_of_memory = temp + new_cap;
			}
		}

		size_type	capacity(void) const{
			return (static_cast<size_type>(this->_end_of_memory - this->_start));
		}

		/*			Modifiers			*/
		void	push_back( const_reference value ){
			allocator_type alloc = allocator_type();
			if (this->_end == this->_start)
			{
				this->_start = alloc.allocate(1);
				alloc.construct(this->_start, value);
				this->_end = this->_start + 1;
				this->_end_of_memory = this->_start + 1;
			}
			else if (this->size() != this->capacity())
			{
				alloc.construct(this->_start + this->size(), value);
				++this->_end;
			}
			else
			{
				/* allocate and construct copies of previous memory */
				pointer temp = alloc.allocate(this->capacity() * 2);
				size_type temp_size = this->size();
				for (size_type i = 0; i < this->size(); ++i)
					alloc.construct(temp + i, *(this->_start + i));

				/* add the new element */
				alloc.construct(temp + this->size(), value);

				/* destroy and deallocate */
				for (size_type i = 0; i < temp_size; ++i) alloc.destroy(this->_start + i);
				alloc.deallocate(this->_start, temp_size);
				
				/* replace the old memory (maybe i could use swap) */
				this->_start = temp;
				this->_end = temp + temp_size + 1;
				this->_end_of_memory = temp + (temp_size * 2);
			}
		}

		void pop_back(){
			allocator_type alloc = allocator_type();
			
			alloc.destroy(--this->_end);
		}

		void resize(size_type new_size, T value = T() ){
			if (new_size < this->size())
			{
				allocator_type alloc = allocator_type();
				/* maybe when i figure out how to implement erase() i can use erase here */
				for (size_type i = new_size; i < this->size(); ++i) alloc.destroy(this->_start + i);
				this->_end = this->_start + new_size;
			}
			else if (new_size > this->size())
			{
				for (size_type i = this->size(); i < new_size; ++i) this->push_back(value);
			}
		}

		void clear(){
			allocator_type alloc = allocator_type();
			for (size_type i = 0; i < this->size(); ++i) alloc.destroy(this->_start + i);
			this->_end = this->_start;
		}

		iterator erase( iterator pos ){
			allocator_type alloc = allocator_type();
			pointer temp = &(*pos);
			pointer re = &(*pos) + 1;
			
			for (; pos != this->end() - 1; ++pos)
			{
				alloc.construct(temp, *(temp + 1));
				++temp;
			}
			alloc.destroy(temp);
			--this->_end;
			return (iterator(re));
		}
		
		/* PLS OPTIMIZE THIS BS */
		iterator erase( iterator first, iterator last )
		{		
			allocator_type alloc = allocator_type();
			pointer save = &(*first);
			pointer st = &(*first);
			pointer re = &(*last);
			size_type count = 0;
			
			for (; first != last; ++first, ++count)
				alloc.destroy(st++);
			for (; last != this->end(); ++last)
			{
				alloc.construct(save++, *st);
				++st;
			}
			this->_end -= count;
			std::cout << "COUNT IS -> " << count << std::endl;
			return (iterator(re));
			
		}

		iterator insert( iterator pos, const T& value ){
			allocator_type alloc = allocator_type();
			push_back(value);
			
			for (iterator it = this->end() - 2; it != pos - 1 && it != this->begin() - 1; --it)
				alloc.construct(&(*it) + 1, *(it)); /* backwards copying to avoid overlapping (similar to memmove) */
			/*ENABLE IF TO FIX THIS*/
			// for (ft::reverse_iterator<iterator> rit = this->rbegin(); rit != pos - 1 && rit != this->rend(); ++rit) /**/
				// alloc.construct(&(*rit) + 1, *(rit)); /* backwards copying to avoid overlapping (similar to memmove) */
			alloc.construct(&(*pos), value);
			return (pos);
		}

		void insert( iterator pos, size_type count, const T& value ){
			allocator_type alloc = allocator_type();
			for (size_type i = 0; i < count; ++i) push_back(value);
			
			for (iterator it = this->end() - count - 1; it != pos - 1 && it != this->begin() - 1; --it)
				alloc.construct(&(*it) + count, *(it)); /* backwards copying to avoid overlapping (similar to memmove) */
			for (iterator it = this->begin(); it != end(); ++it)	std::cout << *it << std::endl;
			for (size_type i = 0; i < count; ++i, ++pos)
				{alloc.construct(&(*pos), value); std::cout << "HOWOWO " << i << std::endl;}
			for (iterator it = this->begin(); it != end(); ++it)	std::cout << *it << std::endl;
			
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
		typedef typename ft::vector<T>::iterator_category iterator_category;
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