/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 08:09:13 by ann               #+#    #+#             */
/*   Updated: 2022/09/01 18:28:21 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

#include "iterator.hpp"

namespace ft{
	template < typename T, typename _Alloc >  class	vector;

	/*		ft::vector iterator				*/
	template <typename T, typename _Alloc >
	class vectorIterator
	{
	public:
		typedef typename ft::vector<T, _Alloc>::difference_type		difference_type;
		typedef typename ft::vector<T, _Alloc>::value_type			value_type;
		typedef typename ft::vector<T, _Alloc>::pointer				pointer;
		typedef typename ft::vector<T, _Alloc>::const_pointer		const_pointer;
		typedef typename ft::vector<T, _Alloc>::reference			reference;
		typedef typename ft::vector<T, _Alloc>::const_reference		const_reference;
		typedef typename ft::random_access_iterator_tag		iterator_category;

		vectorIterator(void) : it_start(0) {}
		vectorIterator(vectorIterator const & iter) : it_start(iter.it_start) {}
		vectorIterator(pointer temp) : it_start(temp) {}
		vectorIterator & operator=(vectorIterator const & iter) {if (this != &iter) this->it_start = iter.it_start; return *(this);}
		~vectorIterator() {}

		const pointer &	base(void) const{return it_start;}

		operator	vectorIterator<const T, _Alloc>() const{
			return vectorIterator<const T, _Alloc>(it_start);
		}

		reference	operator*(void) const{
			return *(this->it_start);
		}

		pointer	operator->(void) const{
			return (this->it_start);
		}

		vectorIterator & operator++(void){
			++this->it_start;
			return (*this);
		}

		vectorIterator operator++(int){
			vectorIterator temp;
			temp.it_start = this->it_start++;
			return (temp);
		}

		vectorIterator & operator--(void){
			--this->it_start;
			return (*this);
		}

		vectorIterator operator--(int){
			vectorIterator temp;
			temp.it_start = this->it_start--;
			return (temp);
		}

		vectorIterator		operator+(difference_type n) const
		{
			vectorIterator temp(*this);
			temp = this->it_start + n;
			return (temp);
		}
		vectorIterator &	operator+=(difference_type n)
		{
			this->it_start += n;
			return *(this);
		}

		vectorIterator		operator-(difference_type n) const
		{
			vectorIterator temp(*this);
			temp = this->it_start - n;
			return (temp);
		}

		template <typename TY, typename _AllocY>
		typename vectorIterator<TY, _AllocY>::difference_type operator-(const vectorIterator<TY, _AllocY> & rhs) const{
			return base() - rhs.base();
		}

		vectorIterator &	operator-=(difference_type n) 
		{
			this->it_start -= n;
			return *(this);
		}

		reference	operator[](difference_type n) {return (this->it_start[n]);}

		bool operator==(const vectorIterator<const T, _Alloc> & rhs) const{return base() == rhs.base();}
		bool operator!=(const vectorIterator<const T, _Alloc> & rhs) const{return base() != rhs.base();}
		bool operator<(const vectorIterator<const T, _Alloc> & rhs) const{return base() < rhs.base();}
		bool operator<=(const vectorIterator<const T, _Alloc> & rhs) const{return base() <= rhs.base();}
		bool operator>(const vectorIterator<const T, _Alloc> & rhs) const{return base() > rhs.base();}
		bool operator>=(const vectorIterator<const T, _Alloc> & rhs) const{return base() >= rhs.base();}

	private:
		pointer	it_start;
	};

	template <typename T, typename _Alloc>
	vectorIterator<T, _Alloc> operator+(typename vectorIterator<T, _Alloc>::difference_type n, const vectorIterator<T, _Alloc>& it){
		return vectorIterator<T, _Alloc>(it + n);
	}

}

#endif