#include "common.hpp"

int main()
{
	/*swap*/
	std::cout << "# swap() #" << std::endl;
	ft::map<int, char> mpA;
	for (int i = 0; i < 4242; ++i)
		mpA.insert(ft::make_pair(i, 'A'));
	ft::map<int, char> mpB;
	for (int i = 0; i < 464; ++i)
		mpB.insert(ft::make_pair(i, 'B'));
	ft::map<int, char>::iterator OldItA = mpA.begin();
	ft::map<int, char>::iterator OldItB = mpB.begin();
	
	mpA.swap(mpB);
	printMapInfo(mpA);
	printMapInfo(mpB);
	std::cout << "Check iterator validity: " << std::endl;
	std::cout << (OldItA == mpB.begin()) << std::endl;
	std::cout << (OldItB == mpA.begin()) << std::endl;

	/*clear*/
	std::cout << "# clear() #" << std::endl;
	mpA.clear();
	printMapInfo(mpA);
	mpB.clear();
	printMapInfo(mpB);
}