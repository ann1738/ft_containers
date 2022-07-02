/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:49:21 by ann               #+#    #+#             */
/*   Updated: 2022/07/02 14:14:08 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <vector>
#include <stack>
#include <map>
#include "shared.hpp"
#include "testing.hpp"

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
std::map<int, std::string>::value_compare haha;

	ft::map<std::string,int> mymap;

	try{	
		mymap["alpha"];
		mymap["beta"];
		mymap["gamma"];
		mymap.at("alpha1") = 10;
		mymap.at("beta") = 20;
		mymap.at("gamma") = 30;
	}catch (std::exception & e){std::cerr << e.what() << std::endl;}

	#endif
}
