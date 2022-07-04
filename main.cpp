/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:49:21 by ann               #+#    #+#             */
/*   Updated: 2022/07/04 17:50:01 by anasr            ###   ########.fr       */
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
	std::map<int, std::string> haha;
	
	// for (int i = 0; i < 10; ++i) haha[i] = "hehe";
	// haha.erase(haha.end());
	// for (std::map<int, std::string>::iterator it = haha.begin(); it != haha.end(); ++it) haha.erase(haha.begin());
	// for (std::map<int, std::string>::iterator it = haha.begin(); it != haha.end(); ++it) std::cout << it->first << " = " << it->second << std::endl;

	
	ft::map<int, std::string> m;
	// m[1] = "one";	
	// m[2] = "one";	
	// m[3] = "one";	
	// m[-1] = "one";
	// m[-50] = "one";
	// m[-123] = "oneeee";
	// m[-5] = "one";
	// m[51] = "one";
	
	// srand(time(0));
	// {		
	// 	timer T1;
	// 	for (int i = 0; i < 10; ++i) m[rand()];
	// }

	// {		
	// 	timer T1;
	// 	for (int i = 0; i < 10000000; ++i) haha[rand()];
	// }

		timer T1;
	m[10]; m[5]; m[20]; m[3]; m[22];
		// for (int i = 0; i < 10; ++i) haha[rand()];
	m.erase(22);
	// m.erase(5);
	// m.erase(m.begin(), --m.end());
	// std::cout << "\e[35m" << m.erase(12) << "\e[0m\n";
	// std::cout << "\e[35m" << m.erase(2) << "\e[0m\n";
	// std::cout << "\e[35m" << m.erase(3) << "\e[0m\n";
	for (ft::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it) 
		std::cout << it->first << " = " << it->second << "\twith height\t" << m.pubGetHeight(it->first) <<  std::endl;
	#endif
}
