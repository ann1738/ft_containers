/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:49:21 by ann               #+#    #+#             */
/*   Updated: 2022/06/20 18:19:51 by anasr            ###   ########.fr       */
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
// using ft = std;

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
	
	ft::vector<int> my(10, 42);

	ft::vector<int>::iterator it = my.begin();
	// ft::vector<int>::iterator nit = my.begin();
	// nit++;
	// it++;
	// assert(it == nit);
	// assert(++it == ++nit);
	// it--;
	// nit--;
	// assert(it == nit);
	// assert(--it == --nit);

	// assert(it != nit + 1);
	// assert(it < nit + 1);
	// assert(it <= nit + 1);
	// assert(it + 2 > nit + 1);
	// assert(it + 2 > nit + 1);
	
	assert(static_cast<size_t>(my.end() - my.begin()) == my.size());
	*it = 1;
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
