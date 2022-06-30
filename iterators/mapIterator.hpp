/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 08:09:13 by ann               #+#    #+#             */
/*   Updated: 2022/06/30 15:54:36 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef mapITERATOR_HPP
# define mapITERATOR_HPP

#include <memory>
#include "iterator.hpp"
#include "../map.hpp"

namespace ft{
	// template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > class const_mapIterator;

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
		typedef typename ft::map<Key, T, Compare, Alloc>::pointer				pointer;
		// typedef node*					pointer;
		// typedef const node*				const_pointer;
		// typedef node&					reference;
		// typedef const node&				const_reference;
		typedef typename ft::map<Key, T, Compare, Alloc>::reference			reference;
		typedef typename ft::map<Key, T, Compare, Alloc>::const_reference		const_reference;
		typedef typename ft::bidirectional_iterator_tag		iterator_category;

		mapIterator(void) : it_start(0) {}
		mapIterator(pointer temp) : it_start(temp) {}
		mapIterator(mapIterator const & iter) : it_start(iter.it_start) {}
		mapIterator & operator=(mapIterator const & iter) {if (this != &iter) this->it_start = iter.it_start; return *(this);}
		~mapIterator() {}

		/*YOU HAVE TO IMPLEMENT '->' also !!!*/

		reference	operator*(void){
			return (this->it_start->_info);
		}

		pointer	operator->(void){
			return &(this->it_start->_info);
		}

		mapIterator operator++(void){
			this->it_start = getNextMaximum(this->it_start);
			return (*this);
		}
		mapIterator operator++(int){
			mapIterator temp(this->it_start);
			this->it_start = getNextMaximum(this->it_start);
			return (temp);
		}

		mapIterator operator--(void){
			this->it_start = getNextMinimum(this->it_start);
			return (*this);
		}

		mapIterator operator--(int){
			mapIterator temp(this->it_start);
			this->it_start = getNextMinimum(this->it_start);
			return (temp);
		}

		mapIterator		operator+(difference_type n) const{
			mapIterator temp(*this);
			for (difference_type i = 0; i < n; ++i) /*i dont know if i have to static cast smth*/
				temp = getNextMaximum(temp);
			return (temp);
		}
		mapIterator &	operator+=(difference_type n){
			for (difference_type i = 0; i < n; ++i) 
				this->it_start = getNextMaximum(this->it_start);
			return *(this);
		}

		mapIterator		operator-(difference_type n)
		{
			mapIterator temp(*this);
			for (difference_type i = 0; i < n; ++i)
				temp = getNextMinimum(temp);
			return (temp);
		}

		difference_type operator-(const mapIterator & rhs){
			mapIterator temp(*this);
			difference_type count = 0;
			for (; rhs.it_start != temp.it_start; ++count)
				temp = getNextMinimum(temp);
			return count;
		}

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

		bool operator==(const mapIterator & rhs){return this->it_start == rhs.it_start;}
		bool operator!=(const mapIterator & rhs){return this->it_start != rhs.it_start;}
		bool operator>(const mapIterator & rhs){return this->it_start > rhs.it_start;}
		bool operator>=(const mapIterator & rhs){return this->it_start >= rhs.it_start;}
		bool operator<(const mapIterator & rhs){return this->it_start < rhs.it_start;}
		bool operator<=(const mapIterator & rhs){return this->it_start <= rhs.it_start;}
		
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

		pointer	getSubMinimum(pointer nod){
			pointer tmp = nod;
			
			for (; tmp->_left; tmp = tmp->_left);
			return tmp;
		}

		pointer	getSubMaximum(pointer nod){
			pointer tmp = nod;
			
			for (; tmp->_right; tmp = tmp->_right);
			return tmp;
		}

		pointer	getNextMaximum(pointer nod){
			if (!nod) return NULL;
	
			if (nod->_right && !nod->_left)
				return nod->_right;
			else if (nod->_right)
			{
				if (nod->_right == getSubMinimum(nod->_right))
					return nod->_right;
				else
					return getSubMinimum(nod->_right);
			}
			
			/*knowing that nod is a leaf*/

			while (!amILeft(nod))
			{
				if (nod->_parent) /* maximum node */
					return NULL;
				nod = nod->_parent;
			}
			return nod->_parent;				
		}

		pointer	getNextMinimum(pointer nod){
			if (!nod) return NULL;
	
			if (nod->_left && !nod->_right)
				return nod->_left;
			else if (nod->_left)
			{
				if (nod->_left == getSubMaximum(nod->_left))
					return nod->_left;
				else
					return getSubMaximum(nod->_left);
			}

			/*knowing that nod is a leaf*/

			while (amILeft(nod))
			{
				if (nod->_parent) /* maximum node */
					return NULL;
				nod = nod->_parent;
			}
			return nod->_parent;				
		}

		bool	amILeft(pointer _nod) {return _nod == _nod->_parent->_left;}

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