/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:32:41 by ann               #+#    #+#             */
/*   Updated: 2022/07/25 12:13:16 by ann              ###   ########.fr       */
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
		typedef typename ft::set<T, Compare, Alloc>::difference_type		difference_type;
		typedef typename Alloc::pointer										pointer;
    	typedef typename Alloc::const_pointer								const_pointer;
		typedef typename ft::set<T, Compare, Alloc>::reference				reference;
		typedef typename ft::set<T, Compare, Alloc>::const_reference		const_reference;
		typedef typename ft::bidirectional_iterator_tag						iterator_category;

	// private:
		setIterator(const pointer temp) : it_start(temp) {_myComp = key_compare();}
	public:
		setIterator(void) : it_start(0) {_myComp = key_compare();}
		setIterator(setIterator const & iter) : it_start(iter.it_start) {}//account for _myComp
		setIterator & operator=(setIterator const & iter) {if (this != &iter) this->it_start = iter.it_start; return *(this);}
		~setIterator() {}


		const reference	operator*(void){
			return (this->it_start->_info);
		}

		/*idk how to do this*/
		value_type *	operator->(void){
			return &(this->it_start->_info);
		}

		setIterator operator++(void){
			this->it_start = getNextMaximum(this->it_start);
			return (*this);
		}

		setIterator operator++(int){
			setIterator temp(this->it_start);
			
			this->it_start = getNextMaximum(this->it_start);
			return (temp);
		}

		setIterator operator--(void){
			// if (!this->it_start->_info == value_type()) return (this->it_start());
			// if (!this->it_start) this->it_start = getM
			this->it_start = getNextMinimum(this->it_start);
			return (*this);
		}

		setIterator operator--(int){
			setIterator temp(this->it_start);
			/*add a line to make it bidirectional*/
			this->it_start = getNextMinimum(this->it_start);
			return (temp);
		}

		/* how do i make this const? */
		bool operator==( setIterator & rhs) {return !_myComp(this->it_start->_info, rhs->_info) && !_myComp(rhs.it_start->_info, this->it_start->_info);}
		bool operator!=( setIterator & rhs) {return !(*this == rhs);}

	private:
		pointer	it_start;
		key_compare _myComp;
		
		const setIterator &	base(void) const{return *(this);}

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
}
#endif