#include "common.hpp"

int main()
{
	/*testing typenames*/
	ft::stack<int>::value_type a;
	ft::stack<int>::container_type b;
	ft::stack<int>::size_type c;
	(void)a; (void)b; (void)c;
}