/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:50:42 by ann               #+#    #+#             */
/*   Updated: 2022/06/30 15:56:58 by anasr            ###   ########.fr       */
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
	template <	class Key, class T, class Compare, class Alloc > class mapIterator;
	template <	class Key,												// map::key_type
        		class T,												// map::mapped_type
				class Compare = std::less<Key>,							// map::key_compare
				class Alloc = std::allocator<ft::pair<const Key, T> >	// map::allocator_type
			 >
	class map{
	struct node;
	
	public:

		typedef	pair<const Key, T>						value_type;
		typedef	Key										key_type;
		typedef	T										mapped_type;
		typedef	Compare									key_compare;
		typedef	typename Alloc::template rebind<node>::other				allocator_type;
		typedef	value_type &							reference;
		typedef	const value_type &						const_reference;
		typedef	node *										pointer;
		typedef	const node *								const_pointer;
		// typedef	Alloc::pointer							pointer;
		// typedef Alloc::const_pointer						const_pointer;
		typedef	mapIterator<key_type, mapped_type, key_compare, allocator_type>								iterator;
		// typedef	const const_mapIterator					const_iterator;
		typedef	ft::reverse_iterator<iterator>			reverse_iterator;
		// typedef	ft::reverse_iterator<const_iterator>	reverse_iterator;
		typedef	std::ptrdiff_t							difference_type;
		typedef	size_t									size_type;

	private:
		allocator_type	_myAlloc;
		key_compare		_myComp;
		pointer			_root;
		size_type		_size;
			
		struct node{
			/*maybe this is considered a normal class and thus i can't implement here or maybe that's not true*/
			value_type	_info;
			
			pointer		_parent;
			pointer		_left;
			pointer		_right;
			
			bool		_color;

			node(value_type info = value_type(), pointer left = 0, pointer right = 0)
				: _info(info), _left(left), _right(right), _color(RED){}
			node(const node & rhs)
				: _info(rhs._info), _left(rhs._left), _right(rhs._right), _color(rhs._color){}
			node& operator=(const node & rhs){
				if (this != &rhs){_info = rhs._info; _left = rhs._left; _right = rhs._right; _color = rhs._color;}
				return *this;
			}
			~node(){}
		};
		
		pointer	init_node(){
			pointer tmp = _myAlloc.allocate(1);
			_myAlloc.construct(tmp, node());
			return tmp;
		}
		pointer	init_node(key_type n){
			pointer tmp = _myAlloc.allocate(1);
			_myAlloc.construct(tmp, node(ft::make_pair<key_type, mapped_type>(n, 0)));
			return tmp;
		}

		void	del_node(pointer deleteMe){
			_myAlloc.destroy(deleteMe);
			_myAlloc.deallocate(deleteMe, 1);
		}

		void	recolor(pointer _nod) {_nod->_color == RED ? _nod->_color = BLACK : _nod->_color = RED;};
		
		/*pointer can't be root*/
		bool	amILeft(pointer _nod) {return _nod == _nod->_parent->_left;}
		
		pointer	getMinimum(){
			pointer tmp = _root;
			
			for (; tmp->_left; tmp = tmp->_left);
			return tmp;
		}

		pointer	getMaximum(){
			pointer tmp = _root;
			
			for (; tmp->_right; tmp = tmp->_right);
			return tmp;
		}

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
			
			if (nod == getMaximum())
				return NULL;
			/*knowing that nod is a leaf*/

			while (!amILeft(nod))
				nod = nod->_parent;
			return nod->_parent;				
		}
		
		/* returns the parent of the PosInTree */
		pointer	findPosInTree(const value_type & findMyPlace){
			pointer tmp = _root;

			while (1312)
			{
				if (!_myComp(findMyPlace.first, tmp->_info.first) && !_myComp(tmp->_info.first, findMyPlace.first))
					return NULL;
				if (_myComp(findMyPlace.first, tmp->_info.first))
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
				else if (amILeft(newNode->_parent) && amILeft(newNode)) /* L L */
				{
					recolor(newNode->_parent);
					recolor(newNode->_parent->_parent);

					rotate_right(newNode->_parent->_parent);
				}
				else if (!amILeft(newNode->_parent) && amILeft(newNode)) /* R L */
				{
					rotate_right(newNode->_parent);

					recolor(newNode->_parent);
					recolor(newNode->_parent->_parent);

					rotate_left(newNode->_parent->_parent);					
				}
				else// (amILeft(newNode->_parent) && !amILeft(newNode)) /* L R */
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
		void	rnb_recoloring(pointer gramma, pointer aunt, pointer parent){
			recolor(parent);
			recolor(aunt);
			if (gramma != _root)
				recolor(gramma);
			rotate_n_recolor(gramma);
		}

		/* I AM NOT SURE WHY I DONT FREE HERE */
		void	transplant(pointer u, pointer v){
			if (!u->_parent)
				_root = v;
			else if (amILeft(u))
				u->_parent->_left = v;
			else
				u->_parent->_right = v;
			if (!v)
				v->_parent = u->_parent;
		}

		/*	implement copy constructor and copy assignment before testing this	*/
		void	deleteNodeFromTree(pointer deleteMyExistance){
			pointer y = deleteMyExistance;
			bool saveColor = deleteMyExistance->_color;
			pointer x;
			if (!deleteMyExistance->_left)
			{
				x = deleteMyExistance->_right;
				transplant(deleteMyExistance, deleteMyExistance->_right);
			}
			else if (!deleteMyExistance->_right)
			{
				x = deleteMyExistance->_left;
				transplant(deleteMyExistance, deleteMyExistance->_left);
			}
			else
			{
				y = getSubMinimum(deleteMyExistance->_right);
				saveColor = y->_color;
				x = y->_right;
				if (y->_parent == deleteMyExistance) /* if y is a child of node to be deleted */
					x->_parent = y;
				else
				{
					transplant(y, y->_right);
					y->_right = deleteMyExistance->_right;
					y->_right->_parent = y;
				}
				transplant(deleteMyExistance, y);
				y->_left = deleteMyExistance->_left;
				y->_left->_parent = y;
				y->_color = deleteMyExistance->_color;
			}
			if (saveColor ==  BLACK)
				fixDelete(x);
			--_size;
		}

		void	fixDelete(pointer x){
			pointer w;
			while (x != _root && x->_color == BLACK)
			{
				if (amILeft(x))
				{
					w = x->_parent->_right; //aunt of x
					if (w->_color == RED) //case 1
					{
						w->_color = BLACK;
						w->_parent->_color = RED;
						rotate_left(x->_parent);
						w = x->_parent->_right; //update aunt of x
					}
					if ((!w->_left || w->_left->_color == BLACK) && (!w->_right || w->_right->_color == BLACK)) //case 2
					{
						w->_color = RED;
						x = x->_parent;
					}
					else //case 3 or 4
					{
						if (w->_right->_color == BLACK) //case 3
						{
							w->_left->_color = BLACK;
							w->_color = RED;
							rotate_right(w);
							w = x->_parent->_right;
						}
						//case 4
						w->_color = x->_right->_color;
						w->_parent->_color = BLACK;
						w->_right->_color = RED;
						rotate_left(x->_parent);
						x = _root;
					}
				}
				else
				{
					
				}
			}
			x->_color = BLACK;
		}
	public:
		// void erase (iterator position)
		// {
			
		// }

		/*	!!!!! this is not allowed !!!!	*/
		// pointer		getRoot(){return _root;}
		/*	*/
		/**********************************************************************************************************************************/
		/*			Modifiers			*/
		// ft::pair<iterator,bool> insert (const value_type& val)
		void insert (const value_type& val)
		{
			if (!this->_root)
			{
				_root = init_node();
				_root->_info.second = val.second;
				recolor(_root);
				return ;
				// return ft::make_pair<iterator, bool>(iterator(_root), true);
			}
			
			/*	inserting the new node in the risht place in the tree (to keep order) */
			pointer	newNode;
			pointer	afterMe = findPosInTree(val);
			if (!afterMe)
				return ;
				// return ft::make_pair<iterator,bool>(NULL, false); /*change return val*/
			if (_myComp(afterMe->_info.first, val.first))
			{
				afterMe->_left = init_node(val.first);
				afterMe->_left->_info.second = val.second;
				newNode = afterMe->_left;
			}
			else
			{
				afterMe->_right = init_node(val.first);
				afterMe->_right->_info.second = val.second;
				newNode = afterMe->_right;
			}
			newNode->_parent = afterMe;
			
			/* red black tree balancing */
			// if (newNode->_parent->_color == BLACK ) return ft::make_pair<iterator, bool>(iterator(newNode), true);
			if (newNode->_parent->_color == BLACK ) return ;
			rotate_n_recolor(newNode);
			++_size;
		}

		// mapped_type& operator[](const key_type& k){
			
		// }

		/*			Constructors		*/
		explicit map (const key_compare& comp = key_compare(),
    				  const allocator_type& alloc = allocator_type()){
			_root = 0;
			_size = 0;
			_myComp = comp;
			_myAlloc = alloc;
		}
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
		{
			_root = 0;
			_size = 0;
			_myComp = comp;
			_myAlloc = alloc;

			static_cast<void>(first);
			static_cast<void>(last);
			/*code for constructing appropriately*/
		}
		// map (const map& x);
		
		/*			Destructors			*/
		~map(){
			/*deallocates it*/
		}

		/*			Iterators			*/
		iterator begin(){
			return (iterator(_root));
		}
		// const_iterator begin() const{
		// 	return (const_iterator(_root));
		// }

		iterator end(){
			return (iterator(getMaximum()));
		}
		// const_iterator end() const{
		// 	return (const_iterator(getMaximum()));
		// }

		/*			Capacity			*/
		bool empty() const{
			return _root;
		}

		size_type size() const{
			return _size;
		}
		
		size_type max_size() const{
			return _myAlloc.max_size();
		}
	};
}

#endif