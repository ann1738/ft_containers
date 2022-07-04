/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:50:42 by ann               #+#    #+#             */
/*   Updated: 2022/07/04 17:40:55 by anasr            ###   ########.fr       */
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

		typedef	pair<const Key, T>													value_type;
		typedef	Key																	key_type;
		typedef	T																	mapped_type;
		typedef	Compare																key_compare;
		typedef	typename Alloc::template rebind<node>::other						allocator_type;
		typedef	value_type &														reference;
		typedef	const value_type &													const_reference;
    	typedef node *																pointer;
    	typedef const pointer														const_pointer;
		typedef	mapIterator<key_type, mapped_type, key_compare, allocator_type>		iterator;
		// typedef	const const_mapIterator					const_iterator;
		typedef	ft::reverse_iterator<iterator>										reverse_iterator;
		// typedef	ft::reverse_iterator<const_iterator>	reverse_iterator;
		typedef	std::ptrdiff_t							difference_type;
		typedef	size_t									size_type;

		// /*	value_compare class (CONTINUE THIS PLS!!)	*/
		// template <class Key, class T, class Compare, class Alloc>
		// class value_compare : public std::binary_function<value_type, value_type, bool>{
		// public:
		// 	bool	operator()(const value_type & a, const value_type & b) const{
		// 		return _compObj(a.first, b.first);
		// 	}
		// protected:
		// 	Compare	_compObj;
		// 	value_compare (Compare c) : _compObj(c);
		// };

	private:
		pointer			_root;
		size_type		_size;
		key_compare		_myComp;
		allocator_type	_myAlloc;
		struct node{
			/*maybe this is considered a normal class and thus i can't implement here or maybe that's not true*/
			value_type	_info;
			
			pointer		_parent;
			pointer		_left;
			pointer		_right;

			size_type	_height;
			
			node(value_type info = value_type(), pointer left = 0, pointer right = 0)
				: _info(info), _left(left), _right(right), _height(1) {}
			node(const node & rhs)
				: _info(rhs._info), _left(rhs._left), _right(rhs._right), _height(rhs._height){}
			node& operator=(const node & rhs){
				if (this != &rhs){_info = rhs._info; _left = rhs._left; _right = rhs._right; _height = rhs._height;}
				return *this;
			}
			~node(){}
		};

		pointer	init_node(const key_type & n, const mapped_type & m = mapped_type()){
			pointer tmp = _myAlloc.allocate(1);
			_myAlloc.construct(tmp, node(ft::make_pair< const key_type, mapped_type>(n, m)));
			return tmp;
		}

		void	del_node(pointer deleteMe){ _myAlloc.destroy(deleteMe); _myAlloc.deallocate(deleteMe, 1); }

		bool	amILeft(pointer _nod) {return _nod == _nod->_parent->_left;}

		pointer	getMinimum(){ if (empty()) return NULL; pointer tmp = _root; for (; tmp->_left; tmp = tmp->_left) {}; return tmp; }

		pointer	getMaximum(){ if (empty()) return NULL; pointer tmp = _root; for (; tmp->_right; tmp = tmp->_right) {};	return tmp; }

		pointer	getSubMinimum(pointer nod){ pointer tmp = nod; for (; tmp->_left; tmp = tmp->_left) {}; return tmp; }

		pointer	getSubMaximum(pointer nod){ pointer tmp = nod; for (; tmp->_right; tmp = tmp->_right) {}; return tmp; }

		pointer	getNextMaximum(pointer nod){
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

		pointer	getNextMinimum(pointer nod){
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

		/*	BST ALGORITHMS	*/

		/*	finds the node with the corresponding key if it exists.. if the key exists it returns a pointer to it	*/
		/*	otherwise, it returns NULL	*/
		pointer	bst_find(const key_type & findMe){
			pointer tmp = _root;
			while (tmp != NULL && !(!_myComp(tmp->_info.first, findMe) && !_myComp(findMe, tmp->_info.first)))
			{
				if (_myComp(findMe, tmp->_info.first))
					tmp = tmp->_left;
				else
					tmp = tmp->_right;
			}
			return tmp;
		}
		
		/*	doesn't check if key is already there	*/
		pointer	bst_insert(const value_type & val){
			/*checker*/
			// pointer check = bst_find(val.first);
			// if (check) return pointer; /*checks if it exists*/
			/*creates the node*/
			pointer newNode = init_node(val.first, val.second);
			pointer tmp = _root, saveTmp = 0;
			while (tmp != NULL)
			{
				saveTmp = tmp;
				if (_myComp(val.first, tmp->_info.first))
					tmp = tmp->_left;
				else
					tmp = tmp->_right;
			}
			newNode->_parent = saveTmp;
			if (!saveTmp)
				_root = newNode;
			else if (_myComp(val.first, saveTmp->_info.first))
				saveTmp->_left = newNode;
			else
				saveTmp->_right = newNode;
			++_size;
			return newNode;
		}

		/*	two things need to be changed: the parent's child pointer and the child's parent pointer*/
		void	replaceNodePos(pointer toBeReplaced, pointer replacement){
			/*	changing the parent's (parent of toBeReplaced) child pointer to point at replacement*/
			if (!toBeReplaced->_parent)
				_root = replacement;
			else if (amILeft(toBeReplaced))
				toBeReplaced->_parent->_left = replacement;
			else
				toBeReplaced->_parent->_right = replacement;
			
			/*	changing the child's (child of toBeReplaced) parent pointer to point at the parent of toBeReplaced*/
			if (replacement)
				replacement->_parent = toBeReplaced->_parent;
		}
		/*WHAT IF DELETEME IS ROOT*/
		pointer	bst_delete(pointer deleteMe){
			if (!deleteMe) return NULL; /*checks if it exists*/
			pointer save = deleteMe->_parent;
	
			if (!deleteMe->_left && !deleteMe->_right)
				save = deleteMe->_parent;
			else if (!deleteMe->_left) /* case 1: no child	OR	case 2: one right child */
			{
				save = deleteMe->_right;
				replaceNodePos(deleteMe, deleteMe->_right);
			}
			else if (!deleteMe->_right) /* case 2: one left child */
			{
				save = deleteMe->_left;
				replaceNodePos(deleteMe, deleteMe->_left);
			}
			else /* case 3: two children */
			{
				pointer successor = getSubMinimum(deleteMe->_right);
				save = successor->_parent;
				if (successor->_parent != deleteMe) /*checking whether the successor is a direct child of deleteMe*/
				{
					replaceNodePos(successor, successor->_right); /* the right subtree of successor replaces the position of successor (to preserve that subtree)*/
					successor->_right = deleteMe->_right; /*linking the successor to the right subtree of deleteMe*/
					deleteMe->_right->_parent = successor;
				}
				replaceNodePos(deleteMe, successor); /*successor replacing the position of deleteMe*/
				successor->_left = deleteMe->_left; /*linking the successor to the left subtree of deleteMe*/
				deleteMe->_left->_parent = successor;
			}
			std::cout << "deleteMe = " << deleteMe->_info.first << std::endl;
			del_node(deleteMe);
			--_size;
			return save;
		}

		/*	rotation algorithms	*/
		void		rotate_left(pointer x){
			// std::cout << "\e[35mrotate left " << x->_info.first << "\e[0m" << std::endl;
			pointer y = x->_right;
			x->_right = y->_left;
			if (x->_right)
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

			x->_height = 1 + max(getHeight(x->_left), getHeight(x->_right));
			y->_height = 1 + max(getHeight(y->_left), getHeight(y->_right));
		}

		void	rotate_right(pointer x){
			// std::cout << "\e[35mrotate right " << x->_info.first << "\e[0m" << std::endl;
			pointer y = x->_left;
			x->_left = y->_right;
			if (y->_right)
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

			x->_height = 1 + max(getHeight(x->_left), getHeight(x->_right));
			y->_height = 1 + max(getHeight(y->_left), getHeight(y->_right));
		}
	public:
		size_type	pubGetHeight(const key_type & k){
			pointer tmp = bst_find(k);
			if (!tmp) return 0;
			return (tmp->_height);				
		}
	private:
		pointer	findRootOfNewNode(const key_type & k){
			pointer tmp = _root;
			while (tmp != NULL)
			{
				if (_myComp(k, tmp->_info.first))
					tmp = tmp->_left;
				else
					tmp = tmp->_right;
			}
			return tmp->_parent;
		}

		size_type	max(size_type a, size_type b) {return a > b ? a : b;}
		
		int			getBalance(pointer iAmANode){
			if (!iAmANode)
				return 0;
			return (getHeight(iAmANode->_left) - getHeight(iAmANode->_right));
		}

		size_type	getHeight(pointer _node){
			if (!_node) return 0;
			return _node->_height;
		}

		/*	testing function	*/
		void	verifyAvl(pointer leaf){
			pointer tmp = leaf;
			while (tmp)
			{
				assert(getBalance(tmp) >= -1 && getBalance(tmp) <= 1);
				tmp = tmp->_parent;
			}
		}

		/*	AVL ALGORITHMS	*/
		pointer	avl_insert(const value_type & val){
			/*check if exists!!*/
			// std::cout << "" << std::endl;
			pointer		newNode = bst_insert(val);
			pointer		tmp = newNode->_parent; //initialized as the parent of the newNode
			key_type	key = newNode->_info.first;
			int			balanceFactor;
			while (tmp != NULL)
			{
				/*update height of parent*/
				tmp->_height = 1 + max(getHeight(tmp->_left), getHeight(tmp->_right));
				// std::cout << tmp->_height << std::endl;
				
				/*get balance factor*/
				balanceFactor = getBalance(tmp);

				/*check if balanced*/
				if (balanceFactor >= -1 && balanceFactor <= 1) {tmp = tmp->_parent; continue;}
				
				/*cases where tree is not balanced*/
				if (balanceFactor < -1 && _myComp(key, tmp->_right->_info.first)) /*R L*/
				{
					rotate_right(tmp->_right);
					rotate_left(tmp);
				}
				else if (balanceFactor < -1 && _myComp(tmp->_right->_info.first, key)) /*R R*/
					rotate_left(tmp);
				else if (balanceFactor > 1 && _myComp(key, tmp->_left->_info.first)) /*L L*/
					rotate_right(tmp);
				else if (balanceFactor > 1 && _myComp(tmp->_left->_info.first, key)) /*L R*/
				{
					rotate_left(tmp->_left);
					rotate_right(tmp);
				}
				tmp = tmp->_parent;
			}
			// verifyAvl(newNode);
			return newNode;
		}

		void	avl_delete(pointer deleteMe){
			pointer tmp = bst_delete(deleteMe);
			if (!tmp) return ;
			int			balanceFactor;
			std::cout << "the parent is node with key = " << tmp->_info.first << std::endl;
			while (tmp != NULL)
			{
				/*update height of parent*/
				tmp->_height = 1 + max(getHeight(tmp->_left), getHeight(tmp->_right));
				
				/*get balance factor*/
				balanceFactor = getBalance(tmp);

				/*check if balanced*/
				if (balanceFactor >= -1 && balanceFactor <= 1) {tmp = tmp->_parent; continue;}
				
				/*cases where tree is not balanced*/
				if (balanceFactor < -1 && getBalance(tmp->_right) <= 0) /*R R*/
					rotate_left(tmp);
				else if (balanceFactor < -1) /*R L*/
				{
					rotate_right(tmp->_right);
					rotate_left(tmp);
				}
				else if (balanceFactor > 1 && getBalance(tmp->_left) >= 0) /*L L*/
					rotate_right(tmp);
				else if (balanceFactor > 1) /*L R*/
				{
					rotate_left(tmp->_left);
					rotate_right(tmp);
				}
				tmp = tmp->_parent;
			}
		}
	public:
		/*			Modifiers			*/
		/*TESTED*/
		void erase (iterator position){
			avl_delete(bst_find(position->first));
		}

		/*TESTED*/
		size_type erase (const key_type& k){
			pointer tmp = bst_find(k);
			if (!tmp) return 0;
			avl_delete(tmp);
			return 1;
		}

		/*TESTED*/
		void erase (iterator first, iterator last){
			iterator	tmp(first);
			
			while (first != last)
			{
				tmp = first++;
				avl_delete(bst_find(tmp->first));
			}
		}
		
		/*TESTED*/
		ft::pair<iterator,bool> insert (const value_type& val)
		{
			pointer check = bst_find(val.first);
			if (check) return ft::make_pair<iterator, bool>(iterator(check), false); /*checks if it exists*/

			check = avl_insert(val); /*reusing check*/
			return ft::make_pair<iterator, bool>(iterator(check), true);
		}

		iterator insert (iterator position, const value_type& val)
		{
			static_cast<void>(position);
			pointer check = bst_find(val.first);
			if (check) return iterator(check); /*checks if it exists*/

			check = avl_insert(val); /*reusing check*/
			return iterator(check);
		}
		
		template <class InputIterator>
 		void insert (InputIterator first, InputIterator last,
			typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator >::type* = 0){
			pointer	check;
			while (first != last)
			{
				check = bst_find((*first).first);
				if (check) continue; 
				avl_insert(*first);
				++first;
			}
		}

		iterator find (const key_type& k){
			return (iterator(bst_find(k)));
		}

		// const_iterator find (const key_type& k) const{
		// 	return (const_iterator(bst_find(k));
		// }

		/*TESTED*/
		void clear(){
			pointer tmp;
			// pointer save[size()];
			pointer save = getMinimum();
			size_type i;
			for (i = 0; save; ++i)
			{
				tmp = save;
				save = getNextMaximum(save);
				del_node(tmp);
			}
		}

		/* Not working */
		size_type count (const key_type& k) const{
			if (!bst_find(k)) return 0;
			return 1;
			// return (bst_find(k) == NULL ? 0 : 1);
		}
		
		mapped_type& operator[] (const key_type& k){
			pointer tmp = bst_find(k);
			if (tmp) /*if already there*/
				return (tmp->_info.second);
			tmp = avl_insert(ft::make_pair<key_type, mapped_type>(k, mapped_type()));
			return tmp->_info.second;		
		}

		/*		Observers		*/
		key_compare key_comp() const {return _myComp;}
		
		// const value_compare value_comp() const {return value_compare(_myComp);}
		
		allocator_type get_allocator() const {return _myAlloc;}

		
		/*	*/
		/**********************************************************************************************************************************/

		/*			Constructors		*/
		explicit map (const key_compare& comp = key_compare(),
    				  const allocator_type& alloc = allocator_type())
						: _root(0), _size(0), _myComp(comp), _myAlloc(alloc){}

		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator >::type* = 0,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
				: _root(0), _size(0), _myComp(comp), _myAlloc(alloc){
			insert(first, last);
		}
		// map (const map& x);
		
		/*			Destructors			*/
		~map(){
			clear();
		}

     	mapped_type& at (const key_type& k){
			pointer tmp = bst_find(k);
			if (tmp) return tmp->_info.second;
			throw std::out_of_range("map::at:  key not found");
		}
		
		const mapped_type& at (const key_type& k) const{
			pointer tmp = bst_find(k);
			if (tmp) return tmp->_info.second;
			throw std::out_of_range("map::at:  key not found");
		}

		/*			Iterators			*/
		iterator begin(){
			return (iterator(getMinimum()));
		}
		// const_iterator begin() const{
		// 	return (const_iterator(getMinimum()));
		// }

		iterator end(){
			return (iterator(NULL));
		}
		// const_iterator end() const{
		// 	return (const_iterator(getMaximum()));
		// }

		/*			Capacity			*/
		bool empty() const{
			return !_root;
		}

		size_type size() const{
			return _size;
		}
		
		size_type max_size() const{
			return _myAlloc.max_size();
		}
	};
}

