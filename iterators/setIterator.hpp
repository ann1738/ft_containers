/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:32:41 by ann               #+#    #+#             */
/*   Updated: 2022/09/01 18:24:32 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETITERATOR_HPP
#define SETITERATOR_HPP

#include <memory>
#include "iterator.hpp"
#include "../additional.hpp"

namespace ft{
	
	template < class T, class Compare, class Alloc > class set;
	
	/*		ft::set iterator				*/
	template <	class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class setIterator
	{
	public:
		typedef	T															value_type;
		typedef	T															key_type;
		typedef	Compare														key_compare;
		typedef	Compare														value_compare;
		typedef value_type &												reference;
		typedef const value_type &											const_reference;
		typedef typename Alloc::pointer										node_pointer;
		typedef value_type *												pointer;
    	typedef const pointer												const_pointer;
		typedef typename ft::set<T, Compare, Alloc>::difference_type		difference_type;
		typedef typename ft::set<T, Compare, Alloc>::size_type				size_type;
		typedef typename ft::bidirectional_iterator_tag						iterator_category;

		setIterator(void)
			:	it_start(0), _smallest_node(0), _largest_node(0), _myComp(key_compare()) {}
		setIterator(setIterator const & iter)
			:	it_start(iter.it_start), _smallest_node(iter._smallest_node), _largest_node(iter._largest_node), _myComp(key_compare()) {}
		setIterator(const node_pointer temp, const node_pointer small, const node_pointer large)
			:	it_start(temp), _smallest_node(small), _largest_node(large), _myComp(key_compare()) {}
		setIterator & operator=(setIterator const & iter){
			if (this != &iter)
			{
				it_start = iter.it_start;
				_smallest_node = iter._smallest_node;
				_largest_node = iter._largest_node;
				_myComp = iter._myComp;
		 	}
			return *this;
		}
		~setIterator() {}

		operator setIterator<const T, Compare, Alloc>() const {
			return setIterator<const T, Compare, Alloc>(it_start, _smallest_node, _largest_node);
		}
		
		const node_pointer	base(void) const {return it_start;}

		const_reference	operator*(void) const{
			return (this->it_start->_info);
		}

		pointer	operator->(void) const {
			return getValPtr();
		}

		setIterator & operator++(void){
			if (it_start == NULL) it_start = _smallest_node;
			else this->it_start = getNextMaximum(this->it_start);
			return (*this);
		}

		setIterator operator++(int){
			setIterator temp(this->it_start, _smallest_node, _largest_node);
			if (it_start == NULL) it_start = _smallest_node;
			else this->it_start = getNextMaximum(this->it_start);
			return (temp);
		}

		setIterator & operator--(void){
			if (it_start == NULL) it_start = _largest_node;
			else this->it_start = getNextMinimum(this->it_start);
			return (*this);
		}

		setIterator operator--(int){
			setIterator temp(this->it_start, _smallest_node, _largest_node);
			if (it_start == NULL) it_start = _largest_node;
			else this->it_start = getNextMinimum(this->it_start);
			return (temp);
		}

		bool	operator==(const setIterator<const T, Compare, Alloc> & rhs){
			return base() == rhs.base();
		}

		bool	operator!=(const setIterator<const T, Compare, Alloc> & rhs){
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

		pointer  getValPtr() const{return &it_start->_info;}
	};
}
#endif