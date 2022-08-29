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
	std::list< ft::pair<int, std::string> > myNameIsListy;
	for (int i = 0; i < 10000; ++i)
		myNameIsListy.push_back(ft::make_pair(i, ::to_string(i)));

	ft::map<int, std::string> mp(myNameIsListy.begin(), myNameIsListy.end());
	const ft::map<int, std::string> mpConst(myNameIsListy.begin(), myNameIsListy.end());
	
	ft::map<int, std::string>::key_type	findMe = 0;
	// non-const
	for (findMe = -100; findMe < 1100; findMe += 50)
		if (mp.find(findMe) != mp.end()) std::cout << mp.find(findMe)->second << std::endl;
	// const
	for (findMe = -100; findMe < 1100; findMe += 50)
		if (mpConst.find(findMe) != mpConst.end()) std::cout << mpConst.find(findMe)->second << std::endl;	

	/*count*/
	std::cout << "# count() #" << std::endl;
	for (findMe = -100; findMe < 1100; findMe += 30)
		std::cout << mpConst.count(findMe) << " - ";
	std::cout << std::endl;

	/*upper_bound*/
	std::cout << "# upper_bound() #" << std::endl;
	for (findMe = -100; findMe < 1100; findMe += 10)
		if (mp.upper_bound(findMe) != mp.end()) std::cout << mp.upper_bound(findMe)->second << std::endl;
	for (findMe = -100; findMe < 1100; findMe += 10)
		if (mpConst.upper_bound(findMe) != mpConst.end()) std::cout << mpConst.upper_bound(findMe)->second << std::endl;	
	/*lower_bound*/
	std::cout << "# lower_bound() #" << std::endl;
	for (findMe = -100; findMe < 1100; findMe += 10)
		if (mp.lower_bound(findMe) != mp.end()) std::cout << mp.lower_bound(findMe)->second << std::endl;
	for (findMe = -100; findMe < 1100; findMe += 10)
		if (mpConst.lower_bound(findMe) != mpConst.end()) std::cout << mpConst.lower_bound(findMe)->second << std::endl;

	/*equal_range*/
	std::cout << "# equal_range() #" << std::endl;
	for (findMe = -100; findMe < 1100; findMe += 10)
	{
		ft::pair< ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator > checkMe;
		checkMe = mp.equal_range(findMe);
		if (checkMe.first != mp.end())
			std::cout << checkMe.first->first << "->" << checkMe.first->second << " - ";
		if (checkMe.second != mp.end())
			std::cout << checkMe.second->first << "->" << checkMe.second->second << std::endl;
		ft::pair< ft::map<int, std::string>::const_iterator, ft::map<int, std::string>::const_iterator > checkMeConst;
		checkMeConst = mp.equal_range(findMe);
		if (checkMeConst.first != mp.end())
			std::cout << checkMeConst.first->first << "->" << checkMeConst.first->second << " - ";
		if (checkMeConst.second != mp.end())
			std::cout << checkMeConst.second->first << "->" << checkMeConst.second->second << std::endl;
	}
}