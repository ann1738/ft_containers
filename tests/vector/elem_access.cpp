#include "common.hpp"

int main()
{
	/*Element access*/
	std::cout << "********** Testing Element access: **********" << std::endl;
	ft::vector<int> vec;
	for (int i = 0; i < 100000; ++i) vec.push_back(i);
	std::cout << vec.front() << std::endl;
	std::cout << vec.back() << std::endl;
	for (ft::vector<int>::size_type i = 0; i < vec.size(); ++i) std::cout << vec[i] << "&" << vec.at(i) << " - ";
	std::cout << std::endl;
	try
	{
		std::cout << vec.at(100001) << std::endl;
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << vec.at(-1) << std::endl;
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
	vec.pop_back();
	vec.erase(vec.begin());
	std::cout << vec.front() << std::endl;
	std::cout << vec.back() << std::endl;
}
