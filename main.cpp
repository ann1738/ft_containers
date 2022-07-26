/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:49:21 by ann               #+#    #+#             */
/*   Updated: 2022/07/25 16:02:01 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <vector>
#include <map>

#include "shared.hpp"
// #include "testing.hpp"

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
/********************************************************************************************/
// #define ft std
#define TESTED_NAMESPACE ft

#define _pair TESTED_NAMESPACE::pair


/********************************************************************************************/
// #define ft std
#include <list>


template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}


#define T1 float
#define T2 foo<int>
typedef _pair<const T1, T2> T3;

int		main(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 5;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(2.5 - i, (i + 1) * 7));

	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	TESTED_NAMESPACE::map<T1, T2>::reverse_iterator it(mp.rbegin());
	TESTED_NAMESPACE::map<T1, T2>::const_reverse_iterator ite(mp.rbegin());
	printSize(mp);

	printPair(++ite);
	printPair(ite++);
	printPair(ite++);
	printPair(++ite);

	it->second.m();
	ite->second.m();

	printPair(++it);
	printPair(it++);
	printPair(it++);
	printPair(++it);

	printPair(--ite);
	printPair(ite--);
	printPair(--ite);
	printPair(ite--);

	(*it).second.m();
	(*ite).second.m();

	printPair(--it);
	printPair(it--);
	printPair(it--);
	printPair(--it);

	return (0);
}












/* DONT DELETE -> THIS IS THE MAIN TEST */
// int main(int argc, char **argv)
// {
// 	(void)argc;
// 	(void)argv;


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
		
	// }

// #endif