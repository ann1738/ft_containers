/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:49:21 by ann               #+#    #+#             */
/*   Updated: 2022/07/15 16:35:10 by ann              ###   ########.fr       */
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

#include "tests/tests.hpp"
// #ifdef STRD
// # define ft std
// #endif
int main(int argc, char **argv)
{
	#if TESTING_MODE
	{
		if (argc != 2)
		{
			std::cout << "\e[31mInvalid Input\e[0m" << std::endl
			<< "Valid inputs: \e[35m./main\t \e[33m\"vector\"\e[0m OR \e[33m\"map\"\e[0m OR \e[33m\"stack\"\e[0m OR \e[33m\"all\"\e[0m" << std::endl;
			return 1;
		}
		std::string possible[] = {"vector", "map", "stack", "all"};
		int	test_index = 0;
		for (; test_index < 4 && argv[1] != possible[test_index]; ++test_index);
		switch (test_index)
		{
		case 0: //vector
			test_vector();
			break;
		case 1: //vector
			//test_vector();
			break;
		case 2: //stack
			test_stack();
			break;
		case 3: //vector
			//test_vector();
			break;
		default:
			std::cout << "\e[31mInvalid Input\e[0m" << std::endl
			<< "Valid inputs: \e[35m./main\t \e[33m\"vector\"\e[0m OR \e[33m\"map\"\e[0m OR \e[33m\"stack\"\e[0m OR \e[33m\"all\"\e[0m" << std::endl;
			break;
		}
		// test_stack(); 
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
		(void)argc;
		(void)argv;
		ft::vector<int> mine;
		mine.reserve(10);
		std::vector<int> strd;
		strd.reserve(10);

		for (int i = 0; i < 10; ++i)
		{
			mine.push_back(i);
			strd.push_back(i);
		}
	
		ft::vector<int> mineIns(3, 42);
		std::vector<int> strdIns(3, 42);

		mineIns.insert(mineIns.begin() + 1, mine.begin(), mine.begin() + 3);
		// strdIns.insert(strdIns.begin() + 1, strd.begin(), strd.begin() + 3);
		std::cout << "?\n";

		for (ft::vector<int>::iterator it = mineIns.begin(); it != mineIns.end(); ++it)
			std::cout << *it << std::endl;
		
	#endif
}
