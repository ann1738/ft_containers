#include "common.hpp"

static std::string	to_string(int _n){
	std::stringstream s;
	s << _n;
	return s.str();
}

int main()
{
	/*find*/
	std::cout << "# find() #" << std::endl;
	std::list< std::string > myNameIsListy;
	for (int i = 0; i < 10000; ++i)
		myNameIsListy.push_back(::to_string(i));

	const ft::set<std::string> stConst(myNameIsListy.begin(), myNameIsListy.end());
	
	int	findMe = 0;
	for (findMe = -100; findMe < 1100; findMe += 50)
		if (stConst.find(to_string(findMe)) != stConst.end()) std::cout << *(stConst.find(to_string(findMe))) << std::endl;	

	/*count*/
	std::cout << "# count() #" << std::endl;
	for (findMe = -100; findMe < 1100; findMe += 30)
		std::cout << stConst.count(to_string(findMe)) << " - ";
	std::cout << std::endl;

	/*upper_bound*/
	for (findMe = -100; findMe < 1100; findMe += 10)
		if (stConst.upper_bound(to_string(findMe)) != stConst.end()) std::cout << *stConst.upper_bound(to_string(findMe)) << std::endl;	

	/*lower_bound*/
	for (findMe = -100; findMe < 1100; findMe += 10)
		if (stConst.lower_bound(to_string(findMe)) != stConst.end()) std::cout << *stConst.lower_bound(to_string(findMe)) << std::endl;

	/*equal_range*/
	std::cout << "# equal_range() #" << std::endl;
	for (findMe = -100; findMe < 1100; findMe += 10)
	{
		ft::pair< ft::set<std::string>::iterator, ft::set<std::string>::iterator > checkMeConst;
		checkMeConst = stConst.equal_range(to_string(findMe));
		if (checkMeConst.first != stConst.end())
			std::cout << *checkMeConst.first << " - ";
		if (checkMeConst.second != stConst.end())
			std::cout << *checkMeConst.second << std::endl;
	}
}