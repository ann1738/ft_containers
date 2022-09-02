/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 08:09:13 by ann               #+#    #+#             */
/*   Updated: 2022/09/02 11:35:36 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP

#include <memory>
#include "iterator.hpp"
#include "../additional.hpp"

namespace ft{
	
	template < class Key, class T, class Compare, class Alloc > class map;

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
		typedef value_type *													pointer;
    	typedef const pointer													const_pointer;
		typedef	std::ptrdiff_t													difference_type;
		typedef	size_t															size_type;

		mapIterator(void)
			:	it_start(0), _smallest_node(0), _largest_node(0), _myComp(key_compare()) {}
		mapIterator(mapIterator const & iter)
			:	it_start(iter.it_start), _smallest_node(iter._smallest_node), _largest_node(iter._largest_node), _myComp(key_compare()) {}
		mapIterator(const node_pointer temp, const node_pointer small, const node_pointer large)
			:	it_start(temp), _smallest_node(small), _largest_node(large), _myComp(key_compare()) {}
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

		operator mapIterator<const key_n_map, Compare, Alloc>() const {
			return mapIterator<const key_n_map, Compare, Alloc>(it_start, _smallest_node, _largest_node);
		}

		const node_pointer	base(void) const {return it_start;}

		reference	operator*(void) const{
			return (this->it_start->_info);
		}

		pointer	operator->(void) const {
			return getValPtr();
		}

		mapIterator & operator++(void){
			if (it_start == NULL) it_start = _smallest_node;
			else this->it_start = getNextMaximum(this->it_start);
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

		pointer  getValPtr() const{return &it_start->_info;}
	};

}

#endif
