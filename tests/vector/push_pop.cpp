#include "common.hpp"

static std::string	to_string(int _n){
	std::stringstream s;
	s << _n;
	return s.str();
}

int main()
{
	/*push_back, pop_back*/
	std::cout << "# push_back() and pop_back() #" << std::endl;
	ft::vector<std::string> vecStr;
	printContainer(vecStr);
	vecStr.push_back("FIRST");
	printContainer(vecStr);
	vecStr.push_back("SECOND");
	for (int i = 0; i < 100000; ++i) 
	{
		std::cout << vecStr.capacity() << "*" << vecStr.size() << " - ";
		vecStr.push_back(to_string(i));
	}
	std::cout << std::endl;
	printContainer(vecStr);
	for (; !vecStr.empty();) 
	{
		std::cout << vecStr.capacity() << "*" << vecStr.size() << " - ";
		vecStr.pop_back();
	}
	std::cout << std::endl;
	printContainer(vecStr);
}