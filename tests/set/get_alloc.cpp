#include "common.hpp"

int main()
{
	/*get_allocator*/
	std::cout << "# get_allocator() #" << std::endl;
	ft::set<int> st;

	ft::set<int>::value_type *ptr = st.get_allocator().allocate(1000);

	for (int i = 0; i < 1000; ++i) st.get_allocator().construct(ptr + i, i);

	for (int i = 0; i < 1000; ++i) std::cout << ptr[i] << " - ";
	std::cout << std::endl;

	for (int i = 0; i < 1000; ++i) st.get_allocator().destroy(ptr + i);
	st.get_allocator().deallocate(ptr, 1000);
}