#include "common.hpp"

int main()
{
	/*key_comp*/
	std::cout << "# key_comp() #" << std::endl;

	ft::set<float> st;
	ft::set<float>::key_compare keyCompReplica = st.key_comp();
	for (float f = 1.1; f < 10; f += 1.1)
		st.insert(f);
	
	ft::set<float>::iterator it = st.begin();
	for (; keyCompReplica(*it, *st.rbegin()); ++it)
		std::cout << *it << " - " << std::endl;			
	
	/*value_comp*/
	std::cout << "# value_comp() #" << std::endl;
	for (it = st.begin(); st.value_comp()(*it, *st.rbegin()); ++it)
		std::cout << *it << " - " << std::endl;
}