#include "common.hpp"

int main()
{
	/*const_iterators*/
	std::cout << "********** Testing Const_iterators **********" << std::endl;
	const ft::vector<std::string> vecStr(10, "CONST");

	ft::vector<std::string>::const_iterator it = vecStr.begin();
	ft::vector<std::string>::const_iterator ite = vecStr.end();
	for (; it != ite; ++it) std::cout << *it << std::endl;
	it = vecStr.begin();
	ite--;
	for (; ite != it;  --ite) std::cout << *ite << std::endl;

	ft::vector<std::string>::const_reverse_iterator rit = vecStr.rbegin();
	ft::vector<std::string>::const_reverse_iterator rite = vecStr.rend();
	
	for (; rit != rite; ++rit) std::cout << *rit << std::endl;
	rit = vecStr.rbegin();
	rite--;
	for (; rite != rit;  --rite) std::cout << *rite << std::endl;

	/*relational operators for const iterators*/
	it = vecStr.begin();
	ite = vecStr.end();

	std::cout << (it == ite) << std::endl;
	std::cout << (it != ite) << std::endl;
	std::cout << (it < ite) << std::endl;
	std::cout << (it <= ite) << std::endl;
	std::cout << (it > ite) << std::endl;
	std::cout << (it >= ite) << std::endl;
}