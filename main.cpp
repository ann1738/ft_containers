/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:49:21 by ann               #+#    #+#             */
/*   Updated: 2022/06/27 16:42:09 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <vector>
#include <map>
#include "shared.hpp"
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
	ft::map<int,std::string>	my;
	my.insert(ft::make_pair(1, "first"));

	#endif
}
