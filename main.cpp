/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:49:21 by ann               #+#    #+#             */
/*   Updated: 2022/08/24 15:29:39 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
// #include <vector>
// #include <map>

#include "shared.hpp"
#include "testing.hpp"
// # define ft std

/* DONT DELETE -> THIS IS THE MAIN TEST */
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;


	// #if TESTING_MODE
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
		case 1: //map
			test_map();
			break;
		case 2: //stack
			// test_stack();
			break;
		case 3: //vector
			//test_vector();
			break;
		default:
			std::cout << "\e[31mInvalid Input\e[0m" << std::endl
			<< "Valid inputs: \e[35m./main\t \e[33m\"vector\"\e[0m OR \e[33m\"map\"\e[0m OR \e[33m\"stack\"\e[0m OR \e[33m\"all\"\e[0m" << std::endl;
			break;
		}
		

		// std::vector<int>::iterator it;
		// it.base
		// std::map<int, char>::iterator it;
		// it.base();
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
}
// #endif