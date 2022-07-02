/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 09:58:27 by anasr             #+#    #+#             */
/*   Updated: 2022/07/02 09:59:52 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

namespace ft
{
	// class
	private:	
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

		pointer	init_node(const key_type & n = key_type(), const mapped_type & m = mapped_type()){
			pointer tmp = _myAlloc.allocate(1);
			_myAlloc.construct(tmp, node(ft::make_pair< const key_type, mapped_type>(n, m)));
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
				if (!_myComp(findMyPlace.first, tmp->_info.first) && !_myComp(tmp->_info.first, findMyPlace.first)) //if equal
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
			std::cout << "\e[35mrotate left " << x->_info.first << "\e[0m" << std::endl;
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
			std::cout << "\e[35mrotate right " << x->_info.first << "\e[0m" << std::endl;
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

		void	rotate_n_recolor(pointer newNode){
			/* base condition */
			if (newNode == _root || newNode->_parent->_color == BLACK) return ;
			/**/
			pointer	aunt = amILeft(newNode) ? newNode->_left : aunt = newNode->_right;
			if (!aunt || aunt->_color == BLACK)
			{
				if (!amILeft(newNode->_parent) && !amILeft(newNode)) /* R R */
				{
					std::cout << "R R --- " << newNode->_info.first << std::endl;
					std::cout << "recolor both " << newNode->_parent->_info.first << " and " << newNode->_parent->_parent->_info.first << std::endl;
					recolor(newNode->_parent);
					recolor(newNode->_parent->_parent);

					rotate_left(newNode->_parent->_parent);
				}
				else if (amILeft(newNode->_parent) && amILeft(newNode)) /* L L */
				{
					std::cout << "L L --- " << newNode->_info.first << std::endl;
					std::cout << "recolor both " << newNode->_parent->_info.first << " and " << newNode->_parent->_parent->_info.first << std::endl;
					recolor(newNode->_parent);
					recolor(newNode->_parent->_parent);

					rotate_right(newNode->_parent->_parent);
				}
				else if (!amILeft(newNode->_parent) && amILeft(newNode)) /* R L */
				{
					std::cout << "R L --- " << newNode->_info.first << std::endl;
					rotate_right(newNode->_parent);

					std::cout << "recolor both " << newNode->_parent->_info.first << " and " << newNode->_parent->_parent->_info.first << std::endl;
					recolor(newNode->_parent);
					recolor(newNode->_parent->_parent);

					rotate_left(newNode->_parent->_parent);					
				}
				else// (amILeft(newNode->_parent) && !amILeft(newNode)) /* L R */
				{
					std::cout << "L R --- " << newNode->_info.first << std::endl;
					rotate_left(newNode->_parent);

					std::cout << "recolor both " << newNode->_parent->_info.first << " and " << newNode->_parent->_parent->_info.first << std::endl;
					recolor(newNode->_parent);
					recolor(newNode->_parent->_parent);

					rotate_right(newNode->_parent->_parent);	
				}	
			}
			else /* aunt is RED */
			{
				std::cout << "\e[31mAUNT IS REDDDD .. rnb recoloring \e[0m" << std::endl;
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


} // namespace ft


#endif