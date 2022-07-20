/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 08:09:13 by ann               #+#    #+#             */
/*   Updated: 2022/07/20 16:01:57 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

#include "iterator.hpp"
// #include "../vector.hpp"

namespace ft{
	// template < typename T, typename _Alloc >  class	vector;
	template < typename T, typename _Alloc >  class	vector;

	// template <typename T> class const_vectorIterator;

	/*		ft::vector iterator				*/
	template <typename T, typename _Alloc >
	class vectorIterator
	{
	public:
		typedef typename ft::vector<T, _Alloc>::difference_type		difference_type;
		typedef typename ft::vector<T, _Alloc>::value_type			value_type;
		typedef typename ft::vector<T, _Alloc>::pointer				pointer;
		typedef typename ft::vector<T, _Alloc>::reference			reference;
		typedef typename ft::vector<T, _Alloc>::const_reference		const_reference;
		typedef typename ft::random_access_iterator_tag		iterator_category;

		const vectorIterator &	base(void) const{return *(this);}
		vectorIterator(void) : it_start(0) {}
		vectorIterator(pointer temp) : it_start(temp) {}
		vectorIterator(vectorIterator const & iter) : it_start(iter.it_start) {}
		vectorIterator & operator=(vectorIterator const & iter) {if (this != &iter) this->it_start = iter.it_start; return *(this);}
		~vectorIterator() {}


		operator	vectorIterator<const T, _Alloc>() const{
			return vectorIterator<const T, _Alloc>(it_start);
		}

		
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

		/* --(--ite) --> this doesn't work */
		vectorIterator operator--(void){
			--this->it_start;
			// std::cout << "hey " << *it_start << std::endl;
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
			return this->it_start - rhs.it_start;
		}

		vectorIterator &	operator-=(difference_type n) 
		{
			this->it_start -= n;
			return *(this);
		}
		reference	operator[](difference_type n) {return (this->it_start[n]);}

		bool operator==(const vectorIterator & rhs) const{return this->it_start == rhs.it_start;}
		bool operator!=(const vectorIterator & rhs) const{return this->it_start != rhs.it_start;}
		bool operator>(const vectorIterator & rhs) const{return this->it_start > rhs.it_start;}
		bool operator>=(const vectorIterator & rhs) const{return this->it_start >= rhs.it_start;}
		bool operator<(const vectorIterator & rhs) const{return this->it_start < rhs.it_start;}
		bool operator<=(const vectorIterator & rhs) const{return this->it_start <= rhs.it_start;}

		// friend bool operator==(const vectorIterator<const T, _Alloc> & rhs) const{return this->it_start == rhs.it_start;}
		// friend bool operator!=(const vectorIterator<const T, _Alloc> & rhs) const{return this->it_start != rhs.it_start;}
		// bool operator>(const vectorIterator & rhs) const{return this->it_start > rhs.it_start;}
		// bool operator>=(const vectorIterator & rhs) const{return this->it_start >= rhs.it_start;}
		// bool operator<(const vectorIterator & rhs) const{return this->it_start < rhs.it_start;}
		// bool operator<=(const vectorIterator & rhs) const{return this->it_start <= rhs.it_start;}

		// bool operator==(const vectorIterator<const T, _Alloc> & rhs) const{return this->it_start == rhs.it_start;}
		// bool operator!=(const vectorIterator<const T, _Alloc> & rhs) const{return this->it_start != rhs.it_start;}
		// bool operator>(const vectorIterator<const T, _Alloc> & rhs) const{return this->it_start > rhs.it_start;}
		// bool operator>=(const vectorIterator<const T, _Alloc> & rhs) const{return this->it_start >= rhs.it_start;}
		// bool operator<(const vectorIterator<const T, _Alloc> & rhs) const{return this->it_start < rhs.it_start;}
		// bool operator<=(const vectorIterator<const T, _Alloc> & rhs) const{return this->it_start <= rhs.it_start;}
		

		// template <class TI, class _AllocI>
		// bool operator==(const vectorIterator<  TI, _AllocI> & lhs, const vectorIterator< const TI, _AllocI> & rhs){return lhs.base() == rhs.base();}
		// template <typename TI, typename _AllocI>
		// friend bool operator!=(const vectorIterator<TI, _AllocI> & lhs, const vectorIterator<const TI, _AllocI> & rhs){return lhs.it_start != rhs.it_start;}
		// template <typename TI, typename _AllocI>
		// friend bool operator<(const vectorIterator<TI, _AllocI> & lhs, const vectorIterator<const TI, _AllocI> & rhs){return lhs.it_start < rhs.it_start;}
		// template <typename TI, typename _AllocI>
		// friend bool operator<=(const vectorIterator<TI, _AllocI> & lhs, const vectorIterator<const TI, _AllocI> & rhs){return lhs.it_start <= rhs.it_start;}
		// template <typename TI, typename _AllocI>
		// friend bool operator>(const vectorIterator<TI, _AllocI> & lhs, const vectorIterator<const TI, _AllocI> & rhs){return lhs.it_start > rhs.it_start;}
		// template <typename TI, typename _AllocI>
		// friend bool operator>=(const vectorIterator<TI, _AllocI> & lhs, const vectorIterator<const TI, _AllocI> & rhs){return lhs.it_start >= rhs.it_start;}
		
		
		// template <typename TI>
		// bool operator==(const const_vectorIterator<TI> & rhs){return this->it_start == rhs.it_start;}
		// template <typename TI>
		// bool operator!=(const const_vectorIterator<TI> & rhs){return this->it_start != rhs.it_start;}
		// template <typename TI>
		// bool operator>(const const_vectorIterator<TI> & rhs){return this->it_start > rhs.it_start;}
		// template <typename TI>
		// bool operator>=(const const_vectorIterator<TI> & rhs){return this->it_start >= rhs.it_start;}
		// template <typename TI>
		// bool operator<(const const_vectorIterator<TI> & rhs){return this->it_start < rhs.it_start;}
		// template <typename TI>
		// bool operator<=(const const_vectorIterator<TI> & rhs){return this->it_start <= rhs.it_start;}

	

	private:
		pointer	it_start;
	};

	template <typename T, typename _Alloc>
	vectorIterator<T, _Alloc> operator+(typename vectorIterator<T, _Alloc>::difference_type n, const vectorIterator<T, _Alloc>& it){
		return vectorIterator<T, _Alloc>(it + n);
	}

		// template< typename iterator_left, typename iterator_right >
		// bool operator==(const iterator_left & lhs, const iterator_right & rhs) {return lhs.base() == rhs.base();}
		// template< typename iterator_left, typename iterator_right >
		// bool operator!=(const iterator_left & lhs, const iterator_right & rhs) {return lhs.base() != rhs.base();}
		// template< typename iterator_left, typename iterator_right >
		// bool operator<(const iterator_left & lhs, const iterator_right & rhs) {return lhs.base() < rhs.base();}
		// template< typename iterator_left, typename iterator_right >
		// bool operator<=(const iterator_left & lhs, const iterator_right & rhs) {return lhs.base() <= rhs.base();}
		// bool operator!=(const vectorIterator<T, _Alloc> & rhs) const{return this->it_start != rhs.it_start;}
		// bool operator>(const vectorIterator<T, _Alloc> & rhs) const{return this->it_start > rhs.it_start;}
		// bool operator>=(const vectorIterator<T, _Alloc> & rhs) const{return this->it_start >= rhs.it_start;}
		// bool operator<(const vectorIterator<T, _Alloc> & rhs) const{return this->it_start < rhs.it_start;}
		// bool operator<=(const vectorIterator<T, _Alloc> & rhs) const{return this->it_start <= rhs.it_start;}


		// temp
		
	
