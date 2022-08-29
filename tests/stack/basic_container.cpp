#include "common.hpp"
#include <list>

int main()
{
	/*testing member-functions and relational operators*/
	ft::stack< int, std::list<int> > stk;

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