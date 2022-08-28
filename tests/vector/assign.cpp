#include "common.hpp"

int main()
{
	/*assign*/
	std::cout << "# assign() #" << std::endl;
	ft::vector<int> vec;
	vec.assign(10000, 42);
	printVectorInfo(vec);
	vec.assign(10, 42);
	printVectorInfo(vec);
	vec.assign(0, 42);
	printVectorInfo(vec);
	vec.assign(100000, 42);
	printVectorInfo(vec);
	vec.assign(100001, 42);
	printVectorInfo(vec);
	std::list<int> myNameIsListy(1000, 1337);
	vec.assign(myNameIsListy.begin(), myNameIsListy.end());
	printVectorInfo(vec);
}