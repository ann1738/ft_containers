#include "common.hpp"

int main()
{
	/*Element Access*/
	std::cout << "********** Testing operator[]: **********" << std::endl;
	ft::map<int, std::string> mp;
	for (int i = 0; i < 100; ++i) mp.insert(ft::make_pair(i, "HELLO, WORLD!"));
	printMapInfo(mp);
	/*existing keys*/
	mp[1] = "One";
	printMapInfo(mp);
	mp[70] = "Seventy";
	printMapInfo(mp);
	mp[0] = "Zero";
	printMapInfo(mp);
	mp[99] = "Ninety Nine";
	printMapInfo(mp);

	/*new keys*/
	mp[-1] = "Negative One";
	printMapInfo(mp);
	mp[-70] = "Negative Seventy";
	printMapInfo(mp);
	mp[1000000] = "One Million";
	printMapInfo(mp);
	mp[-99] = "Negative Ninety Nine";
	printMapInfo(mp);
}