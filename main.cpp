/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:49:21 by ann               #+#    #+#             */
/*   Updated: 2022/06/13 19:30:48 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "vector.hpp"
#include <iostream>
#include <exception>
// #include <vector>
#include <string>

#include "vector.hpp"
#include "timer.hpp"
#include "additional.hpp"
#include <vector>
int main()
{
	// {
	// 	timer t1;
	// 	std::vector<int> stand(1, 1);
	// 	for (int i = 0; i < 10000; ++i)
	// 		stand.push_back(2);
	// 	for (std::vector<int>::iterator it = stand.begin(); it != stand.end(); ++it)
	// 		std::cout << *it << std::endl;
	// 	stand.erase(stand.begin() + 1);
	// }
	// std::cout << "*************************" << std::endl;
	// {
	// 	timer t1;
	// 	ft::vector<int> stand(1, 1);
	// 	for (int i = 2; i < 10; ++i)
	// 		stand.push_back(i);

	// 	ft::vector<int>::iterator it = stand.begin();
	// 	ft::vector<int>::iterator ite = stand.end();
	// 	for (; it != ite; ++it)
	// 	{
	// 		std::cout << *it << std::endl;
	// 	}
	// 	std::cout << "#########################" << std::endl;
	// 	// stand.clear();
	// 	// stand.erase(stand.begin() + 1, stand.begin() + 3);
	// 	stand.insert(stand.begin() + 1, 5, 42);
	// 	ft::vector<int>::iterator it1 = stand.begin();
	// 	ft::vector<int>::iterator ite1 = stand.end();
	// 	for (; it1 != ite1; ++it1)
	// 	{
	// 		std::cout << *it1 << std::endl;
	// 	}
	// 	std::cout << "#########################" << std::endl;
	// 	std::cout << stand.size() << std::endl;
		
	// 	ft::vector<int> copy(10, 1337);
		
	// 	// copy = stand;
	// 	copy.swap(stand);
	// 	std::cout << "\e[31mAFTER SWAPPING\e[0m\n" << std::endl;
	// 	std::cout << "stand" << std::endl;
	// 	for (ft::vector<int>::iterator itt = stand.begin(); itt != stand.end(); ++itt)
	// 		std::cout << *itt << std::endl;
	// 	std::cout << "SIZE is " << stand.size() << std::endl;
	// 	std::cout << "#########################" << std::endl;
		
	// 	std::cout << "\ncopy" << std::endl;
	// 	for (ft::vector<int>::iterator itt = copy.begin(); itt != copy.end(); ++itt)
	// 		std::cout << *itt << std::endl;
	// 	std::cout << "SIZE is " << copy.size() << std::endl;
	// }
	// {
	// 	std::cout << "MINE\n";
	// 	ft::vector<int> a(100, 1337);
	// 	ft::vector<int> b(10, 1337);
	// 	if (ft::equal(a.begin(), a.begin() + 10, b.begin()))
	// 		std::cout << "\e[32mEQUAL\e[0m" << std::endl;
	// 	else
	// 		std::cout << "\e[31mNOT EQUAL\e[0m" << std::endl;
	// }
	// {
	// 	std::cout << "THEIRS\n";
	// 	std::vector<int> a(100, 1337);
	// 	std::vector<int> b(10, 1337);
	// 	if (std::equal(a.begin(), a.begin() + 10, b.begin()))
	// 		std::cout << "\e[32mEQUAL\e[0m" << std::endl;
	// 	else
	// 		std::cout << "\e[31mNOT EQUAL\e[0m" << std::endl;
	// }
	// std::cout << "#########################" << std::endl;
	{
		// std::vector<int> a(10, 420);
		// std::vector<int> b(10, 420);
		std::string a("Heyyyy");
		std::string b("heyyyy");
		if (std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end()))
			std::cout << "a is less\n";
		else
			std::cout << "a is greater or equal\n";
		if (std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end())
			== ft::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end()))
			std::cout << "\e[32mCORRECT\e[0m\n";
		else
			std::cout << "\e[31mINCORRECT\e[0m\n";
	}
}
