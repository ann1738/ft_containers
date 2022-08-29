#include "common.hpp"

int main()
{
	/*const_iterators*/
	std::cout << "********** Testing Const_iterators: **********" << std::endl;
	
	ft::map<int, std::string> copyFromMe;
	for (int i = 0; i < 10000; ++i) copyFromMe.insert(ft::make_pair(i, "HELLO, WORLD!"));
	
	const ft::map<int, std::string> mp(copyFromMe.begin(), copyFromMe.end());
	
	ft::map<int, std::string>::const_iterator it = mp.begin();
	ft::map<int, std::string>::const_iterator ite = mp.end();
	
	for (; it != ite; ++it) std::cout << it->first << "->" << it->second << " - ";
	std::cout << std::endl;
	
	it = mp.begin();
	ite--;
	for (; ite != it; --ite) std::cout << ite->first << "->" << ite->second  << " - ";
	std::cout << std::endl;
	
	ft::map<int, std::string>::const_reverse_iterator rit = mp.rbegin();
	ft::map<int, std::string>::const_reverse_iterator rite = mp.rend();

	for (; rit != rite; ++rit) std::cout << rit->first << "->" << rit->second  << " - ";
	std::cout << std::endl;

	rit = mp.rbegin();
	rite--;
	for (; rite != rit; --rite) std::cout << ite->first << "->" << ite->second  << " - ";
	std::cout << std::endl;
	
	/*relational operators for const_iterators*/
	it = mp.begin();
	ite = mp.end();

	std::cout << (it == ite) << std::endl;
	std::cout << (it != ite) << std::endl;
}