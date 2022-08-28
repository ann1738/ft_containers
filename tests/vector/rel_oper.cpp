#include "common.hpp"

int main()
{
	/*relational operators*/
	std::cout << "# relational operators #" << std::endl;
	ft::vector<int> vecA(10, 42);
	ft::vector<int> vecB(10, 1337);

	std::cout << (vecA == vecB) << std::endl;
	std::cout << (vecA != vecB) << std::endl;
	std::cout << (vecA < vecB) << std::endl;
	std::cout << (vecA <= vecB) << std::endl;
	std::cout << (vecA > vecB) << std::endl;
	std::cout << (vecA >= vecB) << std::endl;
}