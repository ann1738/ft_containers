#include "common.hpp"

int main()
{
	/*insert, */
	std::cout << "# insert() #" << std::endl;
	ft::vector<int> vec;
	for (int i = 0; i < 10000; ++i) vec.push_back(i);
	vec.insert(vec.begin(), 4242);
	vec.insert(vec.end() - 1, 4242);
	printContainer(vec);	
	vec.insert(vec.begin() + 1000, 4242);
	vec.insert(vec.begin() + 5000, 4242);
	vec.insert(vec.begin() + 7000, 4242);
	vec.insert(vec.begin() + 9000, 4242);
	printContainer(vec);
	
	vec.insert(vec.begin(), 5, 4242);
	vec.insert(vec.end() - 1, 5, 4242);
	printContainer(vec);
	vec.insert(vec.begin() + 500, 0, 4242);
	vec.insert(vec.begin() + 500, 5, 4242);
	vec.insert(vec.begin() + 1500, 5, 4242);
	vec.insert(vec.begin() + 2500, 5, 4242);
	vec.insert(vec.begin() + 4500, 5, 4242);
	vec.insert(vec.begin() + 5500, 5, 4242);
	vec.insert(vec.begin() + 6500, 5, 4242);
	vec.insert(vec.begin() + 7500, 5, 4242);
	vec.insert(vec.begin() + 8500, 5, 4242);
	vec.insert(vec.begin() + 9500, 5, 4242);
	printContainer(vec);

	std::list<int> myNameIsListy(1000, 1337);

	vec.insert(vec.begin(), myNameIsListy.begin(), myNameIsListy.end());
	vec.insert(vec.end() - 1, myNameIsListy.begin(), myNameIsListy.end());
	printContainer(vec);
	

	myNameIsListy.clear();
	myNameIsListy.assign(50, 1337);
	vec.insert(vec.begin() + 750, myNameIsListy.begin(), myNameIsListy.end());
	vec.insert(vec.begin() + 1750, myNameIsListy.begin(), myNameIsListy.end());
	vec.insert(vec.begin() + 2750, myNameIsListy.begin(), myNameIsListy.end());
	vec.insert(vec.begin() + 3750, myNameIsListy.begin(), myNameIsListy.end());
	vec.insert(vec.begin() + 4750, myNameIsListy.begin(), myNameIsListy.end());
	vec.insert(vec.begin() + 5750, myNameIsListy.begin(), myNameIsListy.end());
	vec.insert(vec.begin() + 6750, myNameIsListy.begin(), myNameIsListy.end());
	vec.insert(vec.begin() + 7750, myNameIsListy.begin(), myNameIsListy.end());
	vec.insert(vec.begin() + 8750, myNameIsListy.begin(), myNameIsListy.end());
	vec.insert(vec.begin() + 9750, myNameIsListy.begin(), myNameIsListy.end());
	printContainer(vec);

	/*erase*/
	std::cout << "# erase() #" << std::endl;
	vec.erase(vec.begin());
	vec.erase(vec.end() - 1);
	printContainer(vec);
	
	vec.erase(vec.begin() + 4);
	vec.erase(vec.begin() + 44);
	vec.erase(vec.begin() + 444);
	vec.erase(vec.begin() + 4444);
	printContainer(vec);
	
	vec.erase(vec.begin(), vec.begin() + 25);
	vec.erase(vec.begin() + 500, vec.begin() + 575);
	vec.erase(vec.begin() + 5000, vec.begin() + 5750);
	vec.erase(vec.begin() + 9000, vec.begin() + 9125);
	printContainer(vec);
	
	vec.erase(vec.begin(), vec.end());
	printContainer(vec);
}