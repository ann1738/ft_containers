/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:52:38 by ann               #+#    #+#             */
/*   Updated: 2022/07/20 15:54:47 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../testing.hpp"
#include <map>
#include <algorithm>
#include <utility>

static void	test_performance()
{
	int amount = 1000000;
	std::cout << "\e[34mInsertion: (" << amount << " elements)\e[0m" << std::endl;
	{
		std::cout << "ft::map:" << std::endl;
		std::cout << "Insertion: ";
		timer *T1 = new timer();
		ft::map<int, std::string> mine;
		for (int i = 0; i < amount; ++i)
			mine.insert(ft::make_pair<int, std::string>(i, "one"));
		delete T1;

		std::cout << "Searching: ";
		timer *T2 = new timer();
		mine.find(amount / 10);
		mine.find(amount / 7);
		mine.find(amount / 5);
		mine.find(amount / 3);
		mine.find(amount / 1);
		delete T2;
		
		std::cout << "Deletion: ";
		timer *T3 = new timer();
		// timer T4;
		mine.erase(mine.begin(), mine.end());
		delete T3;
		
	}
	{
		std::cout << "std::map:" << std::endl;
		std::cout << "Insertion: ";
		timer *T1 = new timer();
		std::map<int, std::string> mine;
		for (int i = 0; i < amount; ++i)
			mine.insert(std::make_pair<int, std::string>(i, "one"));
		delete T1;


		std::cout << "Searching: ";
		timer *T2 = new timer();
		mine.find(amount / 10);
		mine.find(amount / 7);
		mine.find(amount / 5);
		mine.find(amount / 3);
		mine.find(amount / 1);
		delete T2;
		

		std::cout << "Deletion: ";
		// timer T4;
		timer *T3 = new timer();
		mine.erase(mine.begin(), mine.end());
		delete T3;

	}
}

void	test_map()
{
	test_performance();
}