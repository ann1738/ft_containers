/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:49:21 by ann               #+#    #+#             */
/*   Updated: 2022/06/21 09:11:43 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <vector>
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
	
	ft::vector<int> my;
	for (size_t i = 1; i < 4; ++i)
		my.push_back(i);
	// for (ft::vector<int>::iterator it = my.begin(); it != my.end(); ++it)
	// std::cout << *it << std::endl;	

	// my.insert(my.begin() + 4, 5, 42);
	// sd.insert(sd.begin() + 4, 5, 42);
	ft::vector<int> comp1(my.begin(), my.end());
	// ft::vector<int> comp2(10, 42);
std::vector<int> a;
	// if (comp1 > comp2)
	// 	std::cout << "TRUE" << std::endl;
	// else
	// 	std::cout << "FALSE" << std::endl;

	// std::cout << "*************************" << std::endl;
	for (ft::vector<int>::iterator it = comp1.begin(); it != comp1.end(); ++it)
		std::cout << *it << std::endl;	



	// std::cout << "HOWOW " << *my2.begin() << std::endl;
	// if (my2.begin() + 2 >= my2.begin() + 2)
	// 	std::cout << "TRUE\n";
	// else
	// 	std::cout << "FALSE\n";
	// std::vector<int> stdd;
	// stdd.push_back(1);
	// stdd.push_back(2);
	// stdd.push_back(3);
	// stdd.push_back(4);
	// stdd.push_back(5);

	#endif
}
