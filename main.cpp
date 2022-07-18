/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:49:21 by ann               #+#    #+#             */
/*   Updated: 2022/07/18 19:15:30 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <vector>
// #include <stack>
// #include <map>
#include "shared.hpp"
#include "testing.hpp"
// #include <cstdlib>

#include "tests/tests.hpp"
// #ifdef STRD
// #endif
	// # define TESTED_TYPE int
	// # define TESTED_NAMESPACE ft
	# include <list>


// # define ft std
# define TESTED_TYPE std::string
# define TESTED_NAMESPACE ft
#define DEGUB() (std::cout << "\e[33mDEBUGGING\e[0m\n")


void	printSize(const TESTED_NAMESPACE::vector<TESTED_TYPE> & cont)
{
	std::cout << "Size is " << cont.size() << std::endl; 
	std::cout << "Capacity is " << cont.capacity() << std::endl;
	std::cout << "content is " << std::endl;
	for (TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator it = cont.begin(); it != cont.end(); ++it)
		std::cout << *it << std::endl;
}


void	checkErase(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct,
					TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator const &it)
{
	static int i = 0;
	std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
	printSize(vct);
}

int main(int argc, char **argv)
{
	#if TESTING_MODE
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
		case 1: //vector
			//test_vector();
			break;
		case 2: //stack
			test_stack();
			break;
		case 3: //vector
			//test_vector();
			break;
		default:
			std::cout << "\e[31mInvalid Input\e[0m" << std::endl
			<< "Valid inputs: \e[35m./main\t \e[33m\"vector\"\e[0m OR \e[33m\"map\"\e[0m OR \e[33m\"stack\"\e[0m OR \e[33m\"all\"\e[0m" << std::endl;
			break;
		}
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
	#else

	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(5);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
	const int cut = 3;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 7;
	printSize(vct);

	vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
	printSize(vct2);
	vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
	printSize(vct2);
	vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
	printSize(vct2);

	std::cout << "insert return:" << std::endl;

	std::cout << *vct2.insert(vct2.end(), 42) << std::endl;
	std::cout << *vct2.insert(vct2.begin() + 5, 84) << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	printSize(vct2);
		(void)argc;
		(void)argv;

	#endif
}
