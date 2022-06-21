/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 08:09:13 by ann               #+#    #+#             */
/*   Updated: 2022/06/21 08:18:18 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

#include "iterator.hpp"
#include "../vector.hpp"

namespace ft{
	template <typename T> class const_vectorIterator;

	/*		ft::vector iterator				*/
	template <typename T>
	class vectorIterator
	{
		vectorIterator	base(void) {return *(this);}
	public:
		typedef typename ft::vector<T>::difference_type		difference_type;
		typedef typename ft::vector<T>::value_type			value_type;
		typedef typename ft::vector<T>::pointer				pointer;
		typedef typename ft::vector<T>::reference			reference;
		typedef typename ft::vector<T>::const_reference		const_reference;
		typedef typename ft::random_access_iterator_tag		iterator_category;

		vectorIterator(void) : it_start(0) {}
		vectorIterator(pointer temp) : it_start(temp) {}
		vectorIterator(vectorIterator const & iter) : it_start(iter.it_start) {}
		vectorIterator & operator=(vectorIterator const & iter) {if (this != &iter) this->it_start = iter.it_start; return *(this);}
		~vectorIterator() {}

		/*YOU HAVE TO IMPLEMENT '->' also !!!*/

		reference	operator*(void){
			return *(this->it_start);
		}

		pointer	operator->(void){
			return (this->it_start);
		}

		vectorIterator operator++(void){
			++this->it_start;
			return (*this);
		}

		vectorIterator operator++(int){
			vectorIterator temp;
			temp.it_start = this->it_start++;
			return (temp);
		}

		vectorIterator operator--(void){
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

		vectorIterator		operator-(difference_type n)
		{
			vectorIterator temp(*this);
			temp = this->it_start - n;
			return (temp);
		}

		template <typename TY>
		typename vectorIterator<TY>::difference_type operator-(const vectorIterator<TY> & rhs){
			return this->it_start - rhs.it_start;
		}

		vectorIterator &	operator-=(difference_type n) 
		{
			this->it_start -= n;
			return *(this);
		}
		reference	operator[](difference_type n) {return (this->it_start[n]);}

		bool operator==(const vectorIterator & rhs){return this->it_start == rhs.it_start;}
		bool operator!=(const vectorIterator & rhs){return this->it_start != rhs.it_start;}
		bool operator>(const vectorIterator & rhs){return this->it_start > rhs.it_start;}
		bool operator>=(const vectorIterator & rhs){return this->it_start >= rhs.it_start;}
		bool operator<(const vectorIterator & rhs){return this->it_start < rhs.it_start;}
		bool operator<=(const vectorIterator & rhs){return this->it_start <= rhs.it_start;}
		
		template <typename TI>
		bool operator==(const const_vectorIterator<TI> & rhs){return this->it_start == rhs.it_start;}
		template <typename TI>
		bool operator!=(const const_vectorIterator<TI> & rhs){return this->it_start != rhs.it_start;}
		template <typename TI>
		bool operator>(const const_vectorIterator<TI> & rhs){return this->it_start > rhs.it_start;}
		template <typename TI>
		bool operator>=(const const_vectorIterator<TI> & rhs){return this->it_start >= rhs.it_start;}
		template <typename TI>
		bool operator<(const const_vectorIterator<TI> & rhs){return this->it_start < rhs.it_start;}
		template <typename TI>
		bool operator<=(const const_vectorIterator<TI> & rhs){return this->it_start <= rhs.it_start;}

	private:
		pointer	it_start;
	};

	template <typename T>
	vectorIterator<T> operator+(typename vectorIterator<T>::difference_type n, const vectorIterator<T>& it){
		return vectorIterator<T>(it + n);
	}
	
	/*		const vector iterator		*/
	template <typename T>
	class const_vectorIterator
	{
		const_vectorIterator	base(void) {return *(this);}
	public:
		typedef typename ft::vector<T>::difference_type		difference_type;
		typedef typename ft::vector<T>::value_type			value_type;
		typedef typename ft::vector<T>::pointer				pointer;
		typedef typename ft::vector<T>::const_pointer		const_pointer;
		typedef typename ft::vector<T>::reference			reference;
		typedef typename ft::vector<T>::const_reference		const_reference;
		typedef typename ft::random_access_iterator_tag		iterator_category;

		const_vectorIterator(void) : it_start(0) {}
		const_vectorIterator(pointer temp) : it_start(temp) {}
		const_vectorIterator(const_vectorIterator const & iter) : it_start(iter.it_start) {}
		const_vectorIterator & operator=(const_vectorIterator const & iter) {if (this != &iter) this->it_start = iter.it_start; return *(this);}
		~const_vectorIterator() {}

		/*YOU HAVE TO IMPLEMENT '->' also !!!*/

		const_reference	operator*(void) const{
			return *(this->it_start);
		}

		const_pointer	operator->(void) const{
			return (this->it_start);
		}

		const_vectorIterator operator++(void){
			++this->it_start;
			return (*this);
		}

		const_vectorIterator operator++(int){
			const_vectorIterator temp;
			temp.it_start = this->it_start++;
			return (temp);
		}

		const_vectorIterator operator--(void){
			--this->it_start;
			return (*this);
		}

		const_vectorIterator operator--(int){
			const_vectorIterator temp;
			temp.it_start = this->it_start--;
			return (temp);
		}

		const_vectorIterator	operator+(difference_type n)
		{
			const_vectorIterator temp(*this);
			temp = this->it_start + n;
			return (temp);
		}
		const_vectorIterator &	operator+=(difference_type n)
		{
			this->it_start += n;
			return *(this);
		}

		const_vectorIterator	operator-(difference_type n)
		{
			const_vectorIterator temp(*this);
			temp = this->it_start - n;
			return (temp);
		}

		typename const_vectorIterator::difference_type operator-(const const_vectorIterator & rhs){
			return this->it_start - rhs.it_start;
		}

		const_vectorIterator &	operator-=(difference_type n) 
		{
			this->it_start -= n;
			return *(this);
		}
		const reference	operator[](difference_type n) const {return (this->it_start[n]);}

		template <typename TI>
		bool operator==(const vectorIterator<TI> & rhs){return this->it_start == rhs.it_start;}
		template <typename TI>
		bool operator!=(const vectorIterator<TI> & rhs){return this->it_start != rhs.it_start;}
		template <typename TI>
		bool operator>(const vectorIterator<TI> & rhs){return this->it_start > rhs.it_start;}
		template <typename TI>
		bool operator>=(const vectorIterator<TI> & rhs){return this->it_start >= rhs.it_start;}
		template <typename TI>
		bool operator<(const vectorIterator<TI> & rhs){return this->it_start < rhs.it_start;}
		template <typename TI>
		bool operator<=(const vectorIterator<TI> & rhs){return this->it_start <= rhs.it_start;}

		bool operator==(const const_vectorIterator & rhs){return this->it_start == rhs.it_start;}
		bool operator!=(const const_vectorIterator & rhs){return this->it_start != rhs.it_start;}
		bool operator>(const const_vectorIterator & rhs){return this->it_start > rhs.it_start;}
		bool operator>=(const const_vectorIterator & rhs){return this->it_start >= rhs.it_start;}
		bool operator<(const const_vectorIterator & rhs){return this->it_start < rhs.it_start;}
		bool operator<=(const const_vectorIterator & rhs){return this->it_start <= rhs.it_start;}

	private:
		pointer	it_start;
	};

	template <typename T>
	const_vectorIterator<T> operator+(typename vectorIterator<T>::difference_type n, const const_vectorIterator<T>& it){
		return const_vectorIterator<T>(it + n);
	}
}

#endif