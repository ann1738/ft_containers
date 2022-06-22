/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:50:42 by ann               #+#    #+#             */
/*   Updated: 2022/06/22 18:30:03 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# define RED 0
# define BLACK 1

#include <memory>
#include <functional>
#include "additional.hpp"
#include "iterators/iterator.hpp"

namespace ft{
	template <	class Key,												// map::key_type
        		class T,												// map::mapped_type
				class Compare = std::less<Key>,							// map::key_compare
				class Alloc = std::allocator<ft::pair<const Key, T> >	// map::allocator_type
			 >
	class map{
		typedef	pair<const Key, T>						value_type;
		typedef	Key										key_type;
		typedef	T										mapped_type;
		typedef	Compare									key_compare;
		typedef	Alloc::rebind<node>::other				allocator_type;
		typedef	value_type &							reference;
		typedef	const value_type &						const_reference;
		typedef	node *										pointer;
		typedef	const node *								const_pointer;
		// typedef	Alloc::pointer							pointer;
		// typedef Alloc::const_pointer						const_pointer;
		// typedef	mapIterator								iterator;
		// typedef	const const_mapIterator					const_iterator;
		// typedef	ft::reverse_iterator<iterator>			reverse_iterator;
		// typedef	ft::reverse_iterator<const_iterator>	reverse_iterator;
		typedef	std::ptrdiff_t							difference_type;
		typedef	size_t									size_type;

	private:
		allocator_type	_myAlloc;
		key_compare		_myComp;
		pointer			_root = 0;
		size_type		_size = 0;
			
		struct node{
			/*maybe this is considered a normal class and thus i can't implement here or maybe that's not true*/
			value_type	_info;
			
			pointer		_parent;
			pointer		_left;
			pointer		_right;
			
			bool		_color;

			node(value_type nod = _nod(), pointer left = 0, pointer right = 0)
				: _nod(nod), _left(left), _right(right), _color(RED){}
			node(const node & rhs)
				: _nod(rhs.nod), _left(rhs.left), _right(rhs.right), _color(rhs._color){}
			node& operator=(const node & rhs){
				if (this != &rhs){_nod = rhs.nod; _left = rhs.left; _right = rhs.right; _color = rhs._color;}
				return *this;
			}
			~node(){}
		};
		
		pointer	init_node(){
			pointer = tmp = _myAlloc.allocate(1);
			_myAlloc.construct(tmp, node());
			return tmp;
		}

		void	del_node(pointer deleteMe){
			_myAlloc.destroy(deleteMe);
			_myAlloc.deallocate(deleteMe, 1);
		}

		void	recolor(pointer _nod) {nod->_color == RED ? _nod->color = BLACK : _nod->color = RED;};
		
		/*pointer can't be root*/
		bool	amILeft(pointer _nod) {return _nod == _nod->_parent->left;}
		
		pointer	getMinimum(){
			pointer tmp = _root;
			
			for (; tmp->_left; ++i)
				tmp = tmp->_left;
			return tmp;
		}

		pointer	getMaximum(){
			pointer tmp = _root;
			
			for (; tmp->_right; ++i)
				tmp = tmp->_right;
			return tmp;
		}
		
		/* returns the parent of the PosInTree */
		pointer	findPosInTree(pointer findMyPlace){
			pointer tmp = _root;

			while (1312)
			{
				if (!_myComp(findMyPlace->_info, tmp->_info) && !_myComp(tmp->_info, findMyPlace->_info))
					return NULL;
				if (_myComp(findMyPlace->_info, tmp->_info)
				{
					if (!tmp->_left)
						return tmp;
					tmp = tmp->_left;
				}
				else
				{
					if (!tmp->_right)
						return tmp;
					tmp = tmp->_right;
				}
			}
		}

		void	rotate_left(pointer x){
			pointer y = x->_right;
			x->_right = y->_left;
			x->_right->_parent = x;
			y->_parent = x->_parent;
			if (!x->_parent)
				_root = y;
			else if (amILeft(x))
				x->_parent->_left = y;
			else
				x->_parent->_right = y;
			y->_left = x;
			x->_parent = y;
		}

		void	rotate_right(pointer x){
			pointer y = x->_left;
			x->_left = y->_right;
			y->_right->_parent = x;
			y->_parent = x->_parent;			
			if (!x->_parent)
				_root = y;
			else if (amILeft(x))
				x->_parent->_left = y;
			else
				x->_parent->_right = y;
			y->_right = x;
			x->_parent = y;
		}

		void	rotate_n_recolor(pointer newNode){
			/* base condition */
			if (newNode == _root || newNode->_parent->_color == BLACK) return ;
			/**/
			pointer	aunt = amILeft(newNode) ? newNode->_left : aunt = newNode->_right;
			if (aunt || aunt->_color == BLACK)
			{
				if (!amILeft(newNode->_parent) && !amILeft(newNode)) /* R R */
				{
					recolor(newNode->_parent);
					recolor(newNode->_parent->_parent);

					rotate_left(newNode->_parent->_parent);
				}
				else if (amILeft(newNode->_parent) && amILeft(newNode) /* L L */
				{
					recolor(newNode->_parent);
					recolor(newNode->_parent->_parent);

					rotate_right(newNode->_parent->_parent);
				}
				else if (!amILeft(newNode->_parent) && amILeft(newNode) /* R L */
				{
					rotate_right(newNode->_parent);

					recolor(newNode->_parent);
					recolor(newNode->_parent->_parent);

					rotate_left(newNode->_parent->_parent);					
				}
				else// (amILeft(newNode->_parent) && !amILeft(newNode) /* L R */
				{
					rotate_left(newNode->_parent);

					recolor(newNode->_parent);
					recolor(newNode->_parent->_parent);

					rotate_right(newNode->_parent->_parent);	
				}	
			}
			else /* aunt is RED */
			{
				rnb_recoloring(newNode->_parent->_parent, aunt, newNode->_parent);
			}
		}
		rnb_recoloring(pointer gramma, pointer aunt, pointer parent){
			recolor(parent);
			recolor(aunt);
			if (gramma != _root)
				recolor(gramma);
			rotate_n_recolor(gramma);
		}
	public:
		/**********************************************************************************************************************************/
		/*			Modifiers			*/
		pair<iterator,bool> insert (const value_type& val)
		{
			if (!this->_root)
			{
				_root = init_node();
				recolor(_root);
				return ft::make_pair<iterator, bool>(iterator(_root), true);
			}
			
			/*	inserting the new node in the risht place in the tree (to keep order) */
			pointer	newNode;
			pointer	afterMe = findPosInTree(val);
			if (!afterMe)
				return void; /*change return value*/
			if (_myComp(afterMe->_info, val))
			{
				afterMe->_left = init_node();
				afterMe->_left->info = value;
				newNode = afterMe->_left;
			}
			else
			{
				afterMe->_right = init_node();
				afterMe->_right->info = value;
				newNode = afterMe->_right;
			}
			newNode->_parent = addMe;
			
			/* red black tree balancing */
			if (newNode->_parent->_color == BLACK ) return;
			recolor_n_rotate(newNode);
	
			
		}
		/*			Constructors		*/
		explicit map (const key_compare& comp = key_compare(),
    				  const allocator_type& alloc = allocator_type()){
			_myComp = comp;
			_myAlloc = alloc;
		}
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
		{
			_myComp = comp;
			_myAlloc = alloc;
			/*code for constructing appropriately*/
		}
		// map (const map& x);
		
		/*			Destructors			*/
		~map{
			/*deallocates it*/
		}

		/*			Capacity			*/
		bool empty() const{
			return _root;
		}

		size_type size() const{
			return _size;
		}
		
		size_type size() const{
			return _myAlloc.max_size();
		}

		
	};
}

#endif