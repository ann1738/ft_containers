/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:08:35 by anasr             #+#    #+#             */
/*   Updated: 2022/06/14 17:14:47 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADDITIONAL_HPP
# define ADDITIONAL_HPP

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
}


#endif