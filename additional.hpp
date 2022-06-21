/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:08:35 by anasr             #+#    #+#             */
/*   Updated: 2022/06/21 13:12:47 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADDITIONAL_HPP
# define ADDITIONAL_HPP

#include <iostream>

namespace ft
{
	/*			ft::equal			*/
	template< class InputIt1, class InputIt2 >
	bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 ){
		for (; first1 != last1; first1++, first2++)
		{
			std::cout << "f1 is " << *first1 << ", and f2 is " << *first2 << std::endl;
			if (*first1 != *first2) return false;
		}
		return true;
	}
	
	template< class InputIt1, class InputIt2, class BinaryPredicate >
	bool equal( InputIt1 first1, InputIt1 last1,
				InputIt2 first2, BinaryPredicate p ){
		for (; first1 != last1; first1++, first2++)
		{
			std::cout << "f1 is " << *first1 << ", and f2 is " << *first2 << std::endl;
			if (!p(*first1, *first2)) return false;
		}
		return true;
	}

	/*		ft::lexicographical_compare		*/
	template< class InputIt1, class InputIt2 >
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								 InputIt2 first2, InputIt2 last2 ){
		for (; first1 != last1 && first2 != last2; ++first1, ++first2)
		{
			if (*first1 < *first2) return true;
			if (*first1 > *first2) return false;
		}
		return (first1 == last1 && first2 != last2); /* non-empty array is greater than an empty array */
	}

	template< class InputIt1, class InputIt2, class Compare >
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                            	 InputIt2 first2, InputIt2 last2,
                              	 Compare comp )
	{
		for (; first1 != last1 && first2 != last2; ++first1, ++first2)
		{
			if (comp(*first1, first2)) return true;
			if (comp(*first2, first1)) return false;
		}
		return (first1 == last1 && first2 != last2);
	}


	/*		ft::pair		*/
	template< class T1, class T2 >
	struct pair
	{
		pair();
		pair( const T1& x, const T2& y );
		template< class U1, class U2 >
		pair( const pair<U1, U2>& p );
	};

	/*		enable_if		*/
	template< bool B, class T = void >
	struct enable_if {};

	template< class T >
	struct enable_if<true, T> {typedef T type;};

	/*		is_integral		*/
	template< class T, T _val>
	struct _is_integral_base
	{
		static const T	value = _val;
	};

	typedef _is_integral_base<bool, true> true_type;
	typedef _is_integral_base<bool, false> false_type;

	template< class T >
	struct is_integral : public false_type{};

	template< >
	struct is_integral< bool > : public true_type{};

	template< >
	struct is_integral< char > : public true_type{};

	template< >
	struct is_integral< wchar_t > : public true_type {};

	template< >
	struct is_integral< unsigned char > : public true_type {};

	template< >
	struct is_integral< short int > : public true_type {};

	template< >
	struct is_integral< int > : public true_type{};

	template< >
	struct is_integral< long int > : public true_type {};

	template< >
	struct is_integral< long long int > : public true_type {};

	template< >
	struct is_integral< unsigned short int > : public true_type {};

	template< >
	struct is_integral< unsigned int > : public true_type {};

	template< >
	struct is_integral< unsigned long int > : public true_type {};

	template< >
	struct is_integral< unsigned long long int > : public true_type {};

}
#endif