#include "common.hpp"

int main()
{
	/*swap*/
	std::cout << "# swap() #" << std::endl;

	ft::set<int> stA;
	for (int i = 0; i < 545; ++i)
		stA.insert(i);
	ft::set<int> stB;
	for (int i = -777; i < -111; ++i)
		stB.insert(i);
	ft::set<int>::iterator OldItA = stA.begin();
	ft::set<int>::iterator OldItB = stB.begin();

	stA.swap(stB);
	printSetInfo(stA);
	printSetInfo(stB);
	std::cout << "Check iterator validity: " << std::endl;
	std::cout << (OldItA == stB.begin()) << std::endl;
	std::cout << (OldItB == stA.begin()) << std::endl;

	/*clear*/
	std::cout << "# clear() #" << std::endl;
	stA.clear();
	printSetInfo(stA);
	stB.clear();
	printSetInfo(stB);
}