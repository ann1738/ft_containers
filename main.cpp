/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:49:21 by ann               #+#    #+#             */
/*   Updated: 2022/06/12 18:14:53 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "vector.hpp"
#include <iostream>
#include <exception>
// #include <vector>
#include <string>

#include "vector.hpp"
#include "timer.hpp"
#include <vector>
int main()
{
	{
		timer t1;
		std::vector<int> stand(1, 1);
		for (int i = 0; i < 10000; ++i)
			stand.push_back(2);
	}
	std::cout << "*************************" << std::endl;
	{
		timer t1;
		ft::vector<int> stand(1, 1);
		for (int i = 0; i < 10000; ++i)
			stand.push_back(2);
	}
	std::cout << "#########################" << std::endl;
}
