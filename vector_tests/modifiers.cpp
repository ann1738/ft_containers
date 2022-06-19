/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 07:29:58 by ann               #+#    #+#             */
/*   Updated: 2022/06/19 13:06:57 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared.hpp"
#include "../testing.hpp"
#include <vector>
#include <algorithm>

/*	clear()	*/
void	vector_clear()
{
	{
		std::vector<int> strd;
		ft::vector<int> mine;

		for (size_t i = 0; i < 1000; ++i)
		{
			strd.push_back(i);
			mine.push_back(i);
		}
		assert(strd.size() == mine.size());
		assert(strd.capacity() == mine.capacity());
		strd.clear();
		mine.clear();
		assert(strd.size() == mine.size());
		assert(strd.capacity() == mine.capacity());

	}
	{
		std::vector<std::string> strd;
		ft::vector<std::string> mine;

		for (size_t i = 0; i < 2000; ++i)
		{
			strd.push_back("hello");
			mine.push_back("hello");
			assert(strd.capacity() == mine.capacity());
		}
		assert(strd.size() == mine.size());
		assert(strd.capacity() == mine.capacity());
		strd.clear();
		mine.clear();
		assert(strd.size() == mine.size());
		assert(strd.capacity() == mine.capacity());
	}
	std::cout << "clear() " PASS << std::endl;
}

/*	insert()	*/
void	vector_insert()
{
	{
		std::vector<int> strd;
		ft::vector<int> mine;

		// for (size_t i = 0; i < 1000; ++i)
		// {
		// 	strd.push_back(i);
		// 	mine.push_back(i);
		// }

		// if (std::find(strd.begin(), strd.end(), 0) != strd.end())
		// 	strd.insert(std::find(strd.begin(), strd.end(), 500), 10, -42);
		// if (std::find(strd.begin(), strd.end(), 250) != strd.end())
		// 	strd.insert(std::find(strd.begin(), strd.end(), 500), -42);
		// if (std::find(strd.begin(), strd.end(), 500) != strd.end())
		// 	strd.insert(std::find(strd.begin(), strd.end(), 500), -42);
		// if (std::find(strd.begin(), strd.end(), 750) != strd.end())
		// 	strd.insert(std::find(strd.begin(), strd.end(), 500), -42);
		// if (std::find(strd.begin(), strd.end(), 999) != strd.end())
		// 	strd.insert(std::find(strd.begin(), strd.end(), 500), -42);

		// if (std::find(mine.begin(), mine.end(), 0) != mine.end())
		// 	mine.insert(std::find(mine.begin(), mine.end(), 500), 10, -42);
		// if (std::find(mine.begin(), mine.end(), 250) != mine.end())
		// 	mine.insert(std::find(mine.begin(), mine.end(), 500), -42);
		// if (std::find(mine.begin(), mine.end(), 500) != mine.end())
		// 	mine.insert(std::find(mine.begin(), mine.end(), 500), -42);
		// if (std::find(mine.begin(), mine.end(), 750) != mine.end())
		// 	mine.insert(std::find(mine.begin(), mine.end(), 500), -42);
		// if (std::find(mine.begin(), mine.end(), 999) != mine.end())
		// 	mine.insert(std::find(mine.begin(), mine.end(), 500), -42);

		// assert(strd.size() == mine.size());
		// assert(strd.capacity() == mine.capacity());
		// for (size_t i = 0; i < strd.size(); ++i)
		// 	assert(strd[i] == mine[i]);
	}
	{
		std::vector<std::string> strd;
		ft::vector<std::string> mine;

		strd.push_back("ONE");
		strd.push_back("TWO");
		strd.push_back("THREE");
		strd.push_back("FOUR");
		strd.push_back("FIVE");

		mine.push_back("ONE");
		mine.push_back("TWO");
		mine.push_back("THREE");
		mine.push_back("FOUR");
		mine.push_back("FIVE");


		if (std::find(strd.begin(), strd.end(), "ONE") != strd.end())
			strd.insert(std::find(strd.begin(), strd.end(), "ONE"), 2, "INSERT THIS!");
		if (std::find(strd.begin(), strd.end(), "THREE") != strd.end())
			strd.insert(std::find(strd.begin(), strd.end(), "THREE"), "INSERT THIS!");
		if (std::find(strd.begin(), strd.end(), "FIVE") != strd.end())
			strd.insert(std::find(strd.begin(), strd.end(), "FIVE"), "INSERT THIS!");

		if (std::find(mine.begin(), mine.end(), "ONE") != mine.end())
			mine.insert(std::find(mine.begin(), mine.end(), "ONE"), 2, "INSERT THIS!");
		std::cout << "----------------------------------------------------------------------\n";
		if (std::find(mine.begin(), mine.end(), "THREE") != mine.end())
			mine.insert(std::find(mine.begin(), mine.end(), "THREE"), "INSERT THIS!");
		std::cout << "----------------------------------------------------------------------\n";
		if (std::find(mine.begin(), mine.end(), "FIVE") != mine.end())
			mine.insert(std::find(mine.begin(), mine.end(), "FIVE"), "INSERT THIS!");

		assert(strd.size() == mine.size());
		assert(strd.capacity() == mine.capacity());
		for (size_t i = 0; i < strd.size(); ++i)
			std::cout << strd[i] << " == " << mine[i] << std::endl;
			// assert(strd[i] == mine[i]);	
	}
	std::cout << "insert() " PASS << std::endl;
}
