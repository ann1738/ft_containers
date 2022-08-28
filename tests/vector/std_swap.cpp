#include "common.hpp"

int main()
{
	/*std::swap specialization*/
	std::cout << "# std::swap specialization #" << std::endl;
	ft::vector<int> vecA(10, 42);
	ft::vector<int> vecB(10, 1337);

	std::swap(vecA, vecB);
	printVectorInfo(vecA);
	printVectorInfo(vecB);
}