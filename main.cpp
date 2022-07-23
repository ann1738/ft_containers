/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:49:21 by ann               #+#    #+#             */
/*   Updated: 2022/07/22 13:54:00 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <vector>
#include <map>
// #include <stack>
// #include <map>
#include "shared.hpp"
#include "testing.hpp"
// #include <cstdlib>

#include "tests/tests.hpp"

// # include <list>

// #define TESTED_TYPE foo<int>
// # define TESTED_TYPE std::string

# define ft std
# define TESTED_TYPE int
# define TESTED_NAMESPACE ft
#define DEGUB() (std::cout << "\e[33mDEBUGGING\e[0m\n")



/**/
template <typename T>
class foo {
	public:
		typedef T	value_type;

		foo(void) : value(), _verbose(false) { };
		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
		foo &operator=(value_type src) { this->value = src; return *this; };
		foo &operator=(foo const &src) {
			if (this->_verbose || src._verbose)
				std::cout << "foo::operator=(foo) CALLED" << std::endl;
			this->value = src.value;
			return *this;
		};
		value_type	getValue(void) const { return this->value; };
		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

		operator value_type(void) const {
			return value_type(this->value);
		}
	private:
		value_type	value;
		bool		_verbose;
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, foo<T> const &bar) {
	o << bar.getValue();
	return o;
}
/**/


#define _pair TESTED_NAMESPACE::pair

#define T1 int
#define T2 foo<int>
typedef TESTED_NAMESPACE::map<T1, T2>::value_type T3;
typedef TESTED_NAMESPACE::map<T1, T2>::iterator ft_iterator;
typedef TESTED_NAMESPACE::map<T1, T2>::const_iterator ft_const_iterator;

// template <typename T>
// std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
// {
// 	o << "key: " << iterator->first << " | value: " << iterator->second;
// 	if (nl)
// 		o << std::endl;
// 	return ("");
// }


// void	printSize(const TESTED_NAMESPACE::map<T1,T2> & cont)
// {
// 	std::cout << "Size is " << cont.size() << std::endl; 
// 	std::cout << "content is " << std::endl;
// 	for (TESTED_NAMESPACE::map<T1, T2>::const_iterator it = cont.begin(); it != cont.end(); ++it)
// 		std::cout << it->first << "->" << it->second << std::endl;
// }

// static int iter = 0;

// template <typename MAP>
// void	ft_bound(MAP &mp, const T1 &param)
// {
// 	ft_iterator ite = mp.end(), it[2];
// 	_pair<ft_iterator, ft_iterator> ft_range;

// 	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
// 	std::cout << "with key [" << param << "]:" << std::endl;
// 	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
// 	ft_range = mp.equal_range(param);
// 	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
// 	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
// 	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
// }

// template <typename MAP>
// void	ft_const_bound(const MAP &mp, const T1 &param)
// {
// 	ft_const_iterator ite = mp.end(), it[2];
// 	_pair<ft_const_iterator, ft_const_iterator> ft_range;

// 	std::cout << "\t-- [" << iter++ << "] (const) --" << std::endl;
// 	std::cout << "with key [" << param << "]:" << std::endl;
// 	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
// 	ft_range = mp.equal_range(param);
// 	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
// 	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
// 	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
// }

// int		main(void)
// {
// 	// std::map<int,std::string> m;
// 	// m[0];
// 	// m[1];
// 	// m[2];
// 	// m[3];
// 	// std::map<int,std::string>::const_iterator it = m.begin();
	
// 	// it->second = "heheh";
// 	// std::list<T3> lst;
// 	// unsigned int lst_size = 10;
// 	// for (unsigned int i = 0; i < lst_size; ++i)
// 	// 	lst.push_back(T3(i + 1, (i + 1) * 3));
// 	// TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
// 	// printSize(mp);

// 	// ft_const_bound(mp, -10);
// 	// ft_const_bound(mp, 1);
// 	// ft_const_bound(mp, 5);
// 	// ft_const_bound(mp, 10);
// 	// ft_const_bound(mp, 50);

// 	// printSize(mp);

// 	// mp.lower_bound(3)->second = 404;
// 	// mp.upper_bound(7)->second = 842;
// 	// ft_bound(mp, 5);
// 	// ft_bound(mp, 7);

// 	// printSize(mp);
	
// 	// ft::map<int,std::string> m;
// 	// std::map<int,std::string> s;
// 	// assert(m.max_size() == s.max_size());

// 	// ft::map<char,std::string> m1;
// 	// std::map<char,std::string> s1;
// 	// assert(m1.max_size() == s1.max_size());

// 	// ft::map<char, int> m2;
// 	// std::map<char,int> s2;
// 	// assert(m2.max_size() == s2.max_size());
	
// 	// ft::map<char, ft::vector<int> > m3;
// 	// std::map<char,ft::vector<int> > s3;
// 	// assert(m3.max_size() == s3.max_size());
// 	return (0);
// }
// #define ft std
#include "set.hpp"
// #if 1
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	ft::set<int> my;
	int amount = 10000000;
	for (int i = 0; i < amount; ++i) my.insert(i);

	{
		timer T;
		my.find(amount - 1);
	}
	{
		timer T;
		my.find(amount / 10);
	}
	{
		timer T;
		my.find(amount / 5);
	}
	{
		timer T;
		my.find(amount / 7);
	}
	// size_t i = 0;
	// std::cout << std::endl << "\e[33mBEGINNING OF MAIN()\e[0m" << std::endl;
	// for(ft::set<int>::iterator it = my.begin(); i < my.size(); ++it, ++i)
	// {
	// 	std::cout << *it << "\tcolor is "; my.printColorAndParent(*it); std::cout << std::endl;
	// }

	// ft::map<int,int>::iterator i;
	// i == i;
	// i != i;
		// ft::map<int, char> m; m[0]; m[1]; m [10];
		// ft::map<int, char>::iterator it = m.begin();
		// ft::map<int, char>::iterator ite = m.end();
		// for(; ite != it; --ite)
		// {
		// 	if (ite != m.end())
		// 		std::cout << it->first << std::endl;
		// 	// ++it;
		// }
		// std::vector<int>::iterator it;
		// it < it;
	// #if TESTING_MODE
	// {
		// if (argc != 2)
		// {
		// 	std::cout << "\e[31mInvalid Input\e[0m" << std::endl
		// 	<< "Valid inputs: \e[35m./main\t \e[33m\"vector\"\e[0m OR \e[33m\"map\"\e[0m OR \e[33m\"stack\"\e[0m OR \e[33m\"all\"\e[0m" << std::endl;
		// 	return 1;
		// }
		// std::string possible[] = {"vector", "map", "stack", "all"};
		// int	test_index = 0;
		// for (; test_index < 4 && argv[1] != possible[test_index]; ++test_index);
		// switch (test_index)
		// {
		// case 0: //vector
		// 	test_vector();
		// 	break;
		// case 1: //map
		// 	test_map();
		// 	break;
		// case 2: //stack
		// 	test_stack();
		// 	break;
		// case 3: //vector
		// 	//test_vector();
		// 	break;
		// default:
		// 	std::cout << "\e[31mInvalid Input\e[0m" << std::endl
		// 	<< "Valid inputs: \e[35m./main\t \e[33m\"vector\"\e[0m OR \e[33m\"map\"\e[0m OR \e[33m\"stack\"\e[0m OR \e[33m\"all\"\e[0m" << std::endl;
		// 	break;
		// }
		

		// std::vector<int>::iterator it;
		// it.base
		// std::map<int, char>::iterator it;
		// it.base();
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

// #endif