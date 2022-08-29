#include "common.hpp"

int main()
{
	/*get_allocator*/
	std::cout << "# get_allocator() #" << std::endl;
	ft::map<int, std::string> mp;

	ft::map<int, std::string>::value_type *ptr = mp.get_allocator().allocate(1000);

	for (int i = 0; i < 1000; ++i) mp.get_allocator().construct(ptr + i, ft::make_pair(i, "HELLO!"));

	for (int i = 0; i < 1000; ++i) std::cout << ptr[i].first << "->" << ptr[i].second << " - ";
	std::cout << std::endl;

	for (int i = 0; i < 1000; ++i) mp.get_allocator().destroy(ptr + i);
	mp.get_allocator().deallocate(ptr, 1000);
}