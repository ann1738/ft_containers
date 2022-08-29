#include "common.hpp"

int main()
{
	/*testing typenames*/
	std::cout << "********** Testing Typenames **********" << std::endl;
	ft::map<int, std::string>::key_type a;
	ft::map<int, std::string>::mapped_type b;
	ft::map<int, std::string>::value_type c;
	ft::map<int, std::string>::key_compare d;
	ft::map<int, std::string>::allocator_type e;
	ft::map<int, std::string>::reference f = c;
	ft::map<int, std::string>::const_reference g = c;
	ft::map<int, std::string>::pointer h = NULL;
	ft::map<int, std::string>::const_pointer i = h;
	ft::map<int, std::string>::iterator j;
	ft::map<int, std::string>::const_iterator k;
	ft::map<int, std::string>::reverse_iterator l;
	ft::map<int, std::string>::const_reverse_iterator m;
	ft::map<int, std::string>::difference_type n;
	ft::map<int, std::string>::size_type o;
	(void)a; (void)b; (void)c; (void)d; (void)e;
	(void)f; (void)g; (void)h; (void)i; (void)j;
	(void)k; (void)l; (void)m; (void)n; (void)o;
}