#include "common.hpp"

static std::string	to_string(int _n){
	std::stringstream s;
	s << _n;
	return s.str();
}

int main()
{
	/*iterators*/
	std::cout << "********** Testing Iterators: **********" << std::endl;
	ft::vector<std::string> vecStr;
	for (int i = 0; i < 10; ++i) vecStr.push_back(to_string(i));

	ft::vector<std::string>::iterator it = vecStr.begin();
	ft::vector<std::string>::iterator ite = vecStr.end();
	
	for (; it != ite; ++it) std::cout << *it << std::endl;
	it = vecStr.begin();
	ite--;
	for (; ite != it;  --ite) std::cout << *ite << std::endl;

	ft::vector<std::string>::reverse_iterator rit = vecStr.rbegin();
	ft::vector<std::string>::reverse_iterator rite = vecStr.rend();
	
	for (; rit != rite; ++rit) std::cout << *rit << std::endl;
	rit = vecStr.rbegin();
	rite--;
	for (; rite != rit;  --rite) std::cout << *rite << std::endl;

	/*relational operators for iterators*/
	it = vecStr.begin();
	ite = vecStr.end();

	std::cout << (it == ite) << std::endl;
	std::cout << (it != ite) << std::endl;
	std::cout << (it < ite) << std::endl;
	std::cout << (it <= ite) << std::endl;
	std::cout << (it > ite) << std::endl;
	std::cout << (it >= ite) << std::endl;

	/*relational operators between iterators and const_iterator*/
	ft::vector<std::string>::const_iterator cit = vecStr.begin();
	ft::vector<std::string>::const_iterator cite = vecStr.end();

	std::cout << (it == cite) << std::endl;
	std::cout << (it != cite) << std::endl;
	std::cout << (it < cite) << std::endl;
	std::cout << (it <= cite) << std::endl;
	std::cout << (it > cite) << std::endl;
	std::cout << (it >= cite) << std::endl;

	std::cout << (cit == ite) << std::endl;
	std::cout << (cit != ite) << std::endl;
	std::cout << (cit < ite) << std::endl;
	std::cout << (cit <= ite) << std::endl;
	std::cout << (cit > ite) << std::endl;
	std::cout << (cit >= ite) << std::endl;
}