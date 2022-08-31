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

	vec.insert(vec.begin() + 1, ft::vector<int>(1, 1337));
	vec.insert(vec.begin() + 3, ft::vector<int>(1, 1337));
	vec.insert(vec.begin() + 5, ft::vector<int>(1, 1337));
	vec.insert(vec.begin() + 7, ft::vector<int>(1, 1337));

	vec.insert(vec.begin() + 1, 1, ft::vector<int>(1, 1337));
	vec.insert(vec.begin() + 3, 3, ft::vector<int>(1, 1337));
	vec.insert(vec.begin() + 5, 5, ft::vector<int>(1, 1337));
	vec.insert(vec.begin() + 7, 7, ft::vector<int>(1, 1337));

	vec.insert(vec.begin(), vec.begin(), vec.end());
	vec.insert(vec.begin() + 3, vec.begin(), vec.end());
	vec.insert(vec.begin() + 10, vec.begin(), vec.end());
	vec.insert(vec.end() - 1, vec.begin(), vec.end());

	
	for (ft::vector<ft::vector<int> >::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << it->back() << "\t";
	std::cout << std::endl;

	vec.erase(vec.begin());
	vec.erase(vec.begin() + 1);
	vec.erase(vec.begin() + 3);
	vec.erase(vec.begin() + 5);
	vec.erase(vec.begin() + 7);

	vec.erase(vec.begin(), vec.begin() + 1);
	vec.erase(vec.begin(), vec.begin() + 3);
	vec.erase(vec.begin(), vec.begin() + 5);
	vec.erase(vec.begin(), vec.begin() + 7);
}