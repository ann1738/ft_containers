#include "../../stack.hpp"
#include "timer.hpp"

#ifdef TESTING
# define ft std
#include <stack>
#endif

int main()
{
	int amount = 100000;
	std::cout << "(" << amount << " elements)" << std::endl;
	std::cout << "Insertion: ";
	timer *T1 = new timer();
	ft::stack<int> stk;
	for (int i = 0; i < amount; ++i)
		stk.push(i);
	delete T1;

	std::cout << "Deletion: ";
	timer *T3 = new timer();
	while (!stk.empty())
		stk.pop();
	delete T3;
}