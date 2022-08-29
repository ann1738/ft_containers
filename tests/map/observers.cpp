#include "common.hpp"

int main()
{
	std::cout << "********** Testing Observers: **********" << std::endl;

	/*key_comp*/
	std::cout << "# key_comp() #" << std::endl;
	
	ft::map<float, char> mp;
	ft::map<float, char>::key_compare keyCompReplica = mp.key_comp();
	mp[1.1] = 'A';	mp[2.2] = 'B';	mp[3.3] = 'C';
	mp[4.4] = 'D';	mp[5.5] = 'E';	mp[6.6] = 'G';
	mp[7.7] = 'F';	mp[8.8] = 'K';	mp[9.9] = 'L';
	
	ft::map<float, char>::iterator it = mp.begin();
	for (; keyCompReplica(it->first, mp.rbegin()->first); ++it)
		std::cout << it->first << "->" << it->second << " - " << std::endl;			
	
	/*value_comp*/
	std::cout << "# value_comp() #" << std::endl;
	it = mp.begin();
	for (it = mp.begin(); mp.value_comp()(*it, *mp.rbegin()); ++it)
		std::cout << it->first << "->" << it->second << " - " << std::endl;
}