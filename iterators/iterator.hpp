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
		typedef  _iter					  			iterator_type;
		typedef typename _iter::difference_type  	difference_type;
		typedef typename _iter::value_type       	value_type;
		typedef typename _iter::pointer         	pointer;
		typedef typename _iter::const_pointer         	const_pointer;
		typedef typename _iter::reference        	reference;
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
		
		/*check pls*/
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
		// reverse_iterator operator++(int) {reverse_iterator temp = *this; --current; return temp;}
		// reverse_iterator operator--(int) {reverse_iterator temp = *this; ++current; return temp;}
		reverse_iterator operator+( difference_type n ) const {return reverse_iterator(current - n);}
		reverse_iterator operator-( difference_type n ) const {return reverse_iterator(current + n);}
		reverse_iterator& operator+=( difference_type n ) {current -= n; return *(this);}
		reverse_iterator& operator-=( difference_type n ) {current += n; return *(this);}

		
		/*	Non-member functions of ft::reverse_iterators	*/

		// /*advances the reverse iterator*/

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

#if 0
	/* Iterator all categories: copy constructible, copy assignable, destructable */
	template <class T>
	class iterator: public iterators_traits<T>
	{
	private:
		friend class T;
	public:
		iterator(pointer temp) : it_start(temp) {}
		iterator(iterator const & iterator) : it_start(temp) {}
		iterator & operator=(iterator const & iterator) {this->it_start = iterator.it_start;}
		~iterator() {}

		iterator operator++(void){
			return (++(this->it_start));
		}

		iterator operator++(int){
			iterator temp;
			temp.it_start = this->it_start++;
			return (temp);
		}
	private:
		pointer	it_start;
	};

	/* Input: "==", "!=", and derefrencing through "*" and "->" (only access .. not assignable, rvalue) */
	template <class T>
	class input_iterator: virtual public iterator{
	public:
		const reference	operator*(void) const{
			return *(this->it_start);
		}

		/* check this pls !!!!!*/
		const reference	operator->(void) const{
			return *(this->it_start);
		}

		bool	operator==(const iterator & rhs) {return (this->it_start == rhs.it_start);}
		bool	operator!=(const iterator & rhs) {return (this->it_start != rhs.it_start);}
	};

	/* Output: derefrencing through "*" (assignable, lvalue) */
	template <class T>
	class output_iterator: virtual public iterator{
	public:
		reference	operator*(void){
			return *(this->it_start);
		}
	};

	/* Forward: default constructible */
	template <class T>
	class forward_iterator: public output_iterator, public input_iterator
	{
	public:
		iterator() : it_start(nullptr) {}
	};

	/* Biderectional: default constructible */
	template <class T>
	class bidirectional_iterator: public forward_iterator
	{
	public:
		iterator operator--(void){
			return (--(this->it_start));
		}

		iterator operator--(int){
			iterator temp;
			temp.it_start = this->it_start--;
			return (temp);
		}
	};

	/* Random Access:  */
	template <class T>
	class random_access_iterator: public bidirectional_iterator
	{
		iterator	operator+(const iterator & rhs) {return iterator(this->it_start + rhs.it_start);}
		iterator	operator-(const iterator & rhs) {return iterator(this->it_start - rhs.it_start);}
		iterator&	operator+=(const iterator & rhs) {this->it_start += rhs.it_start; return *(this)}
		iterator&	operator-=(const iterator & rhs) {this->it_start -= rhs.it_start; return *(this)}
		bool	operator<(const iterator & rhs) {return (this->it_start < rhs.it_start);}
		bool	operator<=(const iterator & rhs) {return (this->it_start <= rhs.it_start);}
		bool	operator>(const iterator & rhs) {return (this->it_start > rhs.it_start);}
		bool	operator>=(const iterator & rhs) {return (this->it_start >= rhs.it_start);}
		reference	operator[](T::size_type n) {return *(this->it_start + 1);}
	};
#endif
}


#endif