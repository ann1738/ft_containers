/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:10:24 by ann               #+#    #+#             */
/*   Updated: 2022/08/24 16:11:51 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../testing.hpp"
#include <vector>
#include <string>
#include <list>
#include <algorithm>

#ifdef TESTING
# define ft std
#endif

// #ifdef SPEED
// # define
// #endif

#define NAMESPACE ft

template < class T >
void	printContainer(const T & container){
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << "\t";
	std::cout << std::endl;
}

template< class T >
static void	printVectorInfo(const T & contatiner){
	std::cout << "Size: " << contatiner.size() << std::endl;
	std::cout << "Capacity: " << contatiner.capacity() << std::endl;
	std::cout << "Max Size: " << contatiner.max_size() << std::endl;
	std::cout << "Content: " << std::endl;
	printContainer(contatiner);
}

static void	test_accuracy()
{
	{
		/*testing typenames*/
		std::cout << "********** Testing Typenames **********" << std::endl;
		ft::vector<int>::value_type a;
		ft::vector<int>::allocator_type b;
		ft::vector<int>::reference c = a;
		ft::vector<int>::const_reference d = a;
		ft::vector<int>::pointer e;
		ft::vector<int>::const_pointer f;
		ft::vector<int>::iterator g;
		ft::vector<int>::const_iterator h;
		ft::vector<int>::reverse_iterator i;
		ft::vector<int>::const_reverse_iterator j;
		ft::vector<int>::difference_type k;
		ft::vector<int>::size_type l;
		(void)a; (void)b; (void)c; (void)d; (void)e;
		(void)f; (void)g; (void)h; (void)i; (void)j;
		(void)k; (void)l;
	}

	{
		/*constructors, destructor, and copy assignemnt*/
		std::cout << "********** Testing constructors and copy assignment **********" << std::endl;
		ft::vector<int> vec;
		for (int i = 0; i < 100000; ++i) vec.push_back(i);
		printVectorInfo(vec);
		ft::vector<int> vec1(100000, 42);
		printVectorInfo(vec1);
		ft::vector<int> vec2(vec.begin(), vec.end());
		printVectorInfo(vec2);
		ft::vector<int> vec3(vec1);
		printVectorInfo(vec3);
		ft::vector<int> vec4;
		vec4 = vec3;
		printVectorInfo(vec4);

		ft::vector<std::string> vecStr;
		for (int i = 0; i < 100000; ++i) vecStr.push_back(std::to_string(i));
		printContainer(vecStr);
	}
	{
		/*iterators*/
		std::cout << "********** Testing Iterators: **********" << std::endl;
		ft::vector<std::string> vecStr;
		for (int i = 0; i < 10; ++i) vecStr.push_back(std::to_string(i));
	
		ft::vector<std::string>::iterator it = vecStr.begin();
		ft::vector<std::string>::iterator ite = vecStr.end();
		
		for (; it != ite; ++it) std::cout << *it << std::endl;
		it = vecStr.begin();
		ite--;
		for (; ite != it;  --ite) std::cout << *ite << std::endl;

		ft::vector<std::string>::reverse_iterator rit = vecStr.rbegin();
		ft::vector<std::string>::reverse_iterator rite = vecStr.rend();
		
		for (; rit != rite; ++rit) std::cout << *rit << std::endl;
		rit = vecStr.rbegin();
		rite--;
		for (; rite != rit;  --rite) std::cout << *rite << std::endl;

		/*relational operators for iterators*/
		it = vecStr.begin();
		ite = vecStr.end();

		std::cout << (it == ite) << std::endl;
		std::cout << (it != ite) << std::endl;
		std::cout << (it < ite) << std::endl;
		std::cout << (it <= ite) << std::endl;
		std::cout << (it > ite) << std::endl;
		std::cout << (it >= ite) << std::endl;

		/*relational operators between iterators and const_iterator*/
		ft::vector<std::string>::const_iterator cit = vecStr.begin();
		ft::vector<std::string>::const_iterator cite = vecStr.end();

		std::cout << (it == cite) << std::endl;
		std::cout << (it != cite) << std::endl;
		std::cout << (it < cite) << std::endl;
		std::cout << (it <= cite) << std::endl;
		std::cout << (it > cite) << std::endl;
		std::cout << (it >= cite) << std::endl;
	
		std::cout << (cit == ite) << std::endl;
		std::cout << (cit != ite) << std::endl;
		std::cout << (cit < ite) << std::endl;
		std::cout << (cit <= ite) << std::endl;
		std::cout << (cit > ite) << std::endl;
		std::cout << (cit >= ite) << std::endl;
	}
	{
		/*const_iterators*/
		std::cout << "********** Testing Const_iterators **********" << std::endl;
		const ft::vector<std::string> vecStr(10, "CONST");
	
		ft::vector<std::string>::const_iterator it = vecStr.begin();
		ft::vector<std::string>::const_iterator ite = vecStr.end();
		for (; it != ite; ++it) std::cout << *it << std::endl;
		it = vecStr.begin();
		ite--;
		for (; ite != it;  --ite) std::cout << *ite << std::endl;

		ft::vector<std::string>::const_reverse_iterator rit = vecStr.rbegin();
		ft::vector<std::string>::const_reverse_iterator rite = vecStr.rend();
		
		for (; rit != rite; ++rit) std::cout << *rit << std::endl;
		rit = vecStr.rbegin();
		rite--;
		for (; rite != rit;  --rite) std::cout << *rite << std::endl;

		/*relational operators for const iterators*/
		it = vecStr.begin();
		ite = vecStr.end();

		std::cout << (it == ite) << std::endl;
		std::cout << (it != ite) << std::endl;
		std::cout << (it < ite) << std::endl;
		std::cout << (it <= ite) << std::endl;
		std::cout << (it > ite) << std::endl;
		std::cout << (it >= ite) << std::endl;
	}
	{
		/*Capacity functions*/
		std::cout << "********** Testing Capacity Functions **********" << std::endl;
		{
			/*resize*/
			std::cout << "# resize() #" << std::endl;
			ft::vector<int> vec(100000, 42);
			printVectorInfo(vec);
			vec.resize(1, 42);
			printVectorInfo(vec);
			vec.resize(100001, 42);
			printVectorInfo(vec);
			vec.resize(100005, 42);
			printVectorInfo(vec);
			vec.resize(0, 42);
			printVectorInfo(vec);
			vec.resize(300005, 42);
			printVectorInfo(vec);
		}
		{
			/*empty*/
			std::cout << "# empty() #" << std::endl;
			ft::vector<int> vec;
			std::cout << vec.empty() << std::endl;
			vec.push_back(424242);
			std::cout << vec.empty() << std::endl;
			vec.clear();
			std::cout << vec.empty() << std::endl;
		}
		{
			/*reserve*/
			std::cout << "# reserve() #" << std::endl;
			ft::vector<int> vec;
			vec.reserve(1);
			printVectorInfo(vec);
			vec.reserve(0);
			printVectorInfo(vec);
			vec.reserve(100000);
			printVectorInfo(vec);
			vec.reserve(10);
			printVectorInfo(vec);
			// try
			// {
			// 	vec.reserve(4611686018427387904);
			// }
			// catch (std::exception & e){
			// 	std::cout << e.what() << std::endl;
			// }
		}
	}
	{
		/*Element access*/
		std::cout << "********** Testing Element access: **********" << std::endl;
		ft::vector<int> vec;
		for (int i = 0; i < 100000; ++i) vec.push_back(i);
		std::cout << vec.front() << std::endl;
		std::cout << vec.back() << std::endl;
		for (ft::vector<int>::size_type i = 0; i < vec.size(); ++i) std::cout << vec[i] << "&" << vec.at(i) << " - ";
		std::cout << std::endl;
		try
		{
			std::cout << vec.at(100001) << std::endl;
		}
		catch (std::exception & e){
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << vec.at(-1) << std::endl;
		}
		catch (std::exception & e){
			std::cout << e.what() << std::endl;
		}
		vec.pop_back();
		vec.erase(vec.begin());
		std::cout << vec.front() << std::endl;
		std::cout << vec.back() << std::endl;
	}
	{
		/*Modifiers*/
		std::cout << "********** Testing Modifiers: **********" << std::endl;
		{
			/*assign*/
			std::cout << "# assign() #" << std::endl;
			ft::vector<int> vec;
			vec.assign(10000, 42);
			printVectorInfo(vec);
			vec.assign(10, 42);
			printVectorInfo(vec);
			vec.assign(0, 42);
			printVectorInfo(vec);
			vec.assign(100000, 42);
			printVectorInfo(vec);
			vec.assign(100001, 42);
			printVectorInfo(vec);
			std::list<int> myNameIsListy(1000, 1337);
			vec.assign(myNameIsListy.begin(), myNameIsListy.end());
			printVectorInfo(vec);
		}
		{
			/*push_back, pop_back*/
			std::cout << "# push_back() and pop_back() #" << std::endl;
			ft::vector<std::string> vecStr;
			printContainer(vecStr);
			vecStr.push_back("FIRST");
			printContainer(vecStr);
			vecStr.push_back("SECOND");
			for (int i = 0; i < 100000; ++i) 
			{
				std::cout << vecStr.capacity() << "*" << vecStr.size() << " - ";
				vecStr.push_back(std::to_string(i));
			}
			std::cout << std::endl;
			printContainer(vecStr);
			for (; !vecStr.empty();) 
			{
				std::cout << vecStr.capacity() << "*" << vecStr.size() << " - ";
				vecStr.pop_back();
			}
			std::cout << std::endl;
			printContainer(vecStr);
		}
		{
			/*insert, */
			std::cout << "# insert() #" << std::endl;
			ft::vector<int> vec;
			for (int i = 0; i < 10000; ++i) vec.push_back(i);
			vec.insert(vec.begin(), 4242);
			vec.insert(vec.end() - 1, 4242);
			printContainer(vec);	
			vec.insert(vec.begin() + 1000, 4242);
			vec.insert(vec.begin() + 5000, 4242);
			vec.insert(vec.begin() + 7000, 4242);
			vec.insert(vec.begin() + 9000, 4242);
			printContainer(vec);
			
			vec.insert(vec.begin(), 5, 4242);
			vec.insert(vec.end() - 1, 5, 4242);
			printContainer(vec);
			vec.insert(vec.begin() + 500, 0, 4242);
			vec.insert(vec.begin() + 500, 5, 4242);
			vec.insert(vec.begin() + 1500, 5, 4242);
			vec.insert(vec.begin() + 2500, 5, 4242);
			vec.insert(vec.begin() + 4500, 5, 4242);
			vec.insert(vec.begin() + 5500, 5, 4242);
			vec.insert(vec.begin() + 6500, 5, 4242);
			vec.insert(vec.begin() + 7500, 5, 4242);
			vec.insert(vec.begin() + 8500, 5, 4242);
			vec.insert(vec.begin() + 9500, 5, 4242);
			printContainer(vec);

			std::list<int> myNameIsListy(1000, 1337);
		
			vec.insert(vec.begin(), myNameIsListy.begin(), myNameIsListy.end());
			vec.insert(vec.end() - 1, myNameIsListy.begin(), myNameIsListy.end());
			printContainer(vec);
			

			myNameIsListy.clear();
			myNameIsListy.assign(50, 1337);
			vec.insert(vec.begin() + 750, myNameIsListy.begin(), myNameIsListy.end());
			vec.insert(vec.begin() + 1750, myNameIsListy.begin(), myNameIsListy.end());
			vec.insert(vec.begin() + 2750, myNameIsListy.begin(), myNameIsListy.end());
			vec.insert(vec.begin() + 3750, myNameIsListy.begin(), myNameIsListy.end());
			vec.insert(vec.begin() + 4750, myNameIsListy.begin(), myNameIsListy.end());
			vec.insert(vec.begin() + 5750, myNameIsListy.begin(), myNameIsListy.end());
			vec.insert(vec.begin() + 6750, myNameIsListy.begin(), myNameIsListy.end());
			vec.insert(vec.begin() + 7750, myNameIsListy.begin(), myNameIsListy.end());
			vec.insert(vec.begin() + 8750, myNameIsListy.begin(), myNameIsListy.end());
			vec.insert(vec.begin() + 9750, myNameIsListy.begin(), myNameIsListy.end());
			printContainer(vec);
		
			/*erase*/
			std::cout << "# erase() #" << std::endl;
			vec.erase(vec.begin());
			vec.erase(vec.end() - 1);
			printContainer(vec);
			
			vec.erase(vec.begin() + 4);
			vec.erase(vec.begin() + 44);
			vec.erase(vec.begin() + 444);
			vec.erase(vec.begin() + 4444);
			printContainer(vec);
			
			vec.erase(vec.begin(), vec.begin() + 25);
			vec.erase(vec.begin() + 500, vec.begin() + 575);
			vec.erase(vec.begin() + 5000, vec.begin() + 5750);
			vec.erase(vec.begin() + 9000, vec.begin() + 9125);
			printContainer(vec);
			
			vec.erase(vec.begin(), vec.end());
			printContainer(vec);
		}
		{
			/*swap, clear*/
			std::cout << "# swap() and clear() #" << std::endl;
			ft::vector<std::string> vecA(999, "A");
			ft::vector<std::string> vecB(9999, "BB");
			
			ft::vector<std::string>::iterator itOldA = vecA.begin();
			ft::vector<std::string>::iterator iteOldA = vecA.end();
			ft::vector<std::string>::iterator itOldB = vecB.begin();
			ft::vector<std::string>::iterator iteOldB = vecB.end();

			vecA.swap(vecB);
			printContainer(vecA);
			printContainer(vecB);
			
			std::cout << "Checking iterator validity:" << std::endl;
			std::cout << (itOldA == vecB.begin()) << std::endl;
			std::cout << (iteOldA == vecB.end()) << std::endl;
			std::cout << (itOldB == vecA.begin()) << std::endl;
			std::cout << (iteOldB == vecA.end()) << std::endl;

			vecA.clear();
			printContainer(vecA);
			vecB.clear();
			printContainer(vecB);
		}
		{
			/*get_allocator*/
			std::cout << "# get_allocator() #" << std::endl;
			ft::vector<int> vec;

			int *ptr = vec.get_allocator().allocate(1000);

			for (int i = 0; i < 1000; ++i) vec.get_allocator().construct(ptr + i, i);

			for (int i = 0; i < 1000; ++i) std::cout << ptr[i] << " - ";
			std::cout << std::endl;

			for (int i = 0; i < 1000; ++i) vec.get_allocator().destroy(ptr + i);
			vec.get_allocator().deallocate(ptr, 1000);
		}
		{
			/*relational operators*/
			std::cout << "# relational operators #" << std::endl;
			ft::vector<int> vecA(10, 42);
			ft::vector<int> vecB(10, 1337);

			std::cout << (vecA == vecB) << std::endl;
			std::cout << (vecA != vecB) << std::endl;
			std::cout << (vecA < vecB) << std::endl;
			std::cout << (vecA <= vecB) << std::endl;
			std::cout << (vecA > vecB) << std::endl;
			std::cout << (vecA >= vecB) << std::endl;

			/*std::swap specialization*/
			std::cout << "# std::swap specialization #" << std::endl;
			std::swap(vecA, vecB);
			printVectorInfo(vecA);
			printVectorInfo(vecB);
		}
	}
}

static void	test_performance()
{
	int amount = 100000000;
	std::cout << "\e[34mInsertion: (" << amount << " elements)\e[0m" << std::endl;
	std::cout << "ft::vector:" << std::endl;
	std::cout << "Insertion: ";
	timer *T1 = new timer();
	ft::vector<int> mine;
	for (int i = 0; i < amount; ++i) mine.push_back(i);
	delete T1;

	std::cout << "Searching: ";
	timer *T2 = new timer();
	ft::find(mine.begin(), mine.end(), amount / 10);
	ft::find(mine.begin(), mine.end(), amount / 7);
	ft::find(mine.begin(), mine.end(), amount / 5);
	ft::find(mine.begin(), mine.end(), amount / 3);
	ft::find(mine.begin(), mine.end(), amount / 1);
	delete T2;
	
	std::cout << "Deletion: ";
	// timer *T3 = new timer();
	timer T4;
	mine.erase(mine.begin(), mine.end());
	// delete T3;
}

void	test_vector()
{
	#ifndef SPEED
		test_accuracy();
	#else
		test_performance();
	#endif
	(void)(test_performance);
}
