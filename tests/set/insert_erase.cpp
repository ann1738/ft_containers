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
	ft::set<std::string> st;
	/*first type*/
	for (int i = 0; i < 10000; ++i)
		st.insert(::to_string(i));
	printSetInfo(st);
	std::cout << *(st.insert(::to_string(0)).first) << std::endl;
	std::cout << (st.insert(::to_string(0)).second) << std::endl;
	std::cout << *(st.insert(::to_string(1000)).first) << std::endl;
	std::cout << (st.insert(::to_string(1000)).second) << std::endl;
	std::cout << (st.insert(::to_string(10000)).second) << std::endl;
	printSetInfo(st);

	/*second type (with hint)*/
	std::cout << *st.insert(st.end(), ::to_string(10001)) << std::endl;
	std::cout << *st.insert(st.end(), ::to_string(10000)) << std::endl;
	std::cout << *st.insert(st.end(), ::to_string(9000)) << std::endl;
	std::cout << *st.insert(st.end(), ::to_string(5000)) << std::endl;
	printSetInfo(st);

	/*third type (range)*/
	std::list<std::string> myNameIsListy;
	for (int i = 50000; i < 55000; ++i)
		myNameIsListy.push_back(::to_string(i));
	
	st.insert(myNameIsListy.begin(), myNameIsListy.end());
	printSetInfo(st);

	/*erase*/
	std::cout << "# erase() #" << std::endl;

	/*first type (with position)*/
	for (int i = 0; i < 1000; ++i)
	{
		st.erase(st.begin());
		if (i % 100 == 0)
			printSetInfo(st);
	}

	/*second type (with key)*/
	for (int i = 49950; i < 55050; ++i)
	{
		std::cout << st.erase(::to_string(i)) << " - ";
		if (i % 1000 == 0)
			printSetInfo(st);
	}
	std::cout << std::endl;

	/*third type (range)*/
	ft::set<std::string>::iterator rangeIte = st.begin();
	
	for (int i = 0; i < 10; ++i)
	{
		rangeIte = st.begin();
		for (int i = 0; i < 500; ++i, ++rangeIte);
		st.erase(st.begin(), rangeIte);
		printSetInfo(st);
	}
	st.erase(st.begin(), st.end());
	printSetInfo(st);
}