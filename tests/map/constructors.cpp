#include "common.hpp"

int main()
{
	/*constructors, copy assignment, and destructor*/
	std::cout << "********** Testing constructors and copy assignment **********" << std::endl;
	ft::map<int, std::string> mp;
	for (int i = 0; i < 10000; ++i) mp.insert(ft::make_pair(i, "HELLO, WORLD!"));
	printMapInfo(mp);
	ft::map<int, std::string> mp1(mp.begin(), mp.end());
	printMapInfo(mp1);
	ft::map<int, std::string> mp2(mp);
	printMapInfo(mp2);
	ft::map<int, std::string> mp3;
	mp3 = mp2;
	printMapInfo(mp3);
}