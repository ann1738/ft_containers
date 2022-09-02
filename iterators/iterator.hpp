/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:02:48 by anasr             #+#    #+#             */
/*   Updated: 2022/07/25 16:01:29 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{
	template <class T>
	class	iterator_traits{
	public:
		typedef typename T::difference_type   difference_type;
		typedef typename T::value_type        value_type;
		typedef typename T::pointer           pointer;
		typedef typename T::reference         reference;
		typedef typename T::iterator_category iterator_category;
	};

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag       : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <typename _iter>
	class reverse_iterator{
	public:
		typedef _iter								iterator_type;
		typedef typename _iter::difference_type		difference_type;
		typedef typename _iter::value_type			value_type;
		typedef typename _iter::pointer				pointer;
		typedef typename _iter::const_pointer		const_pointer;
		typedef typename _iter::reference			reference;
		typedef typename _iter::iterator_category	iterator_category;
	protected:
		_iter	current;
	public:
		/*		Constructors		*/
		explicit reverse_iterator() : current() {}
		explicit reverse_iterator( iterator_type x ) : current(x) {}
		template< class U >
		reverse_iterator(const reverse_iterator<U>& rhs) : current(rhs.base()) {}

		/*		Copy assignment		*/
		reverse_iterator& operator=(const reverse_iterator & rhs){
			if (this != &rhs)
				this->current = rhs.current;
			return *(this);
		}

		iterator_type base() const{
			return (current);
		}

		reference operator*() const{
			iterator_type	temp = current;
			return *(--temp); /* thats why &*r == &*(i - 1) */
		}
		
		pointer operator->() const{
			iterator_type	temp = current;
			--temp;
			return temp.operator->();
		}

		reference operator[]( difference_type n ){
			return current[-n - 1]; /* we are working in reverse */
		}
		/*			Operators			*/
		reverse_iterator& operator++() {--current; return *(this);}
		reverse_iterator& operator--() {++current; return *(this);}
		reverse_iterator operator++(int) {return reverse_iterator(current--);}
		reverse_iterator operator--(int) {return reverse_iterator(current++);}
		reverse_iterator operator+( difference_type n ) const {return reverse_iterator(current - n);}
		reverse_iterator operator-( difference_type n ) const {return reverse_iterator(current + n);}
		reverse_iterator& operator+=( difference_type n ) {current -= n; return *(this);}
		reverse_iterator& operator-=( difference_type n ) {current += n; return *(this);}
	};

	template< class IterI >
	reverse_iterator<IterI> operator+(typename reverse_iterator<IterI>::difference_type n, const reverse_iterator<IterI>& it){
		return reverse_iterator<IterI>(it.base() - n);
	}

	/*determines the distance between the two reverse iterators*/
	template< class Iterator >
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
		return (rhs.base() - lhs.base());
	}

	template< class Iterator1, class Iterator2 >
	bool operator==(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs){
		return (lhs.base() == rhs.base());
	}

	template< class Iterator1, class Iterator2 >
	bool operator!=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs){
		return (lhs.base() != rhs.base());
	}

	template< class Iterator1, class Iterator2 >
	bool operator<(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs){
		return (lhs.base() > rhs.base());
	}

	template< class Iterator1, class Iterator2 >
	bool operator<=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs){
		return (lhs.base() >= rhs.base());
	}

	template< class Iterator1, class Iterator2 >
	bool operator>(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs){
		return (lhs.base() < rhs.base());
	}

	template< class Iterator1, class Iterator2 >
	bool operator>=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs){
		return (lhs.base() <= rhs.base());
	}
}


#endif