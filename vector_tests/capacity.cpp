/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 06:53:08 by ann               #+#    #+#             */
/*   Updated: 2022/06/19 07:28:32 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared.hpp"
#include "../testing.hpp"
#include <vector>

/*	empty()	*/
void	vector_empty()
{
	{
		std::vector<int> strd;
		ft::vector<int> mine;
		
		assert(strd.empty() == mine.empty());
		
		strd.push_back(1);
		mine.push_back(1);

		assert(strd.empty() == mine.empty());
	}
	{
		std::vector<char> strd;
		ft::vector<char> mine;
		
		assert(strd.empty() == mine.empty());
		
		strd.push_back('a');
		mine.push_back('a');

		assert(strd.empty() == mine.empty());
	}
	std::cout << "empty() " PASS << std::endl;
}

/*	size()	*/
void	vector_size()
{
	{
		std::vector<int> strd;
		ft::vector<int> mine;
		
		assert(strd.size() == mine.size());
		
		for (size_t i = 0; i < 100; ++i)
		{
			strd.push_back(i);
			mine.push_back(i);
			assert(strd.size() == mine.size());
		}
	}
	{
		std::vector<char> strd;
		ft::vector<char> mine;
		
		assert(strd.size() == mine.size());

		for (char c = 'a'; c < 'z' + 1; ++c)
		{
			strd.push_back(c);
			mine.push_back(c);
			assert(strd.size() == mine.size());
		}
	}
	{
		std::vector<std::string> strd;
		ft::vector<std::string> mine;
		
		assert(strd.size() == mine.size());

		for (size_t i = 0; i < 100; ++i)
		{
			strd.push_back("hello");
			mine.push_back("hello");
			assert(strd.size() == mine.size());
		}
	}
	std::cout << "size() " PASS << std::endl;
}

// /*	max_size()	*/
// void	vector_max_size()
// {
// 	{
// 		std::vector<int> strd;
// 		ft::vector<int> mine;

// 		std::cout << "standard is " << strd.max_size() << ", mine is " << mine.max_size() << std::endl;
// 		assert(strd.max_size() == mine.max_size());
// 	}
// 	{
// 		std::vector<std::string> strd;
// 		ft::vector<std::string> mine;

// 		assert(strd.max_size() == mine.max_size());
// 	}
// 	std::cout << "max_size() " PASS << std::endl;
// }

/*	reserve()	*/
void	vector_reserve()
{
	{
		std::vector<int> strd;
		ft::vector<int> mine;

		assert(strd.capacity() == mine.capacity());

		try
		{
			mine.reserve(15666464545640);
			std::cout << "reserve() " FAIL << std::endl;
		}
		catch(const std::exception& e){}
		try
		{
			strd.reserve(15666464545640);
			std::cout << "reserve() " FAIL << std::endl;
		}
		catch(const std::exception& e){}

		strd.reserve(100);
		mine.reserve(100);
		assert(strd.capacity() == mine.capacity());

		strd.reserve(1);
		mine.reserve(1);
		assert(strd.capacity() == mine.capacity());

		strd.reserve(0);
		mine.reserve(0);
		assert(strd.capacity() == mine.capacity());
	}
	std::cout << "reserve() " PASS << std::endl;
}

/*	capacity()	*/
void	vector_capacity()
{
	{
		std::vector<int> strd;
		ft::vector<int> mine;

		for (size_t i = 0; i < 1000; ++i)
		{
			strd.push_back(i);
			mine.push_back(i);
			assert(strd.capacity() == mine.capacity());
		}
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
	}
	std::cout << "capacity() " PASS << std::endl;
}
