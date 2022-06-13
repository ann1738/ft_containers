/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:02:48 by anasr             #+#    #+#             */
/*   Updated: 2022/06/13 15:51:31 by anasr            ###   ########.fr       */
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