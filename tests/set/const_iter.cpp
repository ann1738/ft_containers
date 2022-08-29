#include "common.hpp"

static std::string	to_string(int _n){
	std::stringstream s;
	s << _n;
	return s.str();
}

int main()
{
	/*const_iterators*/
	std::cout << "********** Testing Const_iterators: **********" << std::endl;
	std::list<std::string> myNameIsListy;
	for (int i = -10000; i < 10000; ++i)
		myNameIsListy.push_back(to_string(i));
	
	const ft::set<std::string> st(myNameIsListy.begin(), myNameIsListy.end());

	ft::set<std::string>::const_iterator it = st.begin();
	ft::set<std::string>::const_iterator ite = st.end();

	for(; it != ite; ++it)
		std::cout << *it << " - ";
	std::cout << std::endl;
	
	it = st.begin();
	ite--;

	for(; ite != it; --ite)
		std::cout << *ite << " - ";
	std::cout << std::endl;

	ft::set<std::string>::const_reverse_iterator rit = st.rbegin();
	ft::set<std::string>::const_reverse_iterator rite = st.rend();

	for(; rit != rite; ++rit)
		std::cout << *rit << " - ";
	std::cout << std::endl;
	
	rit = st.rbegin();
	rite--;

	for(; rite != rit; --rite)
		std::cout << *rite << " - ";
	std::cout << std::endl;
			
	/*relational operators for const_iterators*/
	it = st.begin();
	ite = st.end();

	std::cout << (it == ite) << std::endl;
	std::cout << (it != ite) << std::endl;
}