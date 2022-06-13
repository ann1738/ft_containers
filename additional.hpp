/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:08:35 by anasr             #+#    #+#             */
/*   Updated: 2022/06/13 18:25:03 by anasr            ###   ########.fr       */
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
	
	template< class InputIt1,
			class InputIt2,
			class BinaryPredicate >
	bool equal( InputIt1 first1,
				InputIt1 last1,
				InputIt2 first2,
				BinaryPredicate p );
}


#endif