#include "common.hpp"

int main()
{
	/*swap*/
	std::cout << "# swap() #" << std::endl;
	ft::vector<std::string> vecA(999, "A");
	ft::vector<std::string> vecB(9999, "BB");
	
	ft::vector<std::string>::iterator itOldA = vecA.begin();
	ft::vector<std::string>::iterator iteOldA = vecA.end();
	ft::vector<std::string>::iterator itOldB = vecB.begin();
	ft::vector<std::string>::iterator iteOldB = vecB.end();

	vecA.swap(vecB);
	printContainer(vecA);
	printContainer(vecB);
	
	std::cout << "Checking iterator validity:" << std::endl;
	std::cout << (itOldA == vecB.begin()) << std::endl;
	std::cout << (iteOldA == vecB.end()) << std::endl;
	std::cout << (itOldB == vecA.begin()) << std::endl;
	std::cout << (iteOldB == vecA.end()) << std::endl;
	
	/*clear*/
	std::cout << "# clear() #" << std::endl;
	vecA.clear();
	printContainer(vecA);
	vecB.clear();
	printContainer(vecB);
}