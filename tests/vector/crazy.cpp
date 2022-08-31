#include "common.hpp"

int main()
{
	ft::vector< ft::vector<int> > vec;

	vec.reserve(100);
	for (int i = 0; i < 50; ++i)
		vec.push_back(ft::vector<int>(1, i));
	
	vec.assign(vec.begin(), vec.end());
	
	for (ft::vector<ft::vector<int> >::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << it->front() << "\t";
	std::cout << std::endl;

	vec.insert(vec.begin() + 3, vec.begin(), vec.end());
	
	for (ft::vector<ft::vector<int> >::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << it->front() << "\t";
	std::cout << std::endl;
}