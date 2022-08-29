#include "common.hpp"

int main()
{
	/*empty*/
	std::cout << "********** Testing empty(): **********" << std::endl;
	ft::map<int, std::string> mp;
	std::cout << mp.empty() << std::endl;
	mp.insert(ft::make_pair(42, "HELLO"));
	std::cout << mp.empty() << std::endl;
	mp.clear();
	std::cout << mp.empty() << std::endl;
}