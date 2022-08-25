/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:58:15 by ann               #+#    #+#             */
/*   Updated: 2022/08/25 16:45:01 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../testing.hpp"
#include <stack>

#ifdef TESTING
# define ft std
#endif

template< class T >
static void	printStackInfo(const T & contatiner){
	std::cout << "Empty " << contatiner.empty() << std::endl;
	std::cout << "Size: " << contatiner.size() << std::endl;
	if (contatiner.size())
		std::cout << "Top: " << contatiner.top() << std::endl;
}

void	test_stack()
{
	{
		/*testing typenames*/
		ft::stack<int>::value_type a;
		ft::stack<int>::container_type b;
		ft::stack<int>::size_type c;
		(void)a; (void)b; (void)c;

		/*testing member-functions and relational operators*/
		ft::stack<int> stk;

		printStackInfo(stk);

		stk.push(5);
		printStackInfo(stk);
		
		stk.pop();
		printStackInfo(stk);

		for (ft::stack<int>::size_type i = 0; i < 100; ++i)
		{
			stk.push(i);
			printStackInfo(stk);
		}
		
		std::cout << (stk == stk) << std::endl;
		std::cout << (stk != stk) << std::endl;
		std::cout << (stk < stk) << std::endl;
		std::cout << (stk <= stk) << std::endl;
		std::cout << (stk > stk) << std::endl;
		std::cout << (stk >= stk) << std::endl;

		while (!stk.empty())
		{
			stk.pop();
			printStackInfo(stk);
		}
	}
	{
		std::stack<std::string> stk;

		printStackInfo(stk);

		stk.push("FIRST");
		printStackInfo(stk);
		
		stk.pop();
		printStackInfo(stk);

		for (ft::stack<int>::size_type i = 0; i < 100; ++i)
		{
			stk.push("HELLO!");
			printStackInfo(stk);
		}

		std::cout << (stk == stk) << std::endl;
		std::cout << (stk != stk) << std::endl;
		std::cout << (stk < stk) << std::endl;
		std::cout << (stk <= stk) << std::endl;
		std::cout << (stk > stk) << std::endl;
		std::cout << (stk >= stk) << std::endl;

		while (!stk.empty())
		{
			stk.pop();
			printStackInfo(stk);
		}
		std::cout << "HEYEYE" << std::endl;
	}
}
