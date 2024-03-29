/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:50:42 by ann               #+#    #+#             */
/*   Updated: 2022/08/30 15:25:47 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <memory>
#include <functional>
#include "additional.hpp"
#include "iterators/iterator.hpp"
#include "iterators/mapIterator.hpp"

// #include <cassert>

namespace ft{
	template <	class Key,												// map::key_type
        		class T,												// map::mapped_type
				class Compare = std::less<Key>,							// map::key_compare
				class Alloc = std::allocator<ft::pair<const Key, T> >	// map::allocator_type
			 >
	class map{
	struct node;
	typedef	typename Alloc::template rebind<node>::other							node_allocator;

	public:
		typedef	pair<const Key, T>													value_type;
		typedef	Key																	key_type;
		typedef	T																	mapped_type;
		typedef	Compare																key_compare;
		typedef	Alloc																allocator_type;
		typedef	value_type &														reference;
		typedef	const value_type &													const_reference;
    	typedef node *																pointer;
    	typedef const pointer														const_pointer;
		typedef	mapIterator<value_type, key_compare, node_allocator>				iterator;
		typedef	mapIterator<const value_type, key_compare, node_allocator>			const_iterator;
		typedef	ft::reverse_iterator<iterator>										reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>								const_reverse_iterator;
		typedef	std::ptrdiff_t														difference_type;
		typedef	size_t																size_type;

		/*	value_compare class	*/
		class value_compare : public std::binary_function<value_type, value_type, bool>{
			friend class map;
		public:
			bool	operator()(const value_type & a, const value_type & b) const{
				return _compObj(a.first, b.first);
			}
		protected:
			Compare	_compObj;
			value_compare (Compare c) : _compObj(c) {};
		};

	private:
		pointer			_root;
		size_type		_size;
		key_compare		_myComp;
		allocator_type	_myAlloc;
		node_allocator	_myNodeAlloc;

		struct node{
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
			pointer tmp = _myNodeAlloc.allocate(1);
			_myNodeAlloc.construct(tmp, node(ft::make_pair< const key_type, mapped_type>(n, m)));
			return tmp;
		}

		void	del_node(pointer deleteMe){ _myNodeAlloc.destroy(deleteMe); _myNodeAlloc.deallocate(deleteMe, 1); }

		bool	amILeft(pointer _nod) {return _nod == _nod->_parent->_left;}

		pointer	getMinimum() const{ if (empty()) return NULL; pointer tmp = _root; for (; tmp->_left; tmp = tmp->_left) {}; return tmp; }

		pointer	getMaximum() const{ if (empty()) return NULL; pointer tmp = _root; for (; tmp->_right; tmp = tmp->_right) {}; return tmp; }

		pointer	getSubMinimum(pointer nod){ pointer tmp = nod; for (; tmp->_left; tmp = tmp->_left) {}; return tmp; }

		pointer	getSubMaximum(pointer nod){ pointer tmp = nod; for (; tmp->_right; tmp = tmp->_right) {}; return tmp; }

		pointer	getNextMaximum(pointer nod){
			if (!nod) return NULL;
	
			if (nod->_right)
				return (getSubMinimum(nod->_right));

			/*knowing that nod is a leaf*/
			while (nod->_parent && !amILeft(nod))
				nod = nod->_parent;
			return nod->_parent;				
		}

		pointer	getNextMinimum(pointer nod){
			if (!nod) return NULL;
	
			if (nod->_left)
				return getSubMaximum(nod->_left);

			/*knowing that nod is a leaf*/
			while (nod->_parent && amILeft(nod))
				nod = nod->_parent;
			return nod->_parent;				
		}

		/*	BST ALGORITHMS	*/

		/*	finds the node with the corresponding key if it exists.. if the key exists it returns a pointer to it	*/
		/*	otherwise, it returns NULL	*/
		pointer	bst_find(const key_type & findMe) const{
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

		/*	two things are changed: the parent's child pointer and the child's parent pointer*/
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
		
		pointer	bst_delete(pointer deleteMe){
			if (!deleteMe) return NULL; /*checks if it exists*/
			pointer save = deleteMe->_parent;
	
			if (!deleteMe->_left && !deleteMe->_right)
			{
				save = deleteMe->_parent;
				replaceNodePos(deleteMe, deleteMe->_right);
			}
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
				save = successor;
				if (successor->_parent != deleteMe) /*checking whether the successor is a direct child of deleteMe*/
				{
					save = successor->_parent;
					replaceNodePos(successor, successor->_right); /* the right subtree of successor replaces the position of successor (to preserve that subtree)*/
					successor->_right = deleteMe->_right; /*linking the successor to the right subtree of deleteMe*/
					deleteMe->_right->_parent = successor;
				}
				replaceNodePos(deleteMe, successor); /*successor replacing the position of deleteMe*/
				successor->_left = deleteMe->_left; /*linking the successor to the left subtree of deleteMe*/
				deleteMe->_left->_parent = successor;
			}
			del_node(deleteMe);
			--_size;
			return save;
		}

		/*	rotation algorithms	*/
		void	rotate_left(pointer x){
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

	// public:
	// 	size_type	pubGetHeight(const key_type & k){
	// 		pointer tmp = bst_find(k);
	// 		if (!tmp) return 0;
	// 		return (tmp->_height);				
	// 	}
	// private:

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

		/*	testing function (NOTE: make sure to include <cassert>)	*/
		void	verifyAvl(pointer leaf){
			pointer tmp = leaf;
			while (tmp)
			{
				assert(getBalance(tmp) >= -1 && getBalance(tmp) <= 1);
				tmp = tmp->_parent;
			}
		}

		/*	AVL ALGORITHMS	*/
		
		/*assuming val does not exist*/
		pointer	avl_insert(const value_type & val){
			pointer		newNode = bst_insert(val);
			pointer		tmp = newNode->_parent; //initialized as the parent of the newNode
			key_type	key = newNode->_info.first;
			int			balanceFactor;
			while (tmp != NULL)
			{
				/*update height of parent*/
				tmp->_height = 1 + max(getHeight(tmp->_left), getHeight(tmp->_right));
				
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
			// pointer test = tmp;
			int			balanceFactor;
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
			// verifyAvl(test);
		}
	public:
		/*			Constructors		*/
		explicit map(const key_compare& comp = key_compare(),
    				  const allocator_type& alloc = allocator_type())
						: _root(0), _size(0), _myComp(comp), _myAlloc(alloc){_myNodeAlloc = node_allocator();}

		template <class InputIterator>
		map(InputIterator first, InputIterator last,
			typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator >::type* = 0,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
				: _root(0), _size(0), _myComp(comp), _myAlloc(alloc){
			_myNodeAlloc = node_allocator();
			insert(first, last);
		}
		
		map(const map& x)
			: _root(0), _size(0), _myComp(x._myComp), _myAlloc(x._myAlloc){
			_myNodeAlloc = node_allocator();
			const_iterator first = x.begin(), last = x.end();
			insert(first, last);
		}
		
		/*			Destructors			*/
		~map(){
			clear();
		}
		
		/*			Copy assignment		*/
		map& operator=(const map& x){
			if (this != &x)
			{
				clear();
				_root = 0;
				_size = 0;
				_myComp = x._myComp;
				_myAlloc = x._myAlloc;
				_myNodeAlloc = x._myNodeAlloc;
				insert(x.begin(), x.end());
			}
			return *this;
		}

		/*			Capacity			*/
		bool			empty() const{
			return !_root;
		}

		size_type		size() const{
			return _size;
		}
		
		size_type		max_size() const{
			return _myNodeAlloc.max_size();
		}

		/*			Element access		*/
		mapped_type&	operator[](const key_type& k){
			return ((this->insert(ft::make_pair(k, mapped_type()))).first)->second;
		}

		/*			Modifiers			*/
		ft::pair<iterator,bool>	insert(const value_type& val)
		{
			pointer check = bst_find(val.first);
			if (check) return ft::make_pair<iterator, bool>(iterator(check, getMinimum(), getMaximum()), false); /*checks if it exists*/

			check = avl_insert(val); /*reusing check*/
			return ft::make_pair<iterator, bool>(iterator(check, getMinimum(), getMaximum()), true);
		}

		iterator insert(iterator position, const value_type& val)
		{
			static_cast<void>(position);
			pointer check = bst_find(val.first);
			if (check) return iterator(check, getMinimum(), getMaximum()); /*checks if it exists*/

			check = avl_insert(val);
			return iterator(check, getMinimum(), getMaximum());
		}
		
		template <class InputIterator>
 		void insert(InputIterator first, InputIterator last,
			typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator >::type* = 0){
			pointer	check;
			while (first != last)
			{
				check = bst_find((*first).first);
				if (check) {++first; continue;} 
				avl_insert(*first);
				++first;
			}
		}
		
		void erase(iterator position){
			avl_delete(bst_find(position->first));
		}

		size_type erase(const key_type& k){
			pointer tmp = bst_find(k);
			if (!tmp) return 0;
			avl_delete(tmp);
			return 1;
		}

		void erase(iterator first, iterator last){
			iterator	tmp(first);
			
			while (first != last)
			{
				tmp = first++;
				avl_delete(bst_find(tmp->first));
			}
		}

		void swap(map& x){
			ft::myswap(_root, x._root);
			ft::myswap(_size, x._size);
			ft::myswap(_myComp, x._myComp);
			ft::myswap(_myAlloc, x._myAlloc);
			ft::myswap(_myNodeAlloc, x._myNodeAlloc);
		}

		void clear(){
			erase(begin(), end());
		}

		/*		Observers		*/
		key_compare key_comp() const{return _myComp;}
		
		const value_compare value_comp() const{return value_compare(_myComp);}

		/*			Iterators			*/
		iterator begin(){
			return iterator(getMinimum(), getMinimum(), getMaximum());
		}

		const_iterator begin() const{
			return const_iterator(getMinimum(), getMinimum(), getMaximum());
		}

		iterator end(){
			return (iterator(NULL, getMinimum(), getMaximum()));
		}

		const_iterator end() const{
			return (const_iterator(NULL, getMinimum(), getMaximum()));
		}

		reverse_iterator rbegin(){
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin() const{
			return const_reverse_iterator(end());
		}

		reverse_iterator rend(){
			return reverse_iterator(begin());
		}
		
		const_reverse_iterator rend() const{
			return const_reverse_iterator(begin());
		}

		/*		Operations		*/
		iterator find(const key_type& k){
			return (iterator(bst_find(k), getMinimum(), getMaximum()));
		}

		const_iterator find(const key_type& k) const{
			return (const_iterator(bst_find(k), getMinimum(), getMaximum()));
		}

		size_type count(const key_type& k) const{
			return (bst_find(k) ? 1 : 0);
		}	

		iterator lower_bound(const key_type& k) {
			iterator	tmp = begin();
			while (tmp != end() && _myComp(tmp->first, k))
				++tmp;
			return tmp;
		}
		
		const_iterator lower_bound(const key_type& k) const{
			const_iterator	tmp = begin();
			while (tmp != end() && _myComp(tmp->first, k))
				++tmp;
			return tmp;
		}

		iterator upper_bound(const key_type& k) {
			iterator	tmp = begin();
			while (tmp != end() && !_myComp(k, tmp->first))
				++tmp;	
			return tmp;
		}

		const_iterator upper_bound(const key_type& k) const {
			const_iterator	tmp = begin();
			while (tmp != end() && !_myComp(k, tmp->first))
				++tmp;	
			return tmp;
		}

		ft::pair<iterator,iterator>	equal_range(const key_type& k) {
			return ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k));
		}
		
		pair<const_iterator,const_iterator>	equal_range(const key_type& k) const{
			return ft::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
		}

		/*		Operations		*/
		allocator_type get_allocator() const{
			return _myAlloc;
		}

	};

	/*		Non-member functions	*/
	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ){
		if (lhs.size() != rhs.size()) return false;
		typename ft::map<Key, T, Compare, Alloc>::const_iterator first1 = lhs.begin(), last1 = lhs.end(), first2 = rhs.begin();
		for (; first1 != last1; first1++, first2++)
			if (lhs.value_comp()(*first1, *first2) || lhs.value_comp()(*first2, *first1)) return false;
		return true;
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ){
		return !(lhs == rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ){
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ){
		return !(ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ){
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ){
		return !(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

}

namespace std
{
	/*		std::swap specialization		*/
	template< class Key, class T, class Compare, class Alloc >
	void swap( ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs ){
		lhs.swap(rhs);
	}
}

#endif