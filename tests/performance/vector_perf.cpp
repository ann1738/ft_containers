#include "../../vector.hpp"
#include "timer.hpp"

#ifdef TESTING
# define ft std
#include <vector>
#endif

int main()
{
	int amount = 1000000;
	std::cout << "(" << amount << " elements)" << std::endl;
	std::cout << "Insertion: ";
	timer *T1 = new timer();
	ft::vector<int> vec;
	for (int i = 0; i < amount; ++i) vec.push_back(i);
	delete T1;

	std::cout << "Searching: ";
	timer *T2 = new timer();
	ft::find(vec.begin(), vec.end(), amount / 10);
	ft::find(vec.begin(), vec.end(), amount / 7);
	ft::find(vec.begin(), vec.end(), amount / 5);
	ft::find(vec.begin(), vec.end(), amount / 3);
	ft::find(vec.begin(), vec.end(), amount / 1);
	delete T2;
	
	std::cout << "Deletion: ";
	timer T4;
	vec.erase(vec.begin(), vec.end());
}