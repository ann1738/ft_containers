/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:10:24 by ann               #+#    #+#             */
/*   Updated: 2022/08/24 10:00:15 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../testing.hpp"
#include <vector>
#include <string>
#include <algorithm>

#ifdef TESTING
# define ft std
#endif
#define NAMESPACE ft

template < class T >
void	printContainer(const T & container){
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << "\t";
	std::cout << std::endl;
}

template< class T >
static void	printVectorInfo(const T & contatiner){
	std::cout << "Size: " << contatiner.size() << std::endl;
	std::cout << "Capacity: " << contatiner.capacity() << std::endl;
	std::cout << "Max Size: " << contatiner.max_size() << std::endl;
	std::cout << "Content: " << std::endl;
	printContainer(contatiner);
}

void	test_accuracy()
{
	{
		/*testing typenames*/
		std::cout << "********** Testing Typenames **********" << std::endl;
		ft::vector<int>::value_type a;
		ft::vector<int>::allocator_type b;
		ft::vector<int>::reference c = a;
		ft::vector<int>::const_reference d = a;
		ft::vector<int>::pointer e;
		ft::vector<int>::const_pointer f;
		ft::vector<int>::iterator g;
		ft::vector<int>::const_iterator h;
		ft::vector<int>::reverse_iterator i;
		ft::vector<int>::const_reverse_iterator j;
		ft::vector<int>::difference_type k;
		ft::vector<int>::size_type l;
		(void)a; (void)b; (void)c; (void)d; (void)e;
		(void)f; (void)g; (void)h; (void)i; (void)j;
		(void)k; (void)l;
	}

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
		for (int i = 0; i < 100000; ++i) vecStr.push_back(std::to_string(i));
		printContainer(vecStr);
	}
	{
		/*iterators*/
		std::cout << "********** Testing Iterators: **********" << std::endl;
		ft::vector<std::string> vecStr;
		for (int i = 0; i < 10; ++i) vecStr.push_back(std::to_string(i));
	
		ft::vector<std::string>::iterator it = vecStr.begin();
		ft::vector<std::string>::iterator ite = vecStr.end();
		for (; it != ite; ++it) std::cout << *it << std::endl;
		it = vecStr.begin();
		ite--;
		for (; ite != it;  --ite) std::cout << *ite << std::endl;

		ft::vector<std::string>::reverse_iterator rit = vecStr.rbegin();
		ft::vector<std::string>::reverse_iterator rite = vecStr.rend();
		
		for (; rit != rite; ++rit) std::cout << *rit << std::endl;
		rit = vecStr.rbegin();
		rite--;
		for (; rite != rit;  --rite) std::cout << *rite << std::endl;
	}
	{
		/*const_iterators*/
		std::cout << "********** Testing Const_iterators **********" << std::endl;
		const ft::vector<std::string> vecStr(10, "CONST");
	
		ft::vector<std::string>::const_iterator it = vecStr.begin();
		ft::vector<std::string>::const_iterator ite = vecStr.end();
		for (; it != ite; ++it) std::cout << *it << std::endl;
		it = vecStr.begin();
		ite--;
		for (; ite != it;  --ite) std::cout << *ite << std::endl;

		ft::vector<std::string>::const_reverse_iterator rit = vecStr.rbegin();
		ft::vector<std::string>::const_reverse_iterator rite = vecStr.rend();
		
		for (; rit != rite; ++rit) std::cout << *rit << std::endl;
		rit = vecStr.rbegin();
		rite--;
		for (; rite != rit;  --rite) std::cout << *rite << std::endl;
	}
	{
		/*Capacity functions*/
		std::cout << "********** Testing Capacity Functions **********" << std::endl;
		{
			/*resize*/
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
			ft::vector<int> vec;
			std::cout << vec.empty() << std::endl;
			vec.push_back(424242);
			std::cout << vec.empty() << std::endl;
			vec.clear();
			std::cout << vec.empty() << std::endl;
		}
		{
			/*reserve*/
			ft::vector<int> vec;
			vec.reserve(1);
			printVectorInfo(vec);
			vec.reserve(0);
			printVectorInfo(vec);
			vec.reserve(100000);
			printVectorInfo(vec);
			vec.reserve(10);
			printVectorInfo(vec);
		}
	}

