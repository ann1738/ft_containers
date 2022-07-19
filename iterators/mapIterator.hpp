/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 08:09:13 by ann               #+#    #+#             */
/*   Updated: 2022/07/19 15:54:56 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef mapITERATOR_HPP
# define mapITERATOR_HPP

#include <memory>
#include "iterator.hpp"
#include "../additional.hpp"
// #include "../map.hpp"

namespace ft{
	// template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > class const_mapIterator;
	template <	class Key,												// map::key_type
        		class T,												// map::mapped_type
				class Compare,							// map::key_compare
				class Alloc	// map::allocator_type
			 >class map;
	
	/*		ft::map iterator				*/
	template <	class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class mapIterator
	{
	public:
		typedef	pair<const Key, T>						value_type;
		typedef	Key										key_type;
		typedef	T										mapped_type;
		typedef	Compare									key_compare;
		typedef typename ft::map<Key, T, Compare, Alloc>::difference_type		difference_type;
		// typedef typename ft::map<Key, T, Compare, Alloc>::value_type			value_type;
		// typedef typename ft::map<Key, T, Compare, Alloc>::pointer				pointer;    
		typedef typename Alloc::pointer			pointer;
    	typedef typename Alloc::const_pointer		const_pointer;
		// typedef ft::map<Key, T, Compare, Alloc>::pointer									pointer;
		// typedef ft::map<Key, T, Compare, Alloc>::const_pointer									const_pointer;
		// typedef node&					reference;
		// typedef const node&				const_reference;
		typedef typename ft::map<Key, T, Compare, Alloc>::reference			reference;
		typedef typename ft::map<Key, T, Compare, Alloc>::const_reference		const_reference;
		typedef typename ft::bidirectional_iterator_tag		iterator_category;

		mapIterator(void) : it_start(0) {}
		mapIterator(const pointer temp) : it_start(temp) {}
		mapIterator(mapIterator const & iter) : it_start(iter.it_start) {}
		mapIterator & operator=(mapIterator const & iter) {if (this != &iter) this->it_start = iter.it_start; return *(this);}
		~mapIterator() {}

		operator	mapIterator<const Key, const T, Compare, Alloc>() const{
			return mapIterator<const Key, const T, Compare, Alloc>(it_start);
		}

		/*YOU HAVE TO IMPLEMENT '->' also !!!*/

		reference	operator*(void){
			return (this->it_start->_info);
		}

		/*idk how to do this*/
		value_type *	operator->(void){
			return &(this->it_start->_info);
		}

		mapIterator operator++(void){
			this->it_start = getNextMaximum(this->it_start);
			// std::cout << "getNextMaximum -> " << this->it_start->_info.first << std::endl;
			return (*this);
		}

		mapIterator operator++(int){
			mapIterator temp(this->it_start);
			
			this->it_start = getNextMaximum(this->it_start);
			return (temp);
		}

		mapIterator operator--(void){
			// if (!this->it_start) this->it_start = getM
			this->it_start = getNextMinimum(this->it_start);
			return (*this);
		}

		mapIterator operator--(int){
			mapIterator temp(this->it_start);
			/*add a line to make it bidirectional*/
			this->it_start = getNextMinimum(this->it_start);
			return (temp);
		}

		mapIterator		operator+(difference_type n) const{
			mapIterator temp(*this);
			for (difference_type i = 0; i < n; ++i) /*i dont know if i have to static cast smth*/
				temp = getNextMaximum(temp.it_start);
			return (temp);
		}
		mapIterator &	operator+=(difference_type n){
			for (difference_type i = 0; i < n; ++i) 
				this->it_start = getNextMaximum(this->it_start);
			return *(this);
		}

		mapIterator		operator-(difference_type n) const
		{
			mapIterator temp(*this);
			for (difference_type i = 0; i < n; ++i)
				temp.it_start = getNextMinimum(temp.it_start);
			return (temp);
		}

		// difference_type operator-(const mapIterator & rhs) const{
			
		// }

		mapIterator &	operator-=(difference_type n) 
		{
			for (difference_type i = 0; i < n; ++i)
				this->it_start = getNextMinimum(this->it_start);
			return *(this);
		}
		// reference	operator[](key_type n) {
		// 	mapIterator temp(it_start-> 	(););
		// 	difference_type count = 0
		// 	for (; rhs.it_start != temp.it_start; ++count)
		// 		temp = getNextMinimum(temp);
		// 	return (this->it_start[n]);
		// }

		bool operator==(const mapIterator & rhs) const{return this->it_start == rhs.it_start;}
		bool operator!=(const mapIterator & rhs) const{return this->it_start != rhs.it_start;}
		bool operator>(const mapIterator & rhs) const{return this->it_start > rhs.it_start;}
		bool operator>=(const mapIterator & rhs) const{return this->it_start >= rhs.it_start;}
		bool operator<(const mapIterator & rhs) const{return this->it_start < rhs.it_start;}
		bool operator<=(const mapIterator & rhs) const{return this->it_start <= rhs.it_start;}
		
		// template <typename TI>
		// bool operator==(const const_mapIterator<TI> & rhs){return this->it_start == rhs.it_start;}
		// template <typename TI>
		// bool operator!=(const const_mapIterator<TI> & rhs){return this->it_start != rhs.it_start;}
		// template <typename TI>
		// bool operator>(const const_mapIterator<TI> & rhs){return this->it_start > rhs.it_start;}
		// template <typename TI>
		// bool operator>=(const const_mapIterator<TI> & rhs){return this->it_start >= rhs.it_start;}
		// template <typename TI>
		// bool operator<(const const_mapIterator<TI> & rhs){return this->it_start < rhs.it_start;}
		// template <typename TI>
		// bool operator<=(const const_mapIterator<TI> & rhs){return this->it_start <= rhs.it_start;}

	private:
		pointer	it_start;
		
		mapIterator	base(void) {return *(this);}

		pointer	getSubMinimum(pointer nod) const{	pointer tmp = nod; for (; tmp->_left; tmp = tmp->_left) {}; return tmp; }

		pointer	getSubMaximum(pointer nod) const{	pointer tmp = nod; for (; tmp->_right; tmp = tmp->_right) {}; return tmp; }

		pointer	getNextMaximum(pointer nod) const{
			if (!nod) return NULL;
	
			if (nod->_right)
				return (getSubMinimum(nod->_right));
			/*knowing that nod is a leaf*/

			while (nod->_parent && !amILeft(nod))
				nod = nod->_parent;
			// if (!nod->_parent)
			// 	return getSubMinimum(nod);
			return nod->_parent;				
		}

		pointer	getNextMinimum(pointer nod) const{
			if (!nod) return NULL;
	
			if (nod->_left)
				return getSubMaximum(nod->_left);
			/*knowing that nod is a leaf*/

			while (nod->_parent && amILeft(nod))
				nod = nod->_parent;
			// if (!nod->_parent)
			// 	return getSubMaximum(nod);
			return nod->_parent;				
		}

		bool	amILeft(pointer _nod) const{return _nod == _nod->_parent->_left;}

	};

	template  <	class Key, class T, class Compare, class Alloc >
	mapIterator<Key, T, Compare, Alloc> operator+(typename mapIterator<Key, T, Compare, Alloc>::difference_type n, const mapIterator<Key, T, Compare, Alloc>& it){
		return mapIterator<Key, T, Compare, Alloc>(it + n);
	}
	
	/*		const map iterator		*/
	// template <typename T>
	// class const_mapIterator
	// {
	// 	const_mapIterator	base(void) {return *(this);}
	// public:
	// 	typedef typename ft::map<T>::difference_type		difference_type;
	// 	typedef typename ft::map<T>::value_type			value_type;
	// 	typedef typename ft::map<T>::pointer				pointer;
	// 	typedef typename ft::map<T>::const_pointer		const_pointer;
	// 	typedef typename ft::map<T>::reference			reference;
	// 	typedef typename ft::map<T>::const_reference		const_reference;
	// 	typedef typename ft::random_access_iterator_tag		iterator_category;

	// 	const_mapIterator(void) : it_start(0) {}
	// 	const_mapIterator(pointer temp) : it_start(temp) {}
	// 	const_mapIterator(const_mapIterator const & iter) : it_start(iter.it_start) {}
	// 	const_mapIterator & operator=(const_mapIterator const & iter) {if (this != &iter) this->it_start = iter.it_start; return *(this);}
	// 	~const_mapIterator() {}

	// 	/*YOU HAVE TO IMPLEMENT '->' also !!!*/

	// 	const_reference	operator*(void) const{
	// 		return *(this->it_start);
	// 	}

	// 	const_pointer	operator->(void) const{
	// 		return (this->it_start);
	// 	}

	// 	const_mapIterator operator++(void){
	// 		++this->it_start;
	// 		return (*this);
	// 	}

	// 	const_mapIterator operator++(int){
	// 		const_mapIterator temp;
	// 		temp.it_start = this->it_start++;
	// 		return (temp);
	// 	}

	// 	const_mapIterator operator--(void){
	// 		--this->it_start;
	// 		return (*this);
	// 	}

	// 	const_mapIterator operator--(int){
	// 		const_mapIterator temp;
	// 		temp.it_start = this->it_start++;
	// 		return (temp);
	// 	}

	// 	const_mapIterator	operator+(difference_type n)
	// 	{
	// 		const_mapIterator temp(*this);
	// 		temp = this->it_start + n;
	// 		return (temp);
	// 	}
	// 	const_mapIterator &	operator+=(difference_type n)
	// 	{
	// 		this->it_start += n;
	// 		return *(this);
	// 	}

	// 	const_mapIterator	operator-(difference_type n)
	// 	{
	// 		const_mapIterator temp(*this);
	// 		temp = this->it_start - n;
	// 		return (temp);
	// 	}

	// 	typename const_mapIterator::difference_type operator-(const const_mapIterator & rhs){
	// 		return this->it_start - rhs.it_start;
	// 	}

	// 	const_mapIterator &	operator-=(difference_type n) 
	// 	{
	// 		this->it_start -= n;
	// 		return *(this);
	// 	}
	// 	const reference	operator[](difference_type n) const {return (this->it_start[n]);}

	// 	template <typename TI>
	// 	bool operator==(const mapIterator<TI> & rhs){return this->it_start == rhs.it_start;}
	// 	template <typename TI>
	// 	bool operator!=(const mapIterator<TI> & rhs){return this->it_start != rhs.it_start;}
	// 	template <typename TI>
	// 	bool operator>(const mapIterator<TI> & rhs){return this->it_start > rhs.it_start;}
	// 	template <typename TI>
	// 	bool operator>=(const mapIterator<TI> & rhs){return this->it_start >= rhs.it_start;}
	// 	template <typename TI>
	// 	bool operator<(const mapIterator<TI> & rhs){return this->it_start < rhs.it_start;}
	// 	template <typename TI>
	// 	bool operator<=(const mapIterator<TI> & rhs){return this->it_start <= rhs.it_start;}

	// 	bool operator==(const const_mapIterator & rhs){return this->it_start == rhs.it_start;}
	// 	bool operator!=(const const_mapIterator & rhs){return this->it_start != rhs.it_start;}
	// 	bool operator>(const const_mapIterator & rhs){return this->it_start > rhs.it_start;}
	// 	bool operator>=(const const_mapIterator & rhs){return this->it_start >= rhs.it_start;}
	// 	bool operator<(const const_mapIterator & rhs){return this->it_start < rhs.it_start;}
	// 	bool operator<=(const const_mapIterator & rhs){return this->it_start <= rhs.it_start;}

	// private:
	// 	pointer	it_start;
	// };

	// template <typename T>
	// const_mapIterator<T> operator+(typename mapIterator<T>::difference_type n, const const_mapIterator<T>& it){
	// 	return const_mapIterator<T>(it + n);
	// }
}

#endif