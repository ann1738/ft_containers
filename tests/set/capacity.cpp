#include "common.hpp"

static std::string	to_string(int _n){
	std::stringstream s;
	s << _n;
	return s.str();
}

int main()
{
	/*empty*/
	std::cout << "********** Testing empty(): **********" << std::endl;

	ft::set<std::string> st;
	std::cout << st.empty() << std::endl;
	for (int i = 0; i < 100; ++i)
		st.insert(to_string(i));
	std::cout << st.empty() << std::endl;
	st.clear();
	std::cout << st.empty() << std::endl;
}