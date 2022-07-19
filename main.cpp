/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:49:21 by ann               #+#    #+#             */
/*   Updated: 2022/07/19 12:33:25 by ann              ###   ########.fr       */
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
# define TESTED_TYPE int
// #define TESTED_TYPE foo<int>
// # define TESTED_TYPE std::string
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


void	printSize(const TESTED_NAMESPACE::vector<TESTED_TYPE> & cont)
{
	std::cout << "Size is " << cont.size() << std::endl; 
	std::cout << "Capacity is " << cont.capacity() << std::endl;
	std::cout << "content is " << std::endl;
	for (TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator it = cont.begin(); it != cont.end(); ++it)
		std::cout << *it << std::endl;
}


// void	checkErase(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct,
// 					TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator const &it)
// {
// 	static int i = 0;
// 	std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
// 	printSize(vct);
// }
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
	TESTED_NAMESPACE::vector<TESTED_TYPE> foo(3, 15);
	TESTED_NAMESPACE::vector<TESTED_TYPE> bar(5, 42);
	
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator it_foo = foo.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator it_bar = bar.begin();

	std::cout << "BEFORE SWAP" << std::endl;

	std::cout << "foo contains:" << std::endl;
	printSize(foo);
	std::cout << "bar contains:" << std::endl;
	printSize(bar);

	foo.swap(bar);

	std::cout << "AFTER SWAP" << std::endl;

	std::cout << "foo contains:" << std::endl;
	printSize(foo);
	std::cout << "bar contains:" << std::endl;
	printSize(bar);

	std::cout << "Iterator validity:" << std::endl;
	std::cout << (it_foo == bar.begin()) << std::endl;
	std::cout << (it_bar == foo.begin()) << std::endl;
		(void)argc;
		(void)argv;

	#endif
}
