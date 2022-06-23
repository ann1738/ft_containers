/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:49:21 by ann               #+#    #+#             */
/*   Updated: 2022/06/23 15:24:50 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <vector>
#include <map>
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
	std::map<int, std::string> firstMap;
	typedef std::allocator<int> Alloc;
	typedef Alloc::rebind<char>::other allocator_type;
	allocator_type A;
	A.allocate(1);

	firstMap[1] = "one";
	firstMap[2] = "two";
	firstMap.insert(std::make_pair(3, "three"));
	firstMap.insert(std::make_pair(-1, "minus one"));
	std::map<int, std::string>::iterator it = firstMap.begin();
	for(; it!=firstMap.end(); ++it){
  		std::cout << it->first << " => " << it->second << '\n';
	}	
	std::cout << it->first << " => " << it->second << '\n';
	++it;
	std::cout << it->first << " => " << it->second << '\n';

	#endif
}
