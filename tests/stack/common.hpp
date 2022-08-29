#include "../../stack.hpp"

#ifdef TESTING
# define ft std
#include <stack>
#endif

template< class T >
static void	printStackInfo(const T & contatiner){
	std::cout << "Empty " << contatiner.empty() << std::endl;
	std::cout << "Size: " << contatiner.size() << std::endl;
	if (contatiner.size())
		std::cout << "Top: " << contatiner.top() << std::endl;
}