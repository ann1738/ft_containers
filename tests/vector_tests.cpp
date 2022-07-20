/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:10:24 by ann               #+#    #+#             */
/*   Updated: 2022/07/20 15:01:36 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../testing.hpp"
#include <vector>
#include <algorithm>

// #define	myAssert(expr) (static_cast <bool> (expr) ? void (0) : static_cast <void> (std::cout << "\e[31mFailed\e[0m\n"))

void	test_accuracy()
{
	//vector<int>
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
	DEBUG();
}

static void	test_performance()
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
	test_performance();
}
