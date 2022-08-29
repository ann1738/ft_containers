#ifndef COMMON_HPP
#define COMMON_HPP

#include "../../set.hpp"
#include <list>
#include <sstream>

#ifdef TESTING
# define ft std
#include <set>
#endif

template < class T >
void	printContainer(const T & container){
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << "\t";
	std::cout << std::endl;
}

template< class T >
static void	printSetInfo(const T & contatiner){
	std::cout << "Size: " << contatiner.size() << std::endl;
	std::cout << "Max Size: " << contatiner.max_size() << std::endl;
	std::cout << "Content: " << std::endl;
	printContainer(contatiner);
}

#endif