#if 0	
	//vector<int>
	std::cout << "testing"<< std::endl;
	{
		ft::vector<int> mine;
		std::vector<int> strd;

		myAssert(mine.empty() == strd.empty());


		myAssert(mine.max_size() == strd.max_size());
		myAssert(mine.size() == strd.size());
		myAssert(mine.capacity() == strd.capacity());
		mine.assign(7, 100);
		strd.assign(7, 100);

		// mine.resize(1000);
		// strd.resize(1000);
		// std::cout << mine.size() << " == " << strd.size() << std::endl;
		// std::cout << mine.capacity() << " == " << strd.capacity() << std::endl;

		myAssert(mine.size() == strd.size());
		myAssert(mine.capacity() == strd.capacity());
		myAssert(mine.front() == strd.front());
		myAssert(mine.back() == strd.back());

		for (int i = 0; i < 100000; ++i)
		{
			mine.push_back(i);
			strd.push_back(i);
			myAssert(mine.size() == strd.size());
			myAssert(mine.capacity() == strd.capacity());
			myAssert(mine.back() == strd.back());
		}
		
		myAssert(mine.empty() == strd.empty());

		mine.reserve(1);
		strd.reserve(1);
		myAssert(mine.back() == strd.back());
		myAssert(mine.size() == strd.size());
		myAssert(mine.capacity() == strd.capacity());

		mine.reserve(200000);
		strd.reserve(200000);
		myAssert(mine.back() == strd.back());
		myAssert(mine.size() == strd.size());
		myAssert(mine.capacity() == strd.capacity());	
		
		mine.resize(1, 42);
		strd.resize(1, 42);
		myAssert(mine.back() == strd.back());
		myAssert(mine.size() == strd.size());
		myAssert(mine.capacity() == strd.capacity());

		mine.resize(100);
		strd.resize(100);
		myAssert(mine.back() == strd.back());
		myAssert(mine.size() == strd.size());
		myAssert(mine.capacity() == strd.capacity());

		mine.resize(200001);
		strd.resize(200001);
		myAssert(mine.back() == strd.back());
		myAssert(mine.size() == strd.size());
		myAssert(mine.capacity() == strd.capacity());

		for (ft::vector<int>::iterator it = mine.begin(); it != mine.end(); ++it)
			*it = 42;
		for (std::vector<int>::iterator it = strd.begin(); it != strd.end(); ++it)
			*it = 42;
		for (ft::vector<int>::size_type i = 0; i < mine.size() && i < strd.size(); ++i)
		{
			myAssert(mine[i] == strd[i]);
			myAssert(mine.at(i) == strd.at(i));	
		}

		for (ft::vector<int>::reverse_iterator rit = mine.rbegin(); rit != mine.rend(); ++rit)
			*rit = 24;
		for (std::vector<int>::reverse_iterator rit = strd.rbegin(); rit != strd.rend(); ++rit)
			*rit = 24;
		for (ft::vector<int>::size_type i = 0; i < mine.size() && i < strd.size(); ++i)
		{
			myAssert(mine[i] == strd[i]);
			myAssert(mine.at(i) == strd.at(i));	
		}
		
		try{
			mine.at(mine.size() + 1);
			myAssert(false);
		}
		catch(std::exception & e){}
		
		try{
			strd.at(strd.size() + 1);
			myAssert(false);
		}
		catch(std::exception & e){}

		ft::vector<int> mineEqual;
		mineEqual = mine;
		std::vector<int> strdEqual;
		strdEqual = strd;
		

		for (ft::vector<int>::size_type i = 0; i < mineEqual.size() && i < strdEqual.size(); ++i)
		{
			mineEqual.pop_back();
			strdEqual.pop_back();
			myAssert(mineEqual.back() == strdEqual.back());
			myAssert(mineEqual.size() == strdEqual.size());
			myAssert(mineEqual.capacity() == strdEqual.capacity());
		}
		
		myAssert(mineEqual.empty() == strdEqual.empty());

		ft::vector<int> mineCopy(mine);
		std::vector<int> strdCopy(strd);

		for (ft::vector<int>::size_type i = 0; i < mineCopy.size() && i < strdCopy.size(); ++i)
		{
			mineCopy.pop_back();
			strdCopy.pop_back();
			myAssert(mineCopy.back() == strdCopy.back());
			myAssert(mineCopy.size() == strdCopy.size());
			myAssert(mineCopy.capacity() == strdCopy.capacity());
		}
		
		myAssert(mineCopy.empty() == strdCopy.empty());
		
		ft::vector<int> mineSwap(100, 1337);
		std::vector<int> strdSwap(100, 1337);

		mineSwap.swap(mine);
		strdSwap.swap(strd);
		
		myAssert(mineSwap.size() == strdSwap.size());
		myAssert(mineSwap.capacity() == strdSwap.capacity());

		for (ft::vector<int>::size_type i = 0; i < mine.size() && i < strd.size(); ++i)
		{
			myAssert(mine[i] == strd[i]);
			myAssert(mine.at(i) == strd.at(i));	
		}
		for (ft::vector<int>::size_type i = 0; i < mineSwap.size() && i < strdSwap.size(); ++i)
		{
			myAssert(mineSwap[i] == strdSwap[i]);
			myAssert(mineSwap.at(i) == strdSwap.at(i));	
		}
		
		mineSwap.clear();
		strdSwap.clear();
		
		myAssert(mineSwap.size() == strdSwap.size());
		myAssert(mineSwap.capacity() == strdSwap.capacity());

		ft::vector<int> mineRange(mine.begin(), mine.end());
		std::vector<int> strdRange(strd.begin(), strd.end());

		for (ft::vector<int>::size_type i = 0; i < mineRange.size() && i < strdRange.size(); ++i)
		{
			myAssert(mineRange[i] == mine[i]);
			myAssert(strdRange[i] == strd[i]);
			myAssert(mineRange[i] == strdRange[i]);
		}
		
		mineRange.erase(mineRange.begin() + 10);
		strdRange.erase(strdRange.begin() + 10);
		mineRange.erase(mineRange.begin(), mineRange.begin() + 5);
		strdRange.erase(strdRange.begin(), strdRange.begin() + 5);
		// std::cout << mineRange.size() << " == " << strdRange.size() << std::endl;
		myAssert(mineSwap.size() == strdSwap.size());
		myAssert(mineSwap.capacity() == strdSwap.capacity());


		mine.resize(0);
		strd.resize(0);
		for (ft::vector<int>::size_type i = 0; i < 100; ++i)
		{
			mine.push_back(i);
			strd.push_back(i);
		}
		mineRange.assign(mine.begin(), mine.end());
		strdRange.assign(strd.begin(), strd.end());
		for (ft::vector<int>::size_type i = 0; i < mineRange.size() && i < strdRange.size(); ++i)
			myAssert(mineRange[i] == strdRange[i]);
		
		mineRange.erase(mineRange.begin() + 10);
		strdRange.erase(strdRange.begin() + 10);
		
		myAssert(mineSwap.size() == strdSwap.size());
		myAssert(mineSwap.capacity() == strdSwap.capacity());
		for (ft::vector<int>::size_type i = 0; i < mineRange.size() && i < strdRange.size(); ++i)
			myAssert(mineRange[i] == strdRange[i]);

		mineRange.erase(mineRange.begin() + 3, mineRange.begin() + 7);
		strdRange.erase(strdRange.begin() + 3, strdRange.begin() + 7);
		
		myAssert(mineSwap.size() == strdSwap.size());
		myAssert(mineSwap.capacity() == strdSwap.capacity());
		for (ft::vector<int>::size_type i = 0; i < mineRange.size() && i < strdRange.size(); ++i)
			myAssert(mineRange[i] == strdRange[i]);

		// myAssert(*mineRange.insert(mineRange.begin() + 5, 42) == *strdRange.insert(strdRange.begin() + 5, 42));
		// myAssert(*mineRange.insert(mineRange.begin() + 5, 42) == *strdRange.insert(strdRange.begin() + 5, 42));
		// myAssert(*mineRange.insert(mineRange.begin() + 5, 42) == *strdRange.insert(strdRange.begin() + 5, 42));
		// myAssert(*mineRange.insert(mineRange.begin() + 5, 42) == *strdRange.insert(strdRange.begin() + 5, 42));
		// myAssert(*mineRange.insert(mineRange.begin() + 2, 42) == *strdRange.insert(strdRange.begin() + 2, 42));
		// myAssert(*mineRange.insert(mineRange.begin() + 2, 42) == *strdRange.insert(strdRange.begin() + 2, 42));
		// mineRange.insert(mineRange.begin(), 15, 42);
		// strdRange.insert(strdRange.begin(), 15, 42);

		DEBUG();
		// mineRange.insert(mineRange.begin(), mine.begin(), mine.begin() + 6);
		// strdRange.insert(strdRange.begin(), strd.begin(), strd.begin() + 6);

		// std::cout << mineRange.size() << " == " << strdRange.size() << std::endl;
		// std::cout << mineRange.capacity() << " == " << strdRange.capacity() << std::endl;
		// myAssert(mineSwap.size() == strdSwap.size());
		// myAssert(mineSwap.capacity() == strdSwap.capacity());

		// return ;
		// for (ft::vector<int>::size_type i = 0; i < mineRange.size() && i < strdRange.size(); ++i)
		// {	std::cout << mineRange[i] << " == " << strdRange[i] << std::endl;
		// 	myAssert(mineRange[i] == strdRange[i]);}

		// mineRange.insert(mineRange.begin(), mine.begin(), mine.begin() + 2); 
		// s.insert(mineRange.begin(), mine.begin(), mine.begin() + 2);

		myAssert((strdRange == strdRange) && (mineRange == mineRange));
		myAssert(!(strdRange != strdRange) && !(mineRange != mineRange));
		myAssert(!(strdRange < strdRange) && !(mineRange < mineRange));
		myAssert((strdRange <= strdRange) && (mineRange <= mineRange));
		myAssert(!(strdRange > strdRange) && !(mineRange > mineRange));
		myAssert((strdRange >= strdRange) && (mineRange >= mineRange));
		
		ft::vector<int> mineIns(3, 42);
		std::vector<int> strdIns(3, 42);

		mineIns.insert(mineIns.begin() + 1, mine.begin(), mine.begin() + 3);
		strdIns.insert(strdIns.begin() + 1, strd.begin(), strd.begin() + 3);

	}
	#endif
	DEBUG();
}

 void	test_performance()
{
	int amount = 100000000;
	std::cout << "\e[34mInsertion: (" << amount << " elements)\e[0m" << std::endl;
	{
		std::cout << "ft::vector:" << std::endl;
		std::cout << "Insertion: ";
		timer *T1 = new timer();
		ft::vector<int> mine;
		for (int i = 0; i < amount; ++i) mine.push_back(i);
		delete T1;

		std::cout << "Searching: ";
		timer *T2 = new timer();
		ft::find(mine.begin(), mine.end(), amount / 10);
		ft::find(mine.begin(), mine.end(), amount / 7);
		ft::find(mine.begin(), mine.end(), amount / 5);
		ft::find(mine.begin(), mine.end(), amount / 3);
		ft::find(mine.begin(), mine.end(), amount / 1);
		delete T2;
		
		std::cout << "Deletion: ";
		// timer *T3 = new timer();
		timer T4;
		mine.erase(mine.begin(), mine.end());
		// delete T3;

		// timer *T1 = new timer();
		// timer *T1 = new timer();
		// timer *T1 = new timer();
		// timer *T1 = new timer();
		
	}
	{
		std::cout << "std::vector:" << std::endl;
		std::cout << "Insertion: ";
		timer *T1 = new timer();
		std::vector<int> mine;
		for (int i = 0; i < amount; ++i) mine.push_back(i);
		delete T1;

		std::cout << "Searching: ";
		timer *T2 = new timer();
		std::find(mine.begin(), mine.end(), amount / 10);
		std::find(mine.begin(), mine.end(), amount / 7);
		std::find(mine.begin(), mine.end(), amount / 5);
		std::find(mine.begin(), mine.end(), amount / 3);
		std::find(mine.begin(), mine.end(), amount / 1);
		delete T2;

		std::cout << "Deletion: ";
		timer T4;
		// timer *T3 = new timer();
		mine.erase(mine.begin(), mine.end());
		// delete T3;

	}
}

void	test_vector()
{
	test_accuracy();
	// test_performance();
}
