#include "common.hpp"

int main()
{
	/*testing member-functions and relational operators*/
	ft::stack<std::string> stk;

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