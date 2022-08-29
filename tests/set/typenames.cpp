#include "common.hpp"

int main()
{
	/*testing typenames*/
	std::cout << "********** Testing Typenames **********" << std::endl;
	ft::set<int>::key_type a;
	ft::set<int>::value_type b;
	ft::set<int>::key_compare c;
	ft::set<int>::value_compare d;
	ft::set<int>::allocator_type e;
	ft::set<int>::reference f = b;
	ft::set<int>::const_reference g = b;
	ft::set<int>::pointer h = NULL;
	ft::set<int>::const_pointer i = h;
	ft::set<int>::iterator j;
	ft::set<int>::const_iterator k;
	ft::set<int>::reverse_iterator l;
	ft::set<int>::const_reverse_iterator m;
	ft::set<int>::difference_type n;
	ft::set<int>::size_type o;
	(void)a; (void)b; (void)c; (void)d; (void)e;
	(void)f; (void)g; (void)h; (void)i; (void)j;
	(void)k; (void)l; (void)m; (void)n; (void)o;
}