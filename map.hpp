/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:50:42 by ann               #+#    #+#             */
/*   Updated: 2022/06/21 18:35:44 by ann              ###   ########.fr       */
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
		typedef	Alloc::pointer							pointer;
		typedef Alloc::const_pointer						const_pointer;
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
			value_type	_nod;
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
	public:

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

		/*			Modifiers			*/
		
		
	};
}

#endif