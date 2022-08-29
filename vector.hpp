/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:49:59 by ann               #+#    #+#             */
/*   Updated: 2022/08/29 11:27:59 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <limits>
#include "iterators/iterator.hpp"
#include "additional.hpp"
#include "iterators/vectorIterator.hpp"

namespace ft
{
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
		typedef	ft::vectorIterator<T, _Alloc>						iterator;
		typedef	ft::vectorIterator<const T, _Alloc>					const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef std::ptrdiff_t 								difference_type;
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
			size_type temp_capacity = this->capacity();
			for (size_type i = 0; i < temp_size; ++i)
				_myAlloc.construct(temp + i, *(this->_start + i));

			/* destroy and deallocate */
			for (size_type i = 0; i < temp_size; ++i) _myAlloc.destroy(this->_start + i);
			_myAlloc.deallocate(this->_start, temp_capacity);
			
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

		template< class InputIt>
		vector(InputIt first, InputIt last, 
			typename ft::enable_if< !ft::is_integral<InputIt>::value, InputIt >::type* = 0, const allocator_type& alloc = allocator_type())
			: _myAlloc(alloc){
			size_type count = 0;
			for (InputIt it = first; it != last; ++it, ++count);
				
			this->_start = _myAlloc.allocate(count);
			for (size_type i = 0; first != last; ++first, ++i) _myAlloc.construct(this->_start + i, *first);
			this->_end = this->_start + count;
			this->_end_of_memory = this->_end;
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
				this->_start = _myAlloc.allocate(other.size());
				for (size_type i = 0; i < other.size(); ++i) _myAlloc.construct(this->_start + i, other[i]);
				this->_end = this->_start + other.size();
				this->_end_of_memory = this->_start + other.size();
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

		/*			Iterators			*/
		iterator	begin(void){
			return (iterator(this->_start));
		}

		const_iterator begin() const{
			return (const_iterator(this->_start));
		}

		iterator	end(void){
			return (iterator(this->_end));
		}
	
		const_iterator	end(void) const{
			return (const_iterator(this->_end));
		}
		
		reverse_iterator	rbegin(void){
			return (reverse_iterator(end()));
		}
		
		const_reverse_iterator	rbegin(void) const{
			return (const_reverse_iterator(end()));
		}

		reverse_iterator	rend(void){
			return (reverse_iterator(begin()));
		}

		const_reverse_iterator	rend(void) const{
			return (const_reverse_iterator(begin()));
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
				for (size_type i = new_size; i < this->size(); ++i) _myAlloc.destroy(this->_start + i);
				this->_end = this->_start + new_size;
			}
			else
				for (size_type i = this->size(); i < new_size; ++i) this->push_back(value);
			// else if (new_size > this->size() && new_size <= this->capacity())
			// 	for (size_type i = this->size(); i < new_size; ++i) this->push_back(value);
			// else if (new_size > this->size() && new_size > this->capacity())
			// {
			// 	realloc_vec(new_size);
			// 	for (size_type i = this->size(); i < new_size; ++i) _myAlloc.construct(this->_start + i, value);
			// 	this->_end = this->_start + new_size;
			// }
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

		template< class InputIt >
		void assign(InputIt first, InputIt last,
					typename enable_if< !is_integral<InputIt>::value >::type* = 0)
		{
			size_type count = 0;
			for (InputIt it = first; it != last; ++it, ++count);
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

		iterator erase(iterator pos){
			pointer save = &(*pos);
			pointer temp = &(*pos);
			
			for (; pos < this->end() - 1; ++pos, ++temp)
				_myAlloc.construct(temp, *(temp + 1));
			_myAlloc.destroy(temp);
			--this->_end;

			return (iterator(save));
		}
		
		iterator erase(iterator first, iterator last)
		{		
			pointer save = &(*first);
			pointer re = &(*first);
			size_type offset = static_cast<size_type>(last - first);

			if (first >= last) return(last);
			for (; first + offset != this->end(); ++first, ++save)
				_myAlloc.construct(save, *(save + offset));
			for (iterator it = this->end() - offset;  it != this->end(); ++it)
				_myAlloc.destroy(&*it);
			this->_end -= offset;

			return (iterator(re));
		}

		iterator insert( iterator pos, const T& value ){ //fix issues
			size_type offset = pos - begin();
			push_back(value);
			iterator it = this->end() - 2;
			iterator	update_pos(this->_start + offset);
			for (; it >= update_pos && it >= this->begin(); --it)
				_myAlloc.construct(&(*it) + 1, *(it)); /* backwards copying to avoid overlapping (similar to memmove) */
			// std::cout << "\e[31m" << *++it << "\e[0m\n";
			_myAlloc.construct(this->_start + offset, value); //do i need to delete here
			return (update_pos);
		}

		void insert( iterator pos, size_type count, const T& value ){
			size_type offset = static_cast<size_type>(pos - this->begin());
			
			if (count + this->size() > this->capacity())
				realloc_vec(count + this->size());
			size_type i = 0;
			for (iterator it = this->end() - 1; it != this->begin() + offset - 1; --it, ++i)
				_myAlloc.construct(&*it + count, *it);
			for (i = 0; i < count; ++i, ++offset)
				_myAlloc.construct(this->_start + offset, value);
			this->_end += count;
		}

		template <class InputIterator>
   		void insert (iterator position, InputIterator first, InputIterator last,
		typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator >::type* = 0){
			// if (first >= last) return ; //do i need this
			size_type pos_offset = static_cast<size_type>(position - begin());
			size_type range = 0;
			for (InputIterator it = first; it != last; ++it, ++range);
			if (range + size() > capacity())
			{
				realloc_vec(range + size() <= size() * 2 ? size() * 2 : range + size());
				position = iterator(this->_start + pos_offset);
			}
			for (iterator it = end() - 1; it >= position; --it)
			{
				_myAlloc.construct(&*it + range, *it);
				// _myAlloc.destroy(&*it);
			}
			for (; first != last; ++first, ++position)
				_myAlloc.construct(&*position, *first);
			this->_end += range;
		}

		void swap(vector& other){
			ft::myswap<pointer>(this->_start, other._start);
			ft::myswap<pointer>(this->_end, other._end);
			ft::myswap<pointer>(this->_end_of_memory, other._end_of_memory);
			ft::myswap<allocator_type>(this->_myAlloc, other._myAlloc);
		}
	};

	/*		Non-member functions	*/
	template< typename T, typename _Alloc >
	bool operator==( const ft::vector<T,_Alloc>& lhs, const ft::vector<T,_Alloc>& rhs ){
		if (lhs.size() != rhs.size())
			return false;
		for (typename ft::vector<T,_Alloc>::size_type i = 0; i < lhs.size(); ++i)
			if (lhs[i] != rhs[i]) return false;
		return true;
	}

	template< typename T, typename _Alloc >
	bool operator!=( const ft::vector<T,_Alloc>& lhs, const ft::vector<T,_Alloc>& rhs ){
		return !(lhs == rhs);
	}

	template< typename T, typename _Alloc >
	bool operator<( const ft::vector<T,_Alloc>& lhs, const ft::vector<T,_Alloc>& rhs ){
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template< typename T, typename _Alloc >
	bool operator<=( const ft::vector<T,_Alloc>& lhs, const ft::vector<T,_Alloc>& rhs ){
		return !(ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}

	template< typename T, typename _Alloc >
	bool operator>( const ft::vector<T,_Alloc>& lhs, const ft::vector<T,_Alloc>& rhs ){
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}

	template< typename T, typename _Alloc >
	bool operator>=( const ft::vector<T,_Alloc>& lhs, const ft::vector<T,_Alloc>& rhs ){
		return !(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
}

namespace std
{
	/*		std::swap specialization		*/
	template< class T, class Alloc >
	void swap( ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs ){
		lhs.swap(rhs);
	}
}
#endif
