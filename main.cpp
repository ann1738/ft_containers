/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:49:21 by ann               #+#    #+#             */
/*   Updated: 2022/06/19 18:14:56 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "vector.hpp"
#include <iostream>
#include <exception>

// #include "vector.hpp"
// #include "timer.hpp"
// #include "additional.hpp"
#include <vector>
// #include <iterator>
// #include <type_traits>

#include "shared.hpp"
#include "testing.hpp"


int main()
{
	#if TESTING_MODE
	{
		std::cout << "\e[33mElement access: \e[0m" << std::endl;
		vector_at();
		vector_subscript();
		vector_front();
		vector_back();
		vector_data();
		std::cout << "\n\e[33mCapacity: \e[0m" << std::endl;
		vector_empty();
		vector_size();
		// vector_max_size();
		vector_reserve();
		vector_capacity();
		std::cout << "\n\e[33mModifiers: \e[0m" << std::endl;
		vector_clear();
		// vector_insert();
		vector_erase();
	}
	#else
	
	// int i = 0;
	// std::cout << std::is_integral<int>::type << std::endl;
	std::cout <<  std::boolalpha <<  std::endl;
	std::cout << std::is_integral<ft::vector<int>::iterator>::value << std::endl;
	std::cout << "************************************************************\n";
	std::cout << ft::is_integral<ft::vector<int>::iterator>::value << std::endl;
	std::cout << ft::is_integral<ft::vector<int>::iterator>::value << std::endl;
	#endif
}
