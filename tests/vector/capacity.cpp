#include "common.hpp"

int main()
{
	/*Capacity functions*/
	std::cout << "********** Testing Capacity Functions **********" << std::endl;
	{
		/*resize*/
		std::cout << "# resize() #" << std::endl;
		ft::vector<int> vec(100000, 42);
		printVectorInfo(vec);
		vec.resize(1, 42);
		printVectorInfo(vec);
		vec.resize(100001, 42);
		printVectorInfo(vec);
		vec.resize(100005, 42);
		printVectorInfo(vec);
		vec.resize(0, 42);
		printVectorInfo(vec);
		vec.resize(300005, 42);
		printVectorInfo(vec);
	}
	{
		/*empty*/
		std::cout << "# empty() #" << std::endl;
		ft::vector<int> vec;
		std::cout << vec.empty() << std::endl;
		vec.push_back(424242);
		std::cout << vec.empty() << std::endl;
		vec.clear();
		std::cout << vec.empty() << std::endl;
	}
	{
		/*reserve*/
		std::cout << "# reserve() #" << std::endl;
		ft::vector<int> vec;
		vec.reserve(1);
		printVectorInfo(vec);
		vec.reserve(0);
		printVectorInfo(vec);
		vec.reserve(100000);
		printVectorInfo(vec);
		vec.reserve(10);
		printVectorInfo(vec);
		// try
		// {
		// 	vec.reserve(4611686018427387904);
		// }
		// catch (std::exception & e){
		// 	std::cout << e.what() << std::endl;
		// }
	}
}