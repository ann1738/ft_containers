#include "common.hpp"

int main()
{
	/*testing typenames*/
	std::cout << "********** Testing Typenames **********" << std::endl;
	ft::vector<int>::value_type a;
	ft::vector<int>::allocator_type b;
	ft::vector<int>::reference c = a;
	ft::vector<int>::const_reference d = a;
	ft::vector<int>::pointer e;
	ft::vector<int>::const_pointer f;
	ft::vector<int>::iterator g;
	ft::vector<int>::const_iterator h;
	ft::vector<int>::reverse_iterator i;
	ft::vector<int>::const_reverse_iterator j;
	ft::vector<int>::difference_type k;
	ft::vector<int>::size_type l;
	(void)a; (void)b; (void)c; (void)d; (void)e;
	(void)f; (void)g; (void)h; (void)i; (void)j;
	(void)k; (void)l;
}