// 	/*		const vector iterator		*/
// 	template <typename T>
// 	class const_vectorIterator
// 	{
// 		const_vectorIterator	base(void) {return *(this);}
// 	public:
// 		typedef typename ft::vector<T>::difference_type		difference_type;
// 		typedef typename ft::vector<T>::value_type			value_type;
// 		typedef typename ft::vector<T>::pointer				pointer;
// 		typedef typename ft::vector<T>::const_pointer		const_pointer;
// 		typedef typename ft::vector<T>::reference			reference;
// 		typedef typename ft::vector<T>::const_reference		const_reference;
// 		typedef typename ft::random_access_iterator_tag		iterator_category;

// 		const_vectorIterator(void) : it_start(0) {}
// 		const_vectorIterator(pointer temp) : it_start(temp) {}
// 		const_vectorIterator(const_vectorIterator const & iter) : it_start(iter.it_start) {}
// 		const_vectorIterator & operator=(const_vectorIterator const & iter) {if (this != &iter) this->it_start = iter.it_start; return *(this);}
// 		~const_vectorIterator() {}

// 		/*YOU HAVE TO IMPLEMENT '->' also !!!*/

// 		const_reference	operator*(void) const{
// 			return *(this->it_start);
// 		}

// 		const_pointer	operator->(void) const{
// 			return (this->it_start);
// 		}

// 		const_vectorIterator operator++(void){
// 			++this->it_start;
// 			return (*this);
// 		}

// 		const_vectorIterator operator++(int){
// 			const_vectorIterator temp;
// 			temp.it_start = this->it_start++;
// 			return (temp);
// 		}

// 		const_vectorIterator operator--(void){
// 			--this->it_start;
// 			return (*this);
// 		}

// 		const_vectorIterator operator--(int){
// 			const_vectorIterator temp;
// 			temp.it_start = this->it_start--;
// 			return (temp);
// 		}

// 		const_vectorIterator	operator+(difference_type n)
// 		{
// 			const_vectorIterator temp(*this);
// 			temp = this->it_start + n;
// 			return (temp);
// 		}
// 		const_vectorIterator &	operator+=(difference_type n)
// 		{
// 			this->it_start += n;
// 			return *(this);
// 		}

// 		const_vectorIterator	operator-(difference_type n)
// 		{
// 			const_vectorIterator temp(*this);
// 			temp = this->it_start - n;
// 			return (temp);
// 		}

// 		typename const_vectorIterator::difference_type operator-(const const_vectorIterator & rhs){
// 			return this->it_start - rhs.it_start;
// 		}

// 		const_vectorIterator &	operator-=(difference_type n) 
// 		{
// 			this->it_start -= n;
// 			return *(this);
// 		}
// 		const reference	operator[](difference_type n) const {return (this->it_start[n]);}

// 		template <typename TI>
// 		bool operator==(const vectorIterator<TI> & rhs){return this->it_start == rhs.it_start;}
// 		template <typename TI>
// 		bool operator!=(const vectorIterator<TI> & rhs){return this->it_start != rhs.it_start;}
// 		template <typename TI>
// 		bool operator>(const vectorIterator<TI> & rhs){return this->it_start > rhs.it_start;}
// 		template <typename TI>
// 		bool operator>=(const vectorIterator<TI> & rhs){return this->it_start >= rhs.it_start;}
// 		template <typename TI>
// 		bool operator<(const vectorIterator<TI> & rhs){return this->it_start < rhs.it_start;}
// 		template <typename TI>
// 		bool operator<=(const vectorIterator<TI> & rhs){return this->it_start <= rhs.it_start;}

// 		bool operator==(const const_vectorIterator & rhs){return this->it_start == rhs.it_start;}
// 		bool operator!=(const const_vectorIterator & rhs){return this->it_start != rhs.it_start;}
// 		bool operator>(const const_vectorIterator & rhs){return this->it_start > rhs.it_start;}
// 		bool operator>=(const const_vectorIterator & rhs){return this->it_start >= rhs.it_start;}
// 		bool operator<(const const_vectorIterator & rhs){return this->it_start < rhs.it_start;}
// 		bool operator<=(const const_vectorIterator & rhs){return this->it_start <= rhs.it_start;}

// 	private:
// 		pointer	it_start;
// 	};

// 	template <typename T>
// 	const_vectorIterator<T> operator+(typename vectorIterator<T>::difference_type n, const const_vectorIterator<T>& it){
// 		return const_vectorIterator<T>(it + n);
// 	}
}

#endif