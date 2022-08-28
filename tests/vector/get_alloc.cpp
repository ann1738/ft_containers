#include "common.hpp"

int main()
{
	/*get_allocator*/
	std::cout << "# get_allocator() #" << std::endl;
	ft::vector<int> vec;

	int *ptr = vec.get_allocator().allocate(1000);

	for (int i = 0; i < 1000; ++i) vec.get_allocator().construct(ptr + i, i);

	for (int i = 0; i < 1000; ++i) std::cout << ptr[i] << " - ";
	std::cout << std::endl;

	for (int i = 0; i < 1000; ++i) vec.get_allocator().destroy(ptr + i);
	vec.get_allocator().deallocate(ptr, 1000);
}