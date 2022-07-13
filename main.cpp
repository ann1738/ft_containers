/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:49:21 by ann               #+#    #+#             */
/*   Updated: 2022/07/13 09:25:30 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <vector>
#include <stack>
#include <map>
#include "shared.hpp"
#include "testing.hpp"
#include <cstdlib>

// #include "tests/tests.hpp"
// #ifdef STRD
# define ft std
// #endif
int main()
{
	#if TESTING_MODE
	{

		test_stack(); 
		// std::cout << "\e[33mElement access: \e[0m" << std::endl;
		// vector_at();
		// vector_subscript();
		// vector_front();
		// vector_back();
		// vector_data();
		// std::cout << "\n\e[33mCapacity: \e[0m" << std::endl;
		// vector_empty();
		// vector_size();
		// // vector_max_size();
		// vector_reserve();
		// vector_capacity();
		// std::cout << "\n\e[33mModifiers: \e[0m" << std::endl;
		// vector_clear();
		// // vector_insert();
		// vector_erase();
		
	}
	#else
	ft::map<int, char> my;
	my[1] = 'a';
	my[2] = 'b';
	my[3] = 'c';
	my[4] = 'd';

	
	ft::map<int, char>::iterator it = my.begin();
	ft::map<int, char>::iterator ite = my.end();
	ite--;
	ite++;
	for (; it != ite; ++it) std::cout << it->first << std::endl;

	// ft::map<int, char>::reverse_iterator rit = my.rbegin();
	// ft::map<int, char>::reverse_iterator rite = --my.rend() ;
	
	// for (; rit != rite; ++rit) std::cout << rit->first << std::endl;
	#endif
}
