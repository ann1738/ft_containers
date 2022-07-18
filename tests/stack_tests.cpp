/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:58:15 by ann               #+#    #+#             */
/*   Updated: 2022/07/14 12:36:07 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../testing.hpp"
#include <stack>

#define TESTED_TYPE int
#define TESTED_NAMESPACE ft
#define t_stack_ TESTED_NAMESPACE::stack<TESTED_TYPE>
typedef t_stack_::container_type container_type;

template <class T_STACK>
void	cmp(const T_STACK &lhs, const T_STACK &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}
void	test_stack()
{

	container_type	ctnr;

	ctnr.push_back(21);
	ctnr.push_back(42);
	ctnr.push_back(1337);
	ctnr.push_back(19);
	ctnr.push_back(0);
	ctnr.push_back(183792);

	t_stack_	stck(ctnr);
	t_stack_	stck2(ctnr);

	cmp(stck, stck);  // 0
	cmp(stck, stck2); // 1

	stck2.push(60);
	stck2.push(61);
	stck2.push(62);

	cmp(stck, stck2); // 2
	cmp(stck2, stck); // 3

	stck.push(42);

	cmp(stck, stck2); // 4
	cmp(stck2, stck); // 5

	stck.push(100);

	cmp(stck, stck2); // 6
	cmp(stck2, stck); // 7
	return ;
	#if 0
	{
		std::stack<int> stnd;
		ft::stack<int> mine;

		assert(stnd.empty() == mine.empty());
		assert(stnd.size() == mine.size());
		// assert(stnd.top() == mine.top());

		stnd.push(5);
		mine.push(5);
		
		assert(stnd.empty() == mine.empty());
		assert(stnd.size() == mine.size());
		assert(stnd.top() == mine.top());

		stnd.pop();
		mine.pop();

		assert(stnd.empty() == mine.empty());
		assert(stnd.size() == mine.size());
		// assert(stnd.top() == mine.top());

		for (ft::stack<int>::size_type i = 0; i < 100; ++i)
		{
			stnd.push(i);
			mine.push(i);
			assert(stnd.size() == mine.size());
			assert(stnd.top() == mine.top());
		}
		
		assert(stnd == stnd && mine == mine);
		assert(!(stnd != stnd) && !(mine != mine));
		assert(!(stnd < stnd) && !(mine < mine));
		assert((stnd <= stnd) && (mine <= mine));
		assert(!(stnd > stnd) && !(mine > mine));
		assert((stnd >= stnd) && (mine >= mine));

		// container_type a;

		for (ft::stack<int>::size_type i = 0; i < 100; ++i)
		{
			assert(stnd.top() == mine.top());
			assert(stnd.size() == mine.size());
			stnd.pop();
			mine.pop();
		}

		assert(stnd.empty() == mine.empty());
	}

	{
		std::stack<std::string> stnd;
		ft::stack<std::string> mine;

		assert(stnd.empty() == mine.empty());
		assert(stnd.size() == mine.size());
		// assert(stnd.top() == mine.top());

		stnd.push("FIRST");
		mine.push("FIRST");
		
		assert(stnd.empty() == mine.empty());
		assert(stnd.size() == mine.size());
		assert(stnd.top() == mine.top());

		stnd.pop();
		mine.pop();

		assert(stnd.empty() == mine.empty());
		assert(stnd.size() == mine.size());
		// assert(stnd.top() == mine.top());

		for (ft::stack<int>::size_type i = 0; i < 100; ++i)
		{
			stnd.push("HEHE");
			mine.push("HEHE");
			assert(stnd.size() == mine.size());
			assert(stnd.top() == mine.top());
		}

		// assert(stnd == stnd);
		// assert(!(stnd != stnd));
		// assert(!(stnd < stnd));
		// assert(!(stnd <= stnd));
		// assert(!(stnd > stnd));
		// assert(!(stnd >= stnd));
		
		// assert(mine == mine);
		// assert(!(mine != mine));
		// assert(!(mine < mine));
		// assert(!(mine <= mine));
		// assert(!(mine > mine));
		// assert(!(mine >= mine));

		for (ft::stack<int>::size_type i = 0; i < 100; ++i)
		{
			assert(stnd.top() == mine.top());
			assert(stnd.size() == mine.size());
			stnd.pop();
			mine.pop();
		}

		assert(stnd.empty() == mine.empty());
	}
	#endif
}

// template <class T_STACK>
// void	cmp(const T_STACK &lhs, const T_STACK &rhs)
// {
// 	static int i = 0;

// 	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
// 	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
// 	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
// 	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
// }

// int		main(void)
// {
// 	container_type	ctnr;

// 	ctnr.push_back(21);
// 	ctnr.push_back(42);
// 	ctnr.push_back(1337);
// 	ctnr.push_back(19);
// 	ctnr.push_back(0);
// 	ctnr.push_back(183792);

// 	t_stack_	stck(ctnr);
// 	t_stack_	stck2(ctnr);

// 	cmp(stck, stck);  // 0
// 	cmp(stck, stck2); // 1

// 	stck2.push(60);
// 	stck2.push(61);
// 	stck2.push(62);

// 	cmp(stck, stck2); // 2
// 	cmp(stck2, stck); // 3

// 	stck.push(42);

// 	cmp(stck, stck2); // 4
// 	cmp(stck2, stck); // 5

// 	stck.push(100);

// 	cmp(stck, stck2); // 6
// 	cmp(stck2, stck); // 7
// 	return (0);
// }
