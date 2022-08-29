#include "../../map.hpp"
#include <list>
#include <sstream>
#include <algorithm>
#include <utility>
#include "../../additional.hpp"

#ifdef TESTING
# define ft std
#include <map>
#endif

template < class T >
void	printContainer(const T & container){
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << it->first << "->" << it->second << "\t";
	std::cout << std::endl;
}

template< class T >
static void	printMapInfo(const T & contatiner){
	std::cout << "Size: " << contatiner.size() << std::endl;
	std::cout << "Max Size: " << contatiner.max_size() << std::endl;
	std::cout << "Content: " << std::endl;
	printContainer(contatiner);
}