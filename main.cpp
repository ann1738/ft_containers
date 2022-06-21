/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:49:21 by ann               #+#    #+#             */
/*   Updated: 2022/06/21 13:26:38 by ann              ###   ########.fr       */
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

	my.insert(my.begin(), 5, 42);
	// sd.insert(sd.begin() + 4, 5, 42);
	ft::vector<int> comp1(my.begin(), my.end());

	for (ft::vector<int>::iterator it = comp1.begin(); it != comp1.end(); ++it)
		std::cout << *it << std::endl;	

	#endif
}
