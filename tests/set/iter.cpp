#include "common.hpp"

int main()
{
	/*iterators*/
	std::cout << "********** Testing Iterators: **********" << std::endl;
	ft::set<int> st;
	for (int i = 0; i < 10000; ++i)
		st.insert(i);
	printSetInfo(st);

	ft::set<int>::iterator it = st.begin();
	ft::set<int>::iterator ite = st.end();

	for(; it != ite; ++it)
		std::cout << *it << " - ";
	std::cout << std::endl;
	
	it = st.begin();
	ite--;

	for(; ite != it; --ite)
		std::cout << *ite << " - ";
	std::cout << std::endl;

	ft::set<int>::reverse_iterator rit = st.rbegin();
	ft::set<int>::reverse_iterator rite = st.rend();

	for(; rit != rite; ++rit)
		std::cout << *rit << " - ";
	std::cout << std::endl;
	
	rit = st.rbegin();
	rite--;

	for(; rite != rit; --rite)
		std::cout << *rite << " - ";
	std::cout << std::endl;
			
	/*relational operators for iterators*/
	it = st.begin();
	ite = st.end();

	std::cout << (it == ite) << std::endl;
	std::cout << (it != ite) << std::endl;
	
	/*relational operators for iterators and const_iterators*/
	ft::set<int>::const_iterator cit = st.begin();
	ft::set<int>::const_iterator cite = st.end();

	std::cout << (it == cite) << std::endl;
	std::cout << (it != cite) << std::endl;

	std::cout << (cit == ite) << std::endl;
	std::cout << (cit != ite) << std::endl;
}