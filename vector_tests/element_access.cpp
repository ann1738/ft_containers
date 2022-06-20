/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_access.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:53:49 by ann               #+#    #+#             */
/*   Updated: 2022/06/20 08:56:26 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared.hpp"
#include "../testing.hpp"
#include <vector>

/* at() */
void	vector_at()
{
	{
		std::vector<int> strd;
		ft::vector<int> mine;

		for (size_t i = 0; i < 26; ++i)
		{
			strd.push_back(i);
			mine.push_back(i);
		}
		for (size_t i = 0; i < 26; ++i)
			assert(strd.at(i) == mine.at(i));
	}
	{
		std::vector<char> strd;
		ft::vector<char> mine;

		for (char c = 'a'; c < 'z' + 1; ++c)
		{
			strd.push_back(c);
			mine.push_back(c);
		}
		
		for (size_t i = 0; i < 26; ++i)
			assert(strd.at(i) == mine.at(i));
	}
	std::cout << "at() " PASS << std::endl;
}

/* operator[] */
void	vector_subscript()
{
	{
		std::vector<int> strd;
		ft::vector<int> mine;

		for (size_t i = 0; i < 26; ++i)
		{
			strd.push_back(i);
			mine.push_back(i);
		}
		
		for (size_t i = 0; i < 26; ++i)
			assert(strd[i] == mine[i]);
	}
	{
		std::vector<char> strd;
		ft::vector<char> mine;

		for (char c = 'a'; c < 'z' + 1; ++c)
		{
			strd.push_back(c);
			mine.push_back(c);
		}

		for (size_t i = 0; i < 26; ++i)
			assert(strd[i] == mine[i]);
	}
	std::cout << "operator[] " PASS << std::endl;
}

/* front() */
void	vector_front()
{
	{
		std::vector<int> strd;
		ft::vector<int> mine;

		for (size_t i = 0; i < 26; ++i)
		{
			strd.push_back(i);
			mine.push_back(i);
		}
		assert(strd.front() == mine.front());
	}
	{
		std::vector<char> strd;
		ft::vector<char> mine;

		for (char c = 'a'; c < 'z' + 1; ++c)
		{
			strd.push_back(c);
			mine.push_back(c);
		}
		assert(strd.front() == mine.front());
	}
	{
		std::vector<std::string> strd;
		ft::vector<std::string> mine;

		strd.push_back("ONE");
		strd.push_back("TWO");
		strd.push_back("THREE");

		mine.push_back("ONE");
		mine.push_back("TWO");
		mine.push_back("THREE");

		assert(strd.front() == mine.front());
	}
	std::cout << "front() " PASS << std::endl;
}

/* back() */
void	vector_back()
{
	{
		std::vector<int> strd;
		ft::vector<int> mine;

		for (size_t i = 0; i < 26; ++i)
		{
			strd.push_back(i);
			mine.push_back(i);
			assert(strd.back() == mine.back());
		}
	}
	{
		std::vector<char> strd;
		ft::vector<char> mine;

		for (char c = 'a'; c < 'z' + 1; ++c)
		{
			strd.push_back(c);
			mine.push_back(c);
			assert(strd.back() == mine.back());
		}
	}
	{
		std::vector<std::string> strd;
		ft::vector<std::string> mine;

		strd.push_back("ONE");
		mine.push_back("ONE");
		assert(strd.back() == mine.back());

		strd.push_back("TWO");
		mine.push_back("TWO");
		assert(strd.back() == mine.back());

		strd.push_back("THREE");
		mine.push_back("THREE");
		assert(strd.back() == mine.back());
	}

	std::cout << "back() " PASS << std::endl;
}

// /* data() */
// void	vector_data()
// {
// 	{
// 		std::vector<int> strd;
// 		ft::vector<int> mine;

// 		for (size_t i = 0; i < 26; ++i)
// 		{
// 			strd.push_back(i);
// 			mine.push_back(i);
// 		}
// 		int *dataStrd = strd.data();
// 		int *dataMine = mine.data();
// 		for (size_t i = 0; i < strd.size(); ++i, ++dataStrd, ++dataMine)
// 			assert(*dataStrd == *dataMine);
// 	}
// 	{
// 		std::vector<char> strd;
// 		ft::vector<char> mine;

// 		for (char c = 'a'; c < 'z' + 1; ++c)
// 		{
// 			strd.push_back(c);
// 			mine.push_back(c);
// 		}
// 		char *dataStrd = strd.data();
// 		char *dataMine = mine.data();
// 		for (size_t i = 0; i < strd.size(); ++i, ++dataStrd, ++dataMine)
// 			assert(*dataStrd == *dataMine);
// 	}
// 	{
// 		std::vector<std::string> strd;
// 		ft::vector<std::string> mine;

// 		strd.push_back("ONE");
// 		strd.push_back("TWO");
// 		strd.push_back("THREE");

// 		mine.push_back("ONE");
// 		mine.push_back("TWO");
// 		mine.push_back("THREE");

// 		std::string *dataStrd = strd.data();
// 		std::string *dataMine = mine.data();
// 		for (size_t i = 0; i < strd.size(); ++i, ++dataStrd, ++dataMine)
// 			assert(*dataStrd == *dataMine);
// 	}
// 	std::cout << "data() " PASS << std::endl;
// }
