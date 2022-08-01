/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 08:09:13 by ann               #+#    #+#             */
/*   Updated: 2022/08/01 13:19:58 by anasr            ###   ########.fr       */
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




	template <	class key_n_map, class Compare , class Alloc >
	class mapIterator
	{
	public:
		typedef	key_n_map														value_type;
		typedef	Compare															key_compare;
		typedef typename Alloc::pointer											node_pointer;
		typedef value_type &													reference;
		typedef const value_type &												const_reference;
		typedef typename ft::bidirectional_iterator_tag							iterator_category;

			// public:
		typedef value_type *														pointer;
    	typedef const pointer														const_pointer;
		typedef	std::ptrdiff_t														difference_type;
		typedef	size_t																size_type;

	// private:
		mapIterator(const node_pointer temp, const node_pointer small, const node_pointer large)
			:	it_start(temp), _smallest_node(small), _largest_node(large), _myComp(key_compare()) {}
	public:	
		mapIterator(void)
			:	it_start(0), _smallest_node(0), _largest_node(0), _myComp(key_compare()) {}
		mapIterator(mapIterator const & iter)
			:	it_start(iter.it_start), _smallest_node(iter._smallest_node), _largest_node(iter._largest_node), _myComp(key_compare()) {}
		mapIterator & operator=(mapIterator const & iter){
			if (this != &iter)
			{
				it_start = iter.it_start;
				_smallest_node = iter._smallest_node;
				_largest_node = iter._largest_node;
				_myComp = iter._myComp;
		 	}
			return *this;
		}
		~mapIterator() {}

		/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
		operator mapIterator<const key_n_map, Compare, Alloc>() const {
			return mapIterator<const key_n_map, Compare, Alloc>(it_start, _smallest_node, _largest_node);
		}
		/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

		const node_pointer	base(void) const {return it_start;}

		reference	operator*(void) const{
			return (this->it_start->_info);
		}

		pointer  getValPtr() const
		{ return &it_start->_info; }

		// const_pointer  getValPtr() const
		// { return &it_start->_info; }

		pointer	operator->(void) const {
			return getValPtr();
			// return  &(this->it_start->_info);
		}

		mapIterator & operator++(void){
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

		mapIterator & operator--(void){
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

		bool	operator==(const mapIterator<const key_n_map, Compare, Alloc> & rhs){
			return base() == rhs.base();
		}

		bool	operator!=(const mapIterator<const key_n_map, Compare, Alloc> & rhs){
			return base() != rhs.base();
		}
	private:
		node_pointer	it_start;
		node_pointer	_smallest_node;
		node_pointer	_largest_node;
		key_compare		_myComp;

		node_pointer	getSubMinimum(node_pointer nod) const{	node_pointer tmp = nod; for (; tmp->_left; tmp = tmp->_left) {}; return tmp; }

		node_pointer	getSubMaximum(node_pointer nod) const{	node_pointer tmp = nod; for (; tmp->_right; tmp = tmp->_right) {}; return tmp; }

		node_pointer	getNextMaximum(node_pointer nod) const{
			if (!nod) return NULL;
			if (nod->_right)
				return (getSubMinimum(nod->_right));
			while (nod->_parent && !amILeft(nod))
				nod = nod->_parent;
			return nod->_parent;				
		}

		node_pointer	getNextMinimum(node_pointer nod) const{
			if (!nod) return NULL;
			if (nod->_left)
				return getSubMaximum(nod->_left);
			while (nod->_parent && amILeft(nod))
				nod = nod->_parent;
			return nod->_parent;				
		}

		bool	amILeft(node_pointer _nod) const{return _nod == _nod->_parent->_left;}
	};









	/*my trials with comparison operators*/

	// bool operator==( mapIterator & rhs) {
		// 	if (base() && rhs.base()) return !_myComp(base()->_info.first, rhs.base()->_info.first) && !_myComp(rhs.base()->_info.first, base()->_info.first);
		// 	if (!base() && !rhs.base()) return true;
		// 	return false;
		// 	}
		// bool operator!=( mapIterator & rhs) {return !(*this == rhs);}
		
		// !!! TRY THE BELOW !!!

		// template <typename Iter1, typename Iter2>
		// friend bool operator==(const Iter1 & lhs, Iter2 & rhs){
		// 	return lhs.base() == rhs.base();
		// }

		// template <typename Iter1, typename Iter2>
		// friend bool operator!=(const Iter1 & lhs, Iter2 & rhs){
		// 	return lhs.base() != rhs.base();
		// }


		// template < class key_n_mapI, class CompareI, class AllocI >
		// bool operator==(const mapIterator<key_n_mapI, CompareI, AllocI> & lhs, mapIterator<key_n_mapI, CompareI, AllocI> & rhs)
		// { return lhs.base() == rhs.base(); }

		// template < class key_n_mapI, class CompareI, class AllocI >
		// bool operator!=(const mapIterator<key_n_mapI, CompareI, AllocI> & lhs, mapIterator<key_n_mapI, CompareI, AllocI> & rhs)
		// { return lhs.base() != rhs.base(); }

		// friend bool
		// operator==(const mapIterator& lhs, mapIterator & rhs)
		// { return lhs.base() == rhs.base(); }

		// friend bool
		// operator!=(const mapIterator& lhs, mapIterator & rhs)
		// { return lhs.base() != rhs.base(); }

	/*******************************************************************/





	/*!!!!!!!!!!! Original Code !!!!!!!!!!!!!*/
	// template <	class Key, class T, class Compare, class Alloc >
	// class constMapIterator;
	
	// /*		ft::map iterator				*/
	// template <	class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	// class mapIterator
	// {
	// public:
	// 	typedef	pair<const Key, T>												value_type;
	// 	typedef	Key																key_type;
	// 	typedef	T																mapped_type;
	// 	typedef	Compare															key_compare;
	// 	typedef typename ft::map<Key, T, Compare, Alloc>::difference_type		difference_type;
	// 	typedef typename Alloc::pointer											node_pointer;
	// 	typedef value_type &													reference;
	// 	typedef const value_type &												const_reference;
	// 	typedef typename ft::bidirectional_iterator_tag							iterator_category;

	// 		// public:
	// 	typedef value_type *			pointer;
    // 	typedef const pointer		const_pointer;

	// // private:
	// 	mapIterator(const node_pointer temp, const node_pointer small, const node_pointer large) : it_start(temp), _smallest_node(small), _largest_node(large), _myComp(key_compare()) {}
	// public:	
	// 	mapIterator(void) : it_start(0), _smallest_node(0), _largest_node(0), _myComp(key_compare()){}
	// 	mapIterator(mapIterator const & iter) : it_start(iter.it_start), _smallest_node(iter._smallest_node), _largest_node(iter._largest_node), _myComp(key_compare()) {}//account for _myComp
	// 	mapIterator & operator=(mapIterator const & iter) {if (this != &iter) this->it_start = iter.it_start; return *(this);}
	// 	~mapIterator() {}

	// 	/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
	// 	operator mapIterator<const Key, T, Compare, Alloc>() const {
	// 		return constMapIterator<Key, T, Compare, Alloc>(it_start, _smallest_node, _largest_node);
	// 	}
	// 	/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

	// 	const node_pointer	base(void) const {return it_start;}

	// 	reference	operator*(void) const{
	// 		return (this->it_start->_info);
	// 	}


	// 	pointer  getValPtr() const
	// 	{ return &it_start->_info; }

	// 	// const_pointer  getValPtr() const
	// 	// { return &it_start->_info; }

	// 	pointer	operator->(void) const {
	// 		return getValPtr();
	// 		// return  &(this->it_start->_info);
	// 	}

	// 	mapIterator & operator++(void){
	// 		if (it_start == NULL) it_start = _smallest_node;
	// 		else this->it_start = getNextMaximum(this->it_start);
	// 		// std::cout << "getNextMaximum -> " << this->it_start->_info.first << std::endl;
	// 		return (*this);
	// 	}

	// 	mapIterator operator++(int){
	// 		mapIterator temp(this->it_start, _smallest_node, _largest_node);
	// 		if (it_start == NULL) it_start = _smallest_node;
	// 		else this->it_start = getNextMaximum(this->it_start);
	// 		return (temp);
	// 	}

	// 	mapIterator & operator--(void){
	// 		if (it_start == NULL) it_start = _largest_node;
	// 		else this->it_start = getNextMinimum(this->it_start);
	// 		return (*this);
	// 	}

	// 	mapIterator operator--(int){
	// 		mapIterator temp(this->it_start, _smallest_node, _largest_node);
	// 		/*add a line to make it bidirectional*/
	// 		if (it_start == NULL) it_start = _largest_node;
	// 		else this->it_start = getNextMinimum(this->it_start);
	// 		return (temp);
	// 	}

	// 	bool operator==( mapIterator & rhs) {
	// 		if (base() && rhs.base()) return !_myComp(base()->_info.first, rhs.base()->_info.first) && !_myComp(rhs.base()->_info.first, base()->_info.first);
	// 		if (!base() && !rhs.base()) return true;
	// 		return false;
	// 		}
	// 	bool operator!=( mapIterator & rhs) {return !(*this == rhs);}
		
	// 	// !!! TRY THE BELOW !!!

	// 	// friend bool
	// 	// operator==(const mapIterator& lhs, mapIterator & rhs)
	// 	// { return lhs.base() == rhs.base(); }

	// 	// friend bool
	// 	// operator!=(const mapIterator& lhs, mapIterator & rhs)
	// 	// { return lhs.base() != rhs.base(); }



	// 	// friend bool
	// 	// operator==(const mapIterator& lhs, constMapIterator & rhs)
	// 	// { return lhs.base() == rhs.base(); }

	// 	// friend bool
	// 	// operator!=(const mapIterator& lhs, constMapIterator & rhs)
	// 	// { return lhs.base() != rhs.base(); }
		


	// private:
	// 	node_pointer	it_start;
	// 	node_pointer	_smallest_node;
	// 	node_pointer	_largest_node;
	// 	key_compare _myComp;
		

	// 	node_pointer	getSubMinimum(node_pointer nod) const{	node_pointer tmp = nod; for (; tmp->_left; tmp = tmp->_left) {}; return tmp; }

	// 	node_pointer	getSubMaximum(node_pointer nod) const{	node_pointer tmp = nod; for (; tmp->_right; tmp = tmp->_right) {}; return tmp; }

	// 	node_pointer	getNextMaximum(node_pointer nod) const{
	// 		if (!nod) return NULL;
	// 		if (nod->_right)
	// 			return (getSubMinimum(nod->_right));
	// 		while (nod->_parent && !amILeft(nod))
	// 			nod = nod->_parent;
	// 		return nod->_parent;				
	// 	}

	// 	node_pointer	getNextMinimum(node_pointer nod) const{
	// 		if (!nod) return NULL;
	// 		if (nod->_left)
	// 			return getSubMaximum(nod->_left);
	// 		while (nod->_parent && amILeft(nod))
	// 			nod = nod->_parent;
	// 		return nod->_parent;				
	// 	}

	// 	bool	amILeft(node_pointer _nod) const{return _nod == _nod->_parent->_left;}
	// };
	




































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

	// 	template <	class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	// class constMapIterator
	// {
	// public:
	// 	typedef	pair<const Key, T>												value_type;
	// 	typedef	Key																key_type;
	// 	typedef	T																mapped_type;
	// 	typedef	Compare															key_compare;
	// 	typedef typename ft::map<Key, T, Compare, Alloc>::difference_type		difference_type;
	// 	typedef typename Alloc::pointer											node_pointer;
	// 	typedef value_type &													reference;
	// 	typedef const value_type &												const_reference;
	// 	typedef typename ft::bidirectional_iterator_tag							iterator_category;

	// 		// public:
	// 	typedef const value_type *			pointer;
    // 	// typedef const pointer		const_pointer;

	// // private:
	// 	constMapIterator(const node_pointer temp, const node_pointer small, const node_pointer large) : it_start(temp), _smallest_node(small), _largest_node(large), _myComp(key_compare()) {}
	// public:	
	// 	constMapIterator(void) : it_start(0), _smallest_node(0), _largest_node(0), _myComp(key_compare()){}
	// 	constMapIterator(constMapIterator const & iter) : it_start(iter.it_start), _smallest_node(iter._smallest_node), _largest_node(iter._largest_node), _myComp(key_compare()) {}//account for _myComp
	// 	constMapIterator & operator=(constMapIterator const & iter) {if (this != &iter) this->it_start = iter.it_start; return *(this);}
	// 	~constMapIterator() {}

	// 	const node_pointer	base(void) const {return it_start;}
	// 	// const pointer	base(void) const{return it_start;}

	// 	const_reference	operator*(void) const{
	// 		return (this->it_start->_info);
	// 	}

    // //   pointer  getValPtr()
    // //   { return &it_start->_info; }

    //   pointer  getValPtr() const
    //   { return const_cast<pointer>(&it_start->_info); }

	// 	pointer	operator->(void) const {
	// 		return getValPtr();
	// 		// return  &(this->it_start->_info);
	// 	}

	// 	constMapIterator & operator++(void){
	// 		if (it_start == NULL) it_start = _smallest_node;
	// 		else this->it_start = getNextMaximum(this->it_start);
	// 		// std::cout << "getNextMaximum -> " << this->it_start->_info.first << std::endl;
	// 		return (*this);
	// 	}

	// 	constMapIterator operator++(int){
	// 		constMapIterator temp(this->it_start, _smallest_node, _largest_node);
	// 		if (it_start == NULL) it_start = _smallest_node;
	// 		else this->it_start = getNextMaximum(this->it_start);
	// 		return (temp);
	// 	}

	// 	constMapIterator & operator--(void){
	// 		if (it_start == NULL) it_start = _largest_node;
	// 		else this->it_start = getNextMinimum(this->it_start);
	// 		return (*this);
	// 	}

	// 	constMapIterator operator--(int){
	// 		constMapIterator temp(this->it_start, _smallest_node, _largest_node);
	// 		/*add a line to make it bidirectional*/
	// 		if (it_start == NULL) it_start = _largest_node;
	// 		else this->it_start = getNextMinimum(this->it_start);
	// 		return (temp);
	// 	}


	// 	bool operator==( constMapIterator & rhs) {
	// 		if (base() && rhs.base()) return !_myComp(base()->_info.first, rhs.base()->_info.first) && !_myComp(rhs.base()->_info.first, base()->_info.first);
	// 		if (!base() && !rhs.base()) return true;
	// 		return false;
	// 		}
	// 	bool operator!=( constMapIterator & rhs) {return !(*this == rhs);}


	// private:
	// 	node_pointer	it_start;
	// 	node_pointer	_smallest_node;
	// 	node_pointer	_largest_node;
	// 	key_compare _myComp;
		

	// 	node_pointer	getSubMinimum(node_pointer nod) const{	node_pointer tmp = nod; for (; tmp->_left; tmp = tmp->_left) {}; return tmp; }

	// 	node_pointer	getSubMaximum(node_pointer nod) const{	node_pointer tmp = nod; for (; tmp->_right; tmp = tmp->_right) {}; return tmp; }

	// 	node_pointer	getNextMaximum(node_pointer nod) const{
	// 		if (!nod) return NULL;
	// 		if (nod->_right)
	// 			return (getSubMinimum(nod->_right));
	// 		while (nod->_parent && !amILeft(nod))
	// 			nod = nod->_parent;
	// 		return nod->_parent;				
	// 	}

	// 	node_pointer	getNextMinimum(node_pointer nod) const{
	// 		if (!nod) return NULL;
	// 		if (nod->_left)
	// 			return getSubMaximum(nod->_left);
	// 		while (nod->_parent && amILeft(nod))
	// 			nod = nod->_parent;
	// 		return nod->_parent;				
	// 	}

	// 	bool	amILeft(node_pointer _nod) const{return _nod == _nod->_parent->_left;}
	// };
}

#endif
