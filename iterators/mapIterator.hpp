/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 08:09:13 by ann               #+#    #+#             */
/*   Updated: 2022/07/25 15:23:33 by ann              ###   ########.fr       */
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

	template <	class Key, class T, class Compare, class Alloc >
	class constMapIterator;
	
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

	// private:
		mapIterator(const pointer temp, const pointer small, const pointer large) : it_start(temp), _smallest_node(small), _largest_node(large), _myComp(key_compare()) {}
	public:	
		mapIterator(void) : it_start(0), _smallest_node(0), _largest_node(0), _myComp(key_compare()){}
		mapIterator(mapIterator const & iter) : it_start(iter.it_start), _smallest_node(iter._smallest_node), _largest_node(iter._largest_node), _myComp(key_compare()) {}//account for _myComp
		mapIterator & operator=(mapIterator const & iter) {if (this != &iter) this->it_start = iter.it_start; return *(this);}
		~mapIterator() {}

		operator mapIterator<Key, const T, Compare, Alloc>() const {
			return mapIterator<Key, const T, Compare, Alloc>(it_start, _smallest_node, _largest_node);
		}

		const pointer	base(void) const {return it_start;}
		// const pointer	base(void) const{return it_start;}

		reference	operator*(void){
			return (this->it_start->_info);
		}
		
		// /*am i allowed to have a const version */
		// const value_type *	operator->(void) const{
		// 	return &(this->it_start->_info);
		// }

		/*idk how to do this*/
		value_type *	operator->(void) const{
			return &(this->it_start->_info);
		}

		mapIterator operator++(void){
			if (it_start == NULL) it_start = _smallest_node;
			else this->it_start = getNextMaximum(this->it_start);
			// std::cout << "getNextMaximum -> " << this->it_start->_info.first << std::endl;
			return (*this);
		}

		mapIterator operator++(int){
			mapIterator temp(this->it_start, _smallest_node, _largest_node);
			if (it_start == NULL) it_start = _smallest_node;
			else this->it_start = getNextMaximum(this->it_start);
			return (temp);
		}

		mapIterator operator--(void){
			if (it_start == NULL) it_start = _largest_node;
			else this->it_start = getNextMinimum(this->it_start);
			return (*this);
		}

		mapIterator operator--(int){
			mapIterator temp(this->it_start, _smallest_node, _largest_node);
			/*add a line to make it bidirectional*/
			if (it_start == NULL) it_start = _largest_node;
			else this->it_start = getNextMinimum(this->it_start);
			return (temp);
		}


		bool operator==( mapIterator & rhs) {
			if (base() && rhs.base()) return !_myComp(base()->_info.first, rhs.base()->_info.first) && !_myComp(rhs.base()->_info.first, base()->_info.first);
			if (!base() && !rhs.base()) return true;
			return false;
			}
		bool operator!=( mapIterator & rhs) {return !(*this == rhs);}
		
		/* how do i make this const? */
		// bool operator==(  mapIterator & rhs) {return !_myComp(this->it_start->_info.first, rhs.it_start->_info.first) && !_myComp(rhs.it_start->_info.first, this->it_start->_info.first);}
		// bool operator!=( mapIterator & rhs) {return !(*this == rhs);}

	private:
		pointer	it_start;
		pointer	_smallest_node;
		pointer	_largest_node;
		key_compare _myComp;
		

		pointer	getSubMinimum(pointer nod) const{	pointer tmp = nod; for (; tmp->_left; tmp = tmp->_left) {}; return tmp; }

		pointer	getSubMaximum(pointer nod) const{	pointer tmp = nod; for (; tmp->_right; tmp = tmp->_right) {}; return tmp; }

		pointer	getNextMaximum(pointer nod) const{
			if (!nod) return NULL;
			if (nod->_right)
				return (getSubMinimum(nod->_right));
			while (nod->_parent && !amILeft(nod))
				nod = nod->_parent;
			return nod->_parent;				
		}

		pointer	getNextMinimum(pointer nod) const{
			if (!nod) return NULL;
			if (nod->_left)
				return getSubMaximum(nod->_left);
			while (nod->_parent && amILeft(nod))
				nod = nod->_parent;
			return nod->_parent;				
		}

		bool	amILeft(pointer _nod) const{return _nod == _nod->_parent->_left;}

	};
	
	// template <typename Iter1, typename Iter2>
	// bool operator==(const Iter1 & lhs, const Iter2 & rhs) {return lhs.base()->_info.first == rhs.base()->info.first;}
	// template <typename Iter1, typename Iter2>
	// bool operator!=(const Iter1 & lhs, const Iter2 & rhs) {return !(lhs == rhs);}
	
	/* ignorant attempt at making random access iterator instead of bidirectional because i forgot to check the reference */

		// mapIterator		operator+(difference_type n) const{
		// 	mapIterator temp(*this);
		// 	for (difference_type i = 0; i < n; ++i) /*i dont know if i have to static cast smth*/
		// 		temp = getNextMaximum(temp.it_start);
		// 	return (temp);
		// }
		// mapIterator &	operator+=(difference_type n){
		// 	for (difference_type i = 0; i < n; ++i) 
		// 		this->it_start = getNextMaximum(this->it_start);
		// 	return *(this);
		// }

		// mapIterator		operator-(difference_type n) const
		// {
		// 	mapIterator temp(*this);
		// 	for (difference_type i = 0; i < n; ++i)
		// 		temp.it_start = getNextMinimum(temp.it_start);
		// 	return (temp);
		// }

		// // difference_type operator-(const mapIterator & rhs) const{
			
		// // }

		// mapIterator &	operator-=(difference_type n) 
		// {
		// 	for (difference_type i = 0; i < n; ++i)
		// 		this->it_start = getNextMinimum(this->it_start);
		// 	return *(this);
		// }

	/**************************************************************************************/



	/*		const map iterator		*/

	// template <	class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	// class constMapIterator
	// {
	// public:
	// 	typedef	pair<const Key, T>						value_type;
	// 	typedef	Key										key_type;
	// 	typedef	T										mapped_type;
	// 	typedef	Compare									key_compare;
	// 	typedef typename ft::map<Key, T, Compare, Alloc>::difference_type		difference_type;
	// 	// typedef typename ft::map<Key, T, Compare, Alloc>::value_type			value_type;
	// 	// typedef typename ft::map<Key, T, Compare, Alloc>::pointer				pointer;    
	// 	typedef typename Alloc::pointer			pointer;
    // 	typedef typename Alloc::const_pointer		const_pointer;
	// 	// typedef ft::map<Key, T, Compare, Alloc>::pointer									pointer;
	// 	// typedef ft::map<Key, T, Compare, Alloc>::const_pointer									const_pointer;
	// 	// typedef node&					reference;
	// 	// typedef const node&				const_reference;
	// 	typedef typename ft::map<Key, T, Compare, Alloc>::reference			reference;
	// 	typedef typename ft::map<Key, T, Compare, Alloc>::const_reference		const_reference;
	// 	typedef typename ft::bidirectional_iterator_tag		iterator_category;


	// // private:
	// 	constMapIterator(const pointer temp, const pointer small, const pointer large) : it_start(temp), _smallest_node(small), _largest_node(large), _myComp(key_compare()) {}
	// public:	
	// 	constMapIterator(void) : it_start(0), _smallest_node(0), _largest_node(0), _myComp(key_compare()){}
	// 	constMapIterator(constMapIterator const & iter) : it_start(iter.it_start), _smallest_node(iter._smallest_node), _largest_node(iter._largest_node), _myComp(key_compare()) {}//account for _myComp
	// 	constMapIterator & operator=(constMapIterator const & iter) {if (this != &iter) this->it_start = iter.it_start; _smallest_node = iter._smallest_node; _largest_node = iter._largest_node; return *(this);}
	// 	~constMapIterator() {}

	// 	const_reference	operator*(void) const{
	// 		return (this->it_start->_info);
	// 	}

	// 	/*idk how to do this*/
	// 	const value_type *	operator->(void) const{
	// 		return &(this->it_start->_info);
	// 	}

	// 	constMapIterator operator++(void){
	// 		this->it_start = getNextMaximum(this->it_start);
	// 		// std::cout << "getNextMaximum -> " << this->it_start->_info.first << std::endl;
	// 		return (*this);
	// 	}

	// 	constMapIterator operator++(int){
	// 		constMapIterator temp(this->it_start, _smallest_node, _largest_node);
			
	// 		this->it_start = getNextMaximum(this->it_start);
	// 		return (temp);
	// 	}

	// 	constMapIterator operator--(void){
	// 		this->it_start = getNextMinimum(this->it_start);
	// 		return (*this);
	// 	}

	// 	constMapIterator operator--(int){
	// 		constMapIterator temp(this->it_start, _smallest_node, _largest_node);
	// 		/*add a line to make it bidirectional*/
	// 		this->it_start = getNextMinimum(this->it_start);
	// 		return (temp);
	// 	}

	// 	bool operator==( const constMapIterator & rhs) {
	// 		if (base() && rhs.base()) return !_myComp(base()->_info.first, rhs.base()->_info.first) && !_myComp(rhs.base()->_info.first, base()->_info.first);
	// 		if (!base() && !rhs.base()) return true;
	// 		return false;
	// 		}
	// 	bool operator!=( const constMapIterator & rhs) {return !(*this == rhs);}
	// 	// bool operator==( constMapIterator & rhs) {return !_myComp(this->it_start->_info.first, rhs.it_start->_info.first) && !_myComp(rhs.it_start->_info.first, this->it_start->_info.first);}
	// 	// bool operator!=( constMapIterator & rhs) {return !(*this == rhs);}

	// 	const pointer	base(void) const {return it_start;}
	// private:
	// 	pointer	it_start;
	// 	pointer	_smallest_node;
	// 	pointer	_largest_node;
	// 	key_compare _myComp;
		

	// 	pointer	getSubMinimum(pointer nod) const{	pointer tmp = nod; for (; tmp->_left; tmp = tmp->_left) {}; return tmp; }

	// 	pointer	getSubMaximum(pointer nod) const{	pointer tmp = nod; for (; tmp->_right; tmp = tmp->_right) {}; return tmp; }

	// 	pointer	getNextMaximum(pointer nod) const{
	// 		if (!nod) return NULL;
	// 		if (nod->_right)
	// 			return (getSubMinimum(nod->_right));
	// 		while (nod->_parent && !amILeft(nod))
	// 			nod = nod->_parent;
	// 		return nod->_parent;				
	// 	}

	// 	pointer	getNextMinimum(pointer nod) const{
	// 		if (!nod) return NULL;
	// 		if (nod->_left)
	// 			return getSubMaximum(nod->_left);
	// 		while (nod->_parent && amILeft(nod))
	// 			nod = nod->_parent;
	// 		return nod->_parent;				
	// 	}

	// 	bool	amILeft(pointer _nod) const{return _nod == _nod->_parent->_left;}

	// };
}

#endif
