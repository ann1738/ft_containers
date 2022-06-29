/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:58:15 by ann               #+#    #+#             */
/*   Updated: 2022/06/29 13:20:05 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../testing.hpp"
#include <stack>

void	test_stack()
{
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
}