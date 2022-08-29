#include "common.hpp"

static std::string	to_string(int _n){
	std::stringstream s;
	s << _n;
	return s.str();
}

int main()
{
	/*insert*/
	std::cout << "# insert() #" << std::endl;
	ft::map<std::string, int> mp;
	/*first type*/
	for (int i = 0; i < 10000; ++i)
		mp.insert(ft::make_pair(::to_string(i), i));
	printMapInfo(mp);
	std::cout << (mp.insert(ft::make_pair(::to_string(0), 0)).first->second) << std::endl;
	std::cout << (mp.insert(ft::make_pair(::to_string(0), 0)).second) << std::endl;
	std::cout << (mp.insert(ft::make_pair(::to_string(1000), 1000)).first->second) << std::endl;
	std::cout << (mp.insert(ft::make_pair(::to_string(1000), 1000)).second) << std::endl;
	std::cout << (mp.insert(ft::make_pair(::to_string(10000), 10000)).second) << std::endl;
	printMapInfo(mp);

	/*second type (with hint)*/
	std::cout << mp.insert(mp.end(), ft::make_pair(::to_string(10001), 10001))->second << std::endl;
	std::cout << mp.insert(mp.end(), ft::make_pair(::to_string(10000), 10000))->second << std::endl;
	std::cout << mp.insert(mp.end(), ft::make_pair(::to_string(9000), 9000))->second << std::endl;
	std::cout << mp.insert(mp.end(), ft::make_pair(::to_string(5000), 9000))->second << std::endl;
	printMapInfo(mp);

	/*third type (range)*/
	std::list< ft::pair<std::string, int> > myNameIsListy;
	for (int i = 50000; i < 55000; ++i)
		myNameIsListy.push_back(ft::make_pair(::to_string(i), i));
	
	mp.insert(myNameIsListy.begin(), myNameIsListy.end());
	printMapInfo(mp);

	/*erase*/
	std::cout << "# erase() #" << std::endl;

	/*first type (with position)*/
	ft::map<std::string, int>::iterator it = mp.begin();
	for (int i = 0; i < 1000; ++i, ++it)
	{
		it = mp.begin();
		mp.erase(it); //invalidates iterator
		if (i % 100 == 0)
			printMapInfo(mp);
	}

	/*second type (with key)*/
	for (int i = 49950; i < 55050; ++i)
	{
		std::cout << mp.erase(::to_string(i)) << " - ";
		if (i % 1000 == 0)
			printMapInfo(mp);
	}
	std::cout << std::endl;

	/*third type (range)*/
	ft::map<std::string, int>::iterator rangeIte = mp.begin();
	
	for (int i = 0; i < 10; ++i)
	{
		rangeIte = mp.begin();
		for (int i = 0; i < 500; ++i, ++rangeIte);
		mp.erase(mp.begin(), rangeIte);
		printMapInfo(mp);
	}
	mp.erase(mp.begin(), mp.end());
	printMapInfo(mp);
}