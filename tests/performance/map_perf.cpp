#include "../../map.hpp"
#include "timer.hpp"

#ifdef TESTING
# define ft std
#include <map>
#endif

int main()
{
	int amount = 100000;
	std::cout << "(" << amount << " elements)" << std::endl;
	std::cout << "Insertion: ";
	timer *T1 = new timer();
	ft::map<int, std::string> vec;
	for (int i = 0; i < amount; ++i)
		vec.insert(ft::make_pair<int, std::string>(i, "one"));
	delete T1;

	std::cout << "Searching: ";
	timer *T2 = new timer();
	vec.find(amount / 10);
	vec.find(amount / 7);
	vec.find(amount / 5);
	vec.find(amount / 3);
	vec.find(amount / 1);
	delete T2;
	
	std::cout << "Deletion: ";
	timer *T3 = new timer();
	vec.erase(vec.begin(), vec.end());
	delete T3;
}