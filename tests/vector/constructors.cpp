#include "common.hpp"

static std::string	to_string(int _n){
	std::stringstream s;
	s << _n;
	return s.str();
}

int main()
{
	/*constructors, destructor, and copy assignemnt*/
	std::cout << "********** Testing constructors and copy assignment **********" << std::endl;
	
	ft::vector<int> vec;
	for (int i = 0; i < 100000; ++i) vec.push_back(i);
	printVectorInfo(vec);
	
	ft::vector<int> vec1(100000, 42);
	printVectorInfo(vec1);
	
	ft::vector<int> vec2(vec.begin(), vec.end());
	printVectorInfo(vec2);
	
	ft::vector<int> vec3(vec1);
	printVectorInfo(vec3);
	
	ft::vector<int> vec4;
	vec4 = vec3;
	printVectorInfo(vec4);
	
	ft::vector<std::string> vecStr;
	for (int i = 0; i < 100000; ++i) vecStr.push_back(to_string(i));
	printContainer(vecStr);
}