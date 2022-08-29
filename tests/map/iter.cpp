#include "common.hpp"

int main()
{
	/*iterators*/
	std::cout << "********** Testing Iterators: **********" << std::endl;
	ft::map<int, std::string> mp;
	for (int i = 0; i < 10000; ++i) mp.insert(ft::make_pair(i, "HELLO, WORLD!"));
	ft::map<int, std::string>::iterator it = mp.begin();
	ft::map<int, std::string>::iterator ite = mp.end();
	
	for (; it != ite; ++it) std::cout << it->first << "->" << it->second << " - ";
	std::cout << std::endl;
	
	it = mp.begin();
	ite--;
	for (; ite != it; --ite) std::cout << ite->first << "->" << ite->second  << " - ";
	std::cout << std::endl;
	
	ft::map<int, std::string>::reverse_iterator rit = mp.rbegin();
	ft::map<int, std::string>::reverse_iterator rite = mp.rend();

	for (; rit != rite; ++rit) std::cout << rit->first << "->" << rit->second  << " - ";
	std::cout << std::endl;

	rit = mp.rbegin();
	rite--;
	for (; rite != rit; --rite) std::cout << ite->first << "->" << ite->second  << " - ";
	std::cout << std::endl;
	
	/*relational operators for iterators*/
	it = mp.begin();
	ite = mp.end();

	std::cout << (it == ite) << std::endl;
	std::cout << (it != ite) << std::endl;
	
	/*relational operators for iterators*/
	ft::map<int, std::string>::const_iterator cit = mp.begin();
	ft::map<int, std::string>::const_iterator cite = mp.end();

	std::cout << (it == cite) << std::endl;
	std::cout << (it != cite) << std::endl;

	std::cout << (cit == ite) << std::endl;
	std::cout << (cit != ite) << std::endl;
}