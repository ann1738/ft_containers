#include "common.hpp"

static std::string	to_string(int _n){
	std::stringstream s;
	s << _n;
	return s.str();
}

int main()
{
	/*relational operators*/
	std::cout << "# relational operators #" << std::endl;
	std::list< ft::pair<int, std::string> > myNameIsListy;
	for (int i = 0; i < 10000; ++i)
		myNameIsListy.push_back(ft::make_pair(i, ::to_string(i)));

	ft::map<int, std::string> mpA(myNameIsListy.begin(), myNameIsListy.end());

	myNameIsListy.clear();
	for (int i = 0; i < 454; ++i)
		myNameIsListy.push_back(ft::make_pair(i, ::to_string(i)));
	ft::map<int, std::string> mpB(myNameIsListy.begin(), myNameIsListy.end());

	std::cout << (mpA == mpB) << std::endl;
	std::cout << (mpA != mpB) << std::endl;
	std::cout << (mpA < mpB) << std::endl;
	std::cout << (mpA <= mpB) << std::endl;
	std::cout << (mpA > mpB) << std::endl;
	std::cout << (mpA >= mpB) << std::endl;
}