#include "../../set.hpp"
#include "timer.hpp"

#ifdef TESTING
# define ft std
#include <set>
#endif

int main()
{
	int amount = 100000;
	std::cout << "(" << amount << " elements)" << std::endl;
	std::cout << "Insertion: ";
	timer *T1 = new timer();
	ft::set<int> st;
	for (int i = 0; i < amount; ++i)
		st.insert(i);
	delete T1;

	std::cout << "Searching: ";
	timer *T2 = new timer();
	st.find(amount / 10);
	st.find(amount / 7);
	st.find(amount / 5);
	st.find(amount / 3);
	st.find(amount / 1);
	delete T2;
	
	std::cout << "Deletion: ";
	timer *T3 = new timer();
	st.erase(st.begin(), st.end());
	delete T3;
}