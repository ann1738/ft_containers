/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:52:38 by ann               #+#    #+#             */
/*   Updated: 2022/08/24 16:47:41 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../testing.hpp"
#include <map>
#include <list>
#include <sstream>
#include <algorithm>
#include <utility>

#ifdef TESTING
# define ft std
#endif

static std::string	to_string(int _n){
	std::stringstream s;
	s << _n;
	return s.str();
}

template < class T >
void	printContainer(const T & container){
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << it->first << "->" << it->second << "\t";
	std::cout << std::endl;
}

template< class T >
static void	printMapInfo(const T & contatiner){
	std::cout << "Size: " << contatiner.size() << std::endl;
	std::cout << "Max Size: " << contatiner.max_size() << std::endl;
	std::cout << "Content: " << std::endl;
	printContainer(contatiner);
}

static void	test_performance()
{
	int amount = 100000;
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

void	test_accuracy()
{
	{
		/*testing typenames*/
		std::cout << "********** Testing Typenames **********" << std::endl;
		ft::map<int, std::string>::key_type a;
		ft::map<int, std::string>::mapped_type b;
		ft::map<int, std::string>::value_type c;
		ft::map<int, std::string>::key_compare d;
		ft::map<int, std::string>::allocator_type e;
		ft::map<int, std::string>::reference f = c;
		ft::map<int, std::string>::const_reference g = c;
		ft::map<int, std::string>::pointer h = NULL;
		ft::map<int, std::string>::const_pointer i = h;
		ft::map<int, std::string>::iterator j;
		ft::map<int, std::string>::const_iterator k;
		ft::map<int, std::string>::reverse_iterator l;
		ft::map<int, std::string>::const_reverse_iterator m;
		ft::map<int, std::string>::difference_type n;
		ft::map<int, std::string>::size_type o;
		(void)a; (void)b; (void)c; (void)d; (void)e;
		(void)f; (void)g; (void)h; (void)i; (void)j;
		(void)k; (void)l; (void)m; (void)n; (void)o;
	}
	{
		/*constructors, copy assignment, and destructor*/
		std::cout << "********** Testing constructors and copy assignment **********" << std::endl;
		ft::map<int, std::string> mp;
		for (int i = 0; i < 10000; ++i) mp.insert(ft::make_pair(i, "HELLO, WORLD!"));
		printMapInfo(mp);
		ft::map<int, std::string> mp1(mp.begin(), mp.end());
		printMapInfo(mp1);
		ft::map<int, std::string> mp2(mp);
		printMapInfo(mp2);
		ft::map<int, std::string> mp3;
		mp3 = mp2;
		printMapInfo(mp3);
	}
	{
		/*iterators*/
		std::cout << "********** Testing Iterators: **********" << std::endl;
		ft::map<int, std::string> mp;
		for (int i = 0; i < 10000; ++i) mp.insert(ft::make_pair(i, "HELLO, WORLD!"));
		ft::map<int, std::string>::iterator it = mp.begin();
		ft::map<int, std::string>::iterator ite = mp.end();
		
		for (; it != ite; ++it) std::cout << it->first << "->" << it->second << " - ";
		std::cout << std::endl;
		
		it = mp.begin();
		ite--;
		for (; ite != it; --ite) std::cout << ite->first << "->" << ite->second  << " - ";
		std::cout << std::endl;
		
		ft::map<int, std::string>::reverse_iterator rit = mp.rbegin();
		ft::map<int, std::string>::reverse_iterator rite = mp.rend();

		for (; rit != rite; ++rit) std::cout << rit->first << "->" << rit->second  << " - ";
		std::cout << std::endl;

		rit = mp.rbegin();
		rite--;
		for (; rite != rit; --rite) std::cout << ite->first << "->" << ite->second  << " - ";
		std::cout << std::endl;
		
		/*relational operators for iterators*/
		it = mp.begin();
		ite = mp.end();

		std::cout << (it == ite) << std::endl;
		std::cout << (it != ite) << std::endl;
		
		/*relational operators for iterators*/
		ft::map<int, std::string>::const_iterator cit = mp.begin();
		ft::map<int, std::string>::const_iterator cite = mp.end();

		std::cout << (it == cite) << std::endl;
		std::cout << (it != cite) << std::endl;

		std::cout << (cit == ite) << std::endl;
		std::cout << (cit != ite) << std::endl;
	}
	{
		/*const_iterators*/
		std::cout << "********** Testing Const_iterators: **********" << std::endl;
		
		ft::map<int, std::string> copyFromMe;
		for (int i = 0; i < 10000; ++i) copyFromMe.insert(ft::make_pair(i, "HELLO, WORLD!"));
		
		const ft::map<int, std::string> mp(copyFromMe.begin(), copyFromMe.end());
		
		ft::map<int, std::string>::const_iterator it = mp.begin();
		ft::map<int, std::string>::const_iterator ite = mp.end();
		
		for (; it != ite; ++it) std::cout << it->first << "->" << it->second << " - ";
		std::cout << std::endl;
		
		it = mp.begin();
		ite--;
		for (; ite != it; --ite) std::cout << ite->first << "->" << ite->second  << " - ";
		std::cout << std::endl;
		
		ft::map<int, std::string>::const_reverse_iterator rit = mp.rbegin();
		ft::map<int, std::string>::const_reverse_iterator rite = mp.rend();

		for (; rit != rite; ++rit) std::cout << rit->first << "->" << rit->second  << " - ";
		std::cout << std::endl;

		rit = mp.rbegin();
		rite--;
		for (; rite != rit; --rite) std::cout << ite->first << "->" << ite->second  << " - ";
		std::cout << std::endl;
		
		/*relational operators for const_iterators*/
		it = mp.begin();
		ite = mp.end();

		std::cout << (it == ite) << std::endl;
		std::cout << (it != ite) << std::endl;
	}
	{
		/*empty*/
		std::cout << "********** Testing empty(): **********" << std::endl;
		ft::map<int, std::string> mp;
		std::cout << mp.empty() << std::endl;
		mp.insert(ft::make_pair(42, "HELLO"));
		std::cout << mp.empty() << std::endl;
		mp.clear();
		std::cout << mp.empty() << std::endl;
	}
	{
		/*Element Access*/
		std::cout << "********** Testing operator[]: **********" << std::endl;
		ft::map<int, std::string> mp;
		for (int i = 0; i < 100; ++i) mp.insert(ft::make_pair(i, "HELLO, WORLD!"));
		printMapInfo(mp);
		/*existing keys*/
		mp[1] = "One";
		printMapInfo(mp);
		mp[70] = "Seventy";
		printMapInfo(mp);
		mp[0] = "Zero";
		printMapInfo(mp);
		mp[99] = "Ninety Nine";
		printMapInfo(mp);

		/*new keys*/
		mp[-1] = "Negative One";
		printMapInfo(mp);
		mp[-70] = "Negative Seventy";
		printMapInfo(mp);
		mp[1000000] = "One Million";
		printMapInfo(mp);
		mp[-99] = "Negative Ninety Nine";
		printMapInfo(mp);
	}
	{
		/*Modifiers*/
		std::cout << "********** Testing Modifiers: **********" << std::endl;
		{
			/*insert*/
			std::cout << "# insert() #" << std::endl;
			ft::map<std::string, int> mp;
			/*first type*/
			for (int i = 0; i < 10000; ++i)
				mp.insert(ft::make_pair(::to_string(i), i));
			printMapInfo(mp);
			std::cout << (mp.insert(ft::make_pair(::to_string(0), 0)).first->second) << std::endl;
			std::cout << (mp.insert(ft::make_pair(::to_string(0), 0)).second) << std::endl;
			std::cout << (mp.insert(ft::make_pair(::to_string(1000), 1000)).first->second) << std::endl;
			std::cout << (mp.insert(ft::make_pair(::to_string(1000), 1000)).second) << std::endl;
			std::cout << (mp.insert(ft::make_pair(::to_string(10000), 10000)).second) << std::endl;
			printMapInfo(mp);

			/*second type (with hint)*/
			std::cout << mp.insert(mp.end(), ft::make_pair(::to_string(10001), 10001))->second << std::endl;
			std::cout << mp.insert(mp.end(), ft::make_pair(::to_string(10000), 10000))->second << std::endl;
			std::cout << mp.insert(mp.end(), ft::make_pair(::to_string(9000), 9000))->second << std::endl;
			std::cout << mp.insert(mp.end(), ft::make_pair(::to_string(5000), 9000))->second << std::endl;
			printMapInfo(mp);

			/*third type (range)*/
			std::list< ft::pair<std::string, int> > myNameIsListy;
			for (int i = 50000; i < 55000; ++i)
				myNameIsListy.push_back(ft::make_pair(::to_string(i), i));
			
			mp.insert(myNameIsListy.begin(), myNameIsListy.end());
			printMapInfo(mp);

			/*erase*/
			std::cout << "# erase() #" << std::endl;

			/*first type (with position)*/
			ft::map<std::string, int>::iterator it = mp.begin();
			for (int i = 0; i < 1000; ++i, ++it)
			{
				it = mp.begin();
				mp.erase(it); //invalidates iterator
				if (i % 100 == 0)
					printMapInfo(mp);
			}

			/*second type (with key)*/
			for (int i = 49950; i < 55050; ++i)
			{
				std::cout << mp.erase(::to_string(i)) << " - ";
				if (i % 1000 == 0)
					printMapInfo(mp);
			}
			std::cout << std::endl;

			/*third type (range)*/
			ft::map<std::string, int>::iterator rangeIte = mp.begin();
			
			for (int i = 0; i < 10; ++i)
			{
				rangeIte = mp.begin();
				for (int i = 0; i < 500; ++i, ++rangeIte);
				mp.erase(mp.begin(), rangeIte);
				printMapInfo(mp);
			}
			mp.erase(mp.begin(), mp.end());
			printMapInfo(mp);
		}
		{
			/*swap*/
			std::cout << "# swap() #" << std::endl;
			ft::map<int, char> mpA;
			for (int i = 0; i < 4242; ++i)
				mpA.insert(ft::make_pair(i, 'A'));
			ft::map<int, char> mpB;
			for (int i = 0; i < 464; ++i)
				mpA.insert(ft::make_pair(i, 'B'));
			ft::map<int, char>::iterator OldItA = mpA.begin();
			ft::map<int, char>::iterator OldIteA = mpA.end();
			ft::map<int, char>::iterator OldItB = mpB.begin();
			ft::map<int, char>::iterator OldIteB = mpB.end();
			
			mpA.swap(mpB);
			printMapInfo(mpA);
			printMapInfo(mpB);
			std::cout << "Check iterator validity: " << std::endl;
			std::cout << (OldItA == mpB.begin()) << std::endl;
			std::cout << (OldIteA == mpB.end()) << std::endl;
			std::cout << (OldItB == mpA.begin()) << std::endl;
			std::cout << (OldIteB == mpA.end()) << std::endl;

			/*clear*/
			std::cout << "# clear() #" << std::endl;
			mpA.clear();
			printMapInfo(mpA);
			mpB.clear();
			printMapInfo(mpB);
		}
	}
	
}

void	test_map()
{
	#ifndef SPEED
		test_accuracy();
	#else
		test_performance();
	#endif
	(void)(test_performance);
}