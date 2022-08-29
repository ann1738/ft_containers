#include "common.hpp"

int main()
{
	/*relational operators*/
	std::cout << "# relational operators #" << std::endl;
	std::list<int> myNameIsListy;
	for (int i = 0; i < 10000; ++i)
		myNameIsListy.push_back(i);

	ft::set<int> stA(myNameIsListy.begin(), myNameIsListy.end());

	myNameIsListy.clear();
	for (int i = 0; i < 454; ++i)
		myNameIsListy.push_back(i);
	ft::set<int> stB(myNameIsListy.begin(), myNameIsListy.end());

	std::cout << (stA == stB) << std::endl;
	std::cout << (stA != stB) << std::endl;
	std::cout << (stA < stB) << std::endl;
	std::cout << (stA <= stB) << std::endl;
	std::cout << (stA > stB) << std::endl;
	std::cout << (stA >= stB) << std::endl;
}