/*	!!!!! this is not allowed !!!!	*/
		// void	draw(pointer tmp){
		// 	if (tmp != NULL)
		// 	{
		// 		std::string color = tmp->_color == RED ? "\e[31m" : "\e[33m";
		// 		std::cout << "\t\t\t\t" << color << tmp->_info.first << "\e[0m\n";
		// 		if (tmp->_left)
		// 		{
		// 			if (tmp->_left->_color == RED)
		// 				std::cout << "\t\t\t\e[31m" << color << tmp->_left->_info.first << "\e[0m";
		// 			else
		// 	std::cout << "heyeye\n";
		// 				std::cout << "\t\t\t\e[33m" << color << tmp->_left->_info.first << "\e[0m";
		// 		}
		// 		if (tmp->_right)
		// 		{
		// 			if (tmp->_right->_color == RED)
		// 				std::cout << "\t\t\t\e[31m" << color << tmp->_right->_info.first << "\e[0m\n";
		// 			else
		// 				std::cout << "\t\t\t\e[33m" << color << tmp->_right->_info.first << "\e[0m\n";
		// 		}
		// 		draw(tmp->_left->_left);
		// 		if (tmp->_right)
		// 			draw(tmp->_right->_right);
		// 	}
		// }

		// void	draw_every(){draw(_root);}

		// pointer		getRoot(){return _root;}

#endif