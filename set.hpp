/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 09:58:27 by anasr             #+#    #+#             */
/*   Updated: 2022/07/25 11:31:03 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# define RED 0
# define BLACK 1

# define RB_DEBUG 1
# define RB_DEL_DEBUG 1
# define BST_FIND_DEBUG 0
# define BST_DEL_DEBUG 1

#include <memory>
#include "iterators/setIterator.hpp"
#include "additional.hpp"

namespace ft
{
	template < class T,                        // set::key_type/value_type
           class Compare = std::less<T>,        // set::key_compare/value_compare
           class Alloc = std::allocator<T>      // set::allocator_type
           >
	class set{
	struct node;
	public:
		typedef	T																	key_type;
		typedef	T																	value_type;
		typedef	T																	val;
		typedef	Compare																key_compare;
		typedef	Compare																value_compare;
		typedef	typename Alloc::template rebind<node>::other						allocator_type;
		typedef	value_type &														reference;
		typedef	const value_type &													const_reference;
    	typedef node *																pointer;
    	typedef const pointer														const_pointer;
		typedef	setIterator<key_type, key_compare, allocator_type>					iterator;
		// typedef	constSetIterator<const key_type , key_compare, allocator_type>		const_iterator;
		typedef	ft::reverse_iterator<iterator>										reverse_iterator;
		// typedef	ft::reverse_iterator<const_iterator>								const_reverse_iterator;
		typedef	std::ptrdiff_t														difference_type;
		typedef	size_t																size_type;
	private:
		key_compare 	_myComp;
		allocator_type	_myAlloc;
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

		pointer	init_node(const key_type & n = key_type()){
			pointer tmp = _myAlloc.allocate(1);
			_myAlloc.construct(tmp, node(n));
			return tmp;
		}

		void	del_node(pointer deleteMe){
			_myAlloc.destroy(deleteMe);
			_myAlloc.deallocate(deleteMe, 1);
		}

		void	recolor(pointer _nod) {if (RB_DEBUG) std::cout << "recolor: " << _nod->_info << std::endl; _nod->_color == RED ? _nod->_color = BLACK : _nod->_color = RED;};
		
		/*pointer can't be root*/
		bool	amILeft(pointer _nod) {return _nod == _nod->_parent->_left;}
		
		pointer	getMinimum() const{ if (!_root) return NULL; pointer tmp = _root; for (; tmp->_left; tmp = tmp->_left) {}; return tmp; }

		pointer	getMaximum() const{ if (!_root) return NULL; pointer tmp = _root; for (; tmp->_right; tmp = tmp->_right) {}; return tmp; }

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

		void	clear_tree(pointer _node){
			if (!_node) return ;
			if (_node->_left)
				clear_tree(_node->_left);
			if (_node->_right)
				clear_tree(_node->_right);
			del_node(_node);
		}
		/*	BST ALGORITHMS	*/

		/*	finds the node with the corresponding key if it exists.. if the key exists it returns a pointer to it	*/
		/*	otherwise, it returns NULL	*/
		pointer	bst_find(const key_type & findMe) const{
			pointer tmp = _root;
			#if BST_FIND_DEBUG
				size_type count = 0;
			#endif
			while (tmp != NULL && !(!_myComp(tmp->_info, findMe) && !_myComp(findMe, tmp->_info)))
			{
				if (_myComp(findMe, tmp->_info))
					tmp = tmp->_left;
				else
					tmp = tmp->_right;
				#if BST_FIND_DEBUG
				++count;
				#endif
			}
			#if BST_FIND_DEBUG
				std::cout << "\e[36mbst_find(): number of operations (how many loops) to find the node is \e[0m" << count << std::endl;
			#endif
			return tmp;
		}
		
		/*	- doesn't check if key is already there	*/
		/*	- increments _size	*/
		pointer	bst_insert(const value_type & val){
			/*creates the node*/
			pointer newNode = init_node(val);
			pointer tmp = _root, saveTmp = 0;
			while (tmp != NULL)
			{
				saveTmp = tmp;
				if (_myComp(val, tmp->_info))
					tmp = tmp->_left;
				else
					tmp = tmp->_right;
			}
			newNode->_parent = saveTmp;
			if (!saveTmp)
				_root = newNode;
			else if (_myComp(val, saveTmp->_info))
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
		
		/*	creates a nill node with a link to the parent (but the parent is not linked to it) */
		pointer	createNillNode(){
			pointer tmp = init_node();
			tmp->_color = BLACK;
			tmp->_right = tmp; /* marker for identification (i can put this in createNillNode()) */
			return tmp;
		}

		bool	isNillNode(pointer amINillNode){
			return amINillNode->_right == amINillNode;
		}

		/*	- decrements _size	*/
		/*	this method is modified to assist rb tree:	*/
		/*		- it will return the replacement node (which can be nill node)	*/
		/*		- in the case of no children for the deleted node, then a nill_node is created, */
		/*		this will be deleted when the deletion is done (thus this should not be used by */
		/*		itself as it will leak) 														*/
		pointer	bst_delete_modified(pointer deleteMe){
			if (!deleteMe) return NULL; /*checks if it exists*/
			pointer replacementNode = 0;
	
			if (deleteMe->_left && deleteMe->_right) /* case 3: two children */
			{
			// std::cout << "\e[31mbst_delete_modified: successor delete\e[0m" << std::endl;
				pointer successor = getSubMinimum(deleteMe->_right);
				deleteMe->_info = successor->_info; //copy the data of the 
				// now successor needs to be deleted
			// std::cout << "in order successor is " << successor->_info << std::endl;
				ft::myswap(successor, deleteMe);
			// std::cout << "AFTER SWAP: delete_me is " << deleteMe->_info << std::endl;
				// now deleteMe is what is to be deleted
			}
			/* fall through */
			if (!deleteMe->_left && !deleteMe->_right) /* case 1: no child */
			{
				#if BST_DEL_DEBUG
				std::cout << "\e[31mbst_delete_modified: no child - nill node created\e[0m" << std::endl;
				#endif
			// std::cout << "\e[31mbst_delete_modified: no child - nill node created\e[0m" << std::endl;
				replacementNode = createNillNode();
				replaceNodePos(deleteMe, replacementNode);
				// replacementNode->_right = replacementNode; /* marker for identification (i can put this in createNillNode()) */
			}
			else if (!deleteMe->_left) /* case 2: one right child */
			{
				#if BST_DEL_DEBUG
				std::cout << "\e[31mbst_delete_modified: one child (right) \e[0m" << std::endl;
				#endif
				replacementNode = deleteMe->_right;
				replaceNodePos(deleteMe, deleteMe->_right);
			}
			else if (!deleteMe->_right) /* case 2: one left child */
			{
				#if BST_DEL_DEBUG
				std::cout << "\e[31mbst_delete_modified: one child (left) \e[0m" << std::endl;
				#endif
				replacementNode = deleteMe->_left;
				replaceNodePos(deleteMe, deleteMe->_left);
			}
			del_node(deleteMe);
			--_size;
			return replacementNode;
		}

		/*	rotation algorithms	*/
		void	rotate_left(pointer x){
			# if RB_DEBUG
			std::cout << "\e[35mrotate left " << x->_info << "\e[0m" << std::endl;
			# endif
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
		}

		void	rotate_right(pointer x){
			# if RB_DEBUG
			std::cout << "\e[35mrotate right " << x->_info << "\e[0m" << std::endl;
			# endif
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
		}

		/*	recursive function	*/
		void	rotate_n_recolor(pointer newNode){
			/* base condition */
			if (newNode == _root || newNode->_parent->_color == BLACK) return ;
			/**/
			pointer	aunt = amILeft(newNode->_parent) ? newNode->_parent->_parent->_right : newNode->_parent->_parent->_left; //check
			if (RB_DEBUG && aunt) std::cout << "aunt is " << aunt->_info << std::endl; 
			if (!aunt || aunt->_color == BLACK)
			{
				if (RB_DEBUG)
					std::cout << "aunt is \e[30mBLACK\e[0m" << std::endl; 
				if (!amILeft(newNode->_parent) && !amILeft(newNode)) /* R R */
				{
					if (RB_DEBUG) std::cout << "R R" << std::endl;
					recolor(newNode->_parent);
					recolor(newNode->_parent->_parent);

					rotate_left(newNode->_parent->_parent);
				}
				else if (amILeft(newNode->_parent) && amILeft(newNode)) /* L L */ 
				{
					if (RB_DEBUG) std::cout << "L L" << std::endl;
					recolor(newNode->_parent);
					recolor(newNode->_parent->_parent);

					rotate_right(newNode->_parent->_parent);
				}
				else if (!amILeft(newNode->_parent) && amILeft(newNode)) /* R L */
				{
					if (RB_DEBUG) std::cout << "R L" << std::endl;
					rotate_right(newNode->_parent);

					recolor(newNode);
					recolor(newNode->_parent);

					rotate_left(newNode->_parent);					
				}
				else// (amILeft(newNode->_parent) && !amILeft(newNode)) /* L R */
				{
					if (RB_DEBUG) std::cout << "L R" << std::endl;
					rotate_left(newNode->_parent);

					recolor(newNode);
					recolor(newNode->_parent);

					rotate_right(newNode->_parent);	
				}	
			}
			else /* aunt is RED */
			{
				if (RB_DEBUG) std::cout << "aunt is \e[31mRED\e[0m" << std::endl; 
				rb_recoloring(newNode->_parent->_parent, aunt, newNode->_parent);
			}
		}
		
		void	rb_recoloring(pointer gramma, pointer aunt, pointer parent){
			recolor(parent);
			recolor(aunt);
			if (gramma != _root)
				recolor(gramma);
			rotate_n_recolor(gramma);
		}
	
		bool	getColor(pointer _node){
			return (_node && _node->_color == RED ? RED : BLACK);
		}

		void	changeColor(pointer _node, bool color){
			_node->_color = color;
			#if RB_DEL_DEBUG
			std::cout << "recolor " << _node->_info << " to ";
			if (color == RED) std::cout << "\e[31mred\e[0m" << std::endl;
			else std::cout << "\e[30mblack\e[0m" << std::endl;
			# endif
		}

		void	deallocateIfNillNode(pointer _node){
			if (isNillNode(_node))
			{
				#if RB_DEL_DEBUG
				std::cout << "\e[31mDetected Nill Node\e[0m" << std::endl;
				#endif
				replaceNodePos(_node, NULL);
				del_node(_node);
			}
		}

		/* - assuming it exists */
		void	rb_delete(pointer deleteMe){
			#if RB_DEL_DEBUG
			std::cout << "\e[31m************************************rb delete of " << deleteMe->_info << "\e[0m" << std::endl;
			#endif
			/* if deleteMe node is red, then it is a simple case */
			bool	save_deleteMe_color = deleteMe->_color;

			if (deleteMe->_left && deleteMe->_right) save_deleteMe_color = getSubMinimum(deleteMe->_right)->_color; /* can be optimized */
			pointer replacementNode = bst_delete_modified(deleteMe);

			/* if the deleted node was red, we can simply remove it */
			if (save_deleteMe_color == RED) /* maybe we need to check if createNillNode was used before returning*/
			{
				#if RB_DEL_DEBUG
				std::cout << "\e[34msimple case: deleted node is RED\e[0m" << std::endl;
				#endif
				deallocateIfNillNode(replacementNode);
				return ;
			}	

			/* if deleted node is black, we have to adjust the tree to maintain rb properties */

		while (1)
		{
			/*		case 1: deleteMe is _root																					*/
			if (replacementNode == _root)
			{
				#if RB_DEL_DEBUG
				std::cout << "\e[34mCase 1 detected (deleted node is the root)\e[0m" << std::endl;
				#endif
				changeColor(replacementNode, BLACK);
				return ;
			}

			/*find the sibling*/
			pointer sibling = amILeft(replacementNode) ? replacementNode->_parent->_right : replacementNode->_parent->_left;

			#if RB_DEL_DEBUG
			if (replacementNode) std::cout << "replacementNode is " << replacementNode->_info << std::endl;
			if (sibling) std::cout << "sibling is " << sibling->_info << std::endl;
			else std::cout << "sibling is " << "\e[31mNULL\e[0m" << std::endl;
			#endif

			/*	if the deleted node is black, we have six cases:	*/
			/*		case 1: deleteMe is _root																					*/
			/*		case 2: sibling of deleteMe is red																			*/
			/*		case 3: sibling of deleteMe is black, both sibling's children are black, parent is red						*/
			/*		case 4: sibling of deleteMe is black, both sibling's children are black, parent is black					*/
			/*		case 5: sibling of deleteMe is black, at least one of sibling's children is red, sibling->_right is black	*/
			/*		case 6: sibling of deleteMe is black, at least one of sibling's children is red, sibling->_right is red		*/

			/*	case 1 is above	*/

			/*		case 2: sibling of deleteMe is red																			*/
			if (getColor(sibling) == RED)
			{
				#if RB_DEL_DEBUG
				std::cout << "\e[34mCase 2 detected (sibling is red)\e[0m" << std::endl;
				#endif
				changeColor(sibling, BLACK);
				changeColor(sibling->_parent, RED);
				if (!amILeft(sibling)) /*the deleted node is on the left*/
					rotate_left(sibling->_parent);
				else
					rotate_right(sibling->_parent);
				sibling = amILeft(replacementNode) ? replacementNode->_parent->_right : replacementNode->_parent->_left; /* update the sibling after the rotation */
			}

			/* FALLTHROUGH	*/

			/*		case 3: sibling of deleteMe is black, both sibling's children are black, parent is red						*/
			/*		case 4: sibling of deleteMe is black, both sibling's children are black, parent is black					*/
			if (getColor(sibling) == BLACK && (getColor(sibling->_left) == BLACK && getColor(sibling->_right) == BLACK))
			{
				changeColor(sibling, RED);
				if (getColor(sibling->_parent) == RED)
				{
					#if RB_DEL_DEBUG
					std::cout << "\e[34mCase 3 detected (sibling is black with two black children -- parent is red)\e[0m" << std::endl;
					#endif	
					changeColor(sibling->_parent, BLACK);
				}
				else
				{
					#if RB_DEL_DEBUG
					std::cout << "\e[34mCase 4 detected (sibling is black with two black children -- parent is black)\e[0m" << std::endl;
					#endif
					pointer save = replacementNode->_parent;
					deallocateIfNillNode(replacementNode);
					replacementNode = save;
					continue ;
				}
			}
			/*		case 5: sibling of deleteMe is black, at least one of sibling's children is red, outer nephew (the sibling's child that is opposite to direction of the deleted node) is black	*/
			/*		case 6: sibling of deleteMe is black, at least one of sibling's children is red, outer nephew is red		*/
			else
			{
				/*	case 5	*/
				if (amILeft(replacementNode) && getColor(sibling->_right) == BLACK) /* right child of the sibling is black */
				{
					#if RB_DEL_DEBUG
					std::cout << "\e[34mCase 5 detected (sibling is black with at least one red child -- outer nephew is black)\e[0m" << std::endl;
					#endif
					changeColor(sibling, RED);
					changeColor(sibling->_left, BLACK);
					rotate_right(sibling);

					sibling = amILeft(replacementNode) ? replacementNode->_parent->_right : replacementNode->_parent->_left;
				}
				else if (!amILeft(replacementNode) && getColor(sibling->_left) == BLACK)
				{
					#if RB_DEL_DEBUG
					std::cout << "\e[34mCase 5 detected (sibling is black with at least one red child -- outer nephew is black)\e[0m" << std::endl;
					#endif
					changeColor(sibling, RED);
					changeColor(sibling->_right, BLACK);
					rotate_left(sibling);
					sibling = amILeft(replacementNode) ? replacementNode->_parent->_right : replacementNode->_parent->_left;
				}

				/*	FALL THROUGH */

				/*	case 6	*/
				#if RB_DEL_DEBUG
				std::cout << "\e[34mCase 6 detected (sibling is black with at least one red child -- outer nephew is red)\e[0m" << std::endl;
				#endif
				changeColor(sibling, getColor(sibling->_parent)); /*recoloring the new sibling with the its parent's color*/
				changeColor(sibling->_parent, BLACK);
				if (amILeft(replacementNode))
				{
					changeColor(sibling->_right, BLACK);
					rotate_left(sibling->_parent);
				}
				else
				{
					changeColor(sibling->_left, BLACK);
					rotate_right(sibling->_parent);
				}
			}
			break ;
			// if (isNillNode(replacementNode))
			// {
			// 	#if RB_DEL_DEBUG
			// 	std::cout << "\e[31mDetected Nill Node\e[0m" << std::endl;
			// 	#endif
			// 	replaceNodePos(replacementNode, NULL);
			// 	del_node(replacementNode);
			// }
			}
			
			deallocateIfNillNode(replacementNode);

		}
		
		/*	Red-Black Tree Algorithms	*/

		/*	assuming key doesn't exist already	*/
		pointer	rb_insert(const value_type& val){
			if (RB_DEBUG)
				std::cout << "\e[35m***************************** rb insert of " << val << "\e[0m" << std::endl;
			/* bst insertion */
			pointer		newNode = bst_insert(val);
			
			/*if inserted node is root */
			if (newNode == _root) {newNode->_color = BLACK; return newNode;}
			
			/* if parent of the inserted node is black */
			if (newNode->_parent->_color == BLACK) return newNode;

			/* if parent of the inserted node is red */
			rotate_n_recolor(newNode);
			return newNode;
		}

		public:
		/*		Constructors		*/
		explicit set (const key_compare& comp = key_compare(),
              		  const allocator_type& alloc = allocator_type())
					  : _myComp(comp), _myAlloc(alloc), _root(0), _size(0) {}
		
		/* !!! RANGE CONSTRUCTOR NOT DONE !!! */
		// template <class InputIterator>
  		// set (InputIterator first, InputIterator last,
       	// 	const key_compare& comp = key_compare(),
       	// 	const allocator_type& alloc = allocator_type());

		
		/* !!!  NOT DONE !!! */
		// set (const set& x);

		/*		Destructor		*/
		~set(){
			clear();
		}
		
		/*		Copy Assignment Operator		*/
		/* !!!  NOT DONE !!! */
		// set& operator= (const set& x);
		
		/*		Modifiers		*/
		pair<iterator,bool> insert (const value_type& val){
			pointer check = bst_find(val);
			if (check) return ft::make_pair<iterator, bool>(iterator(check), false); /*checks if it exists*/
			check = rb_insert(val);
			return ft::make_pair<iterator, bool>(iterator(check), true);
		}
		
		/* !!!  NOT DONE !!! */
		// iterator insert (iterator position, const value_type& val);

		/* !!!  NOT DONE !!! */
		// template <class InputIterator>
  		// void insert (InputIterator first, InputIterator last);
		
		/* !!!  NOT DONE !!! */
    	// void erase (iterator position);
		
		/* !!!  NOT DONE !!! */
		size_type erase (const value_type& val){
			pointer check = bst_find(val);
			if (!check) return 0;
			rb_delete(check);
			return 1;
		}
		
		/* !!!  NOT DONE !!! */
     	// void erase (iterator first, iterator last);
		
		/* !!! remove this !!! */
		void	printColorAndParent(const key_type & k){
			// std::cout << k << std::endl;
			pointer tmp = bst_find(k);
			if (tmp->_color == RED)
				std::cout << "\e[31mRED\e[0m";
			else
				std::cout << "\e[30mBLACK\e[0m";
			if (tmp->_parent)
				std::cout << "\e[0m with parent\e[32m\t" << tmp->_parent->_info << "\e[0m\n";
			else
				std::cout << "\e[0m with no parent\t\e[32m(ROOT)" << "\e[0m\n";
				
		}
		void	printColor(const key_type & k){
			pointer tmp = bst_find(k);
			if (tmp->_color == RED)
				std::cout << "\e[31mRED\e[0m\n";
			else
				std::cout << "\e[30mBLACK\e[0m\n";			
		}
		
		/* has invalid reads pls fix */
		void clear(){
			clear_tree(_root);
		}

		/*		Iterators		*/
		iterator begin(){
			return (iterator(getMinimum()));
		}

		/* !!!  NOT DONE !!! */
		// const_iterator begin() const;

		iterator end(){
			return (iterator(NULL));
		}

		/* !!!  NOT DONE !!! */
		// const_iterator end() const;

		/*	Capacity	*/
		bool empty() const{
			return !_root;
		}
		
		size_type size() const{
			return _size;
		}
		
		size_type max_size() const{
			return _myAlloc.max_size();
		}
		
		/*	Operations	*/
		iterator find (const value_type& val) const{
			pointer tmp = bst_find(val);
			if (!bst_find) return end();
			return iterator(tmp);
		}
		

	};

} // namespace ft


#endif