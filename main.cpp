/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:49:21 by ann               #+#    #+#             */
/*   Updated: 2022/06/12 08:48:20 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "vector.hpp"
#include <iostream>
#include <exception>
// #include <vector>
#include <string>

#include "vector.hpp"
#include <vector>
int main()
{
	try{
		ft::vector<int> a(10, 42);
		a.push_back(2);
		std::cout << "front: "<< a.front() << "and back: " << a.back() << std::endl;}catch (std::exception & e) {std::cerr << e.what() << std::endl;}
	// ft::vector<std::string> a(10, "howwo");
	// ft::vector<int> a(1, 1);
	// for (ft::vector<std::string>::size_type i = 0; i < a.size(); ++i)
	// 	std::cout << a[i] << std::endl;
	
	// std::cout << a.capacity() << std::endl;
	// a.push_back(1);
	// std::cout << a.capacity() << std::endl;
	// a.push_back(2);
	// std::cout << a.capacity() << std::endl;
	// a.push_back(3);
	// std::cout << a.capacity() << std::endl;
	// a.push_back(5);
	// std::cout << a.capacity() << std::endl;
	// a.push_back(8);
	// std::cout << a.capacity() << std::endl;
	// a.push_back(13);
	// std::cout << a.capacity() << std::endl;
	// a.push_back(21);
	// std::cout << a.capacity() << std::endl;
	// for (ft::vector<int>::iterator it = a.begin(); it != a.end(); ++it)
		// std::cout << *i << std::endl;
	
	// for (std::vector<int>::iterator it = a.begin(); i != a.end(); ++i)
	
	// a.push_back("HEYO2");
	// a.push_back("HEYO3");
	// a.push_back("HEYO4");
	// for (int i = 0; i < 5; ++i) std::cout << a[i] << std::endl;
	// std::cout << a.size() << std::endl;
	// try{
		// std::cout << a[111] << std::endl;
	// }
	// catch (std::exception & e)
	// {
	// 	std::cerr << e.what() <<  std::endl;
	// }
}