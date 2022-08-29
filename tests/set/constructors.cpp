#include "common.hpp"

int main()
{
	/*constructors, copy assignment, and destructor*/
	std::cout << "********** Testing constructors and copy assignment **********" << std::endl;
	
	std::list<int> myNameIsListy;
	for (int i = -1000; i < 1000; ++i)
		myNameIsListy.push_back(i);
	
	// default
	ft::set<int> st;
	for (int i = 0; i < 10000; ++i)
		st.insert(i);
	printSetInfo(st);

	// range
	ft::set<int> stRange(myNameIsListy.begin(), myNameIsListy.end());
	printSetInfo(stRange);

	// copy
	ft::set<int> stCopy(st);
	printSetInfo(stCopy);

	for (int i = 50000; i < 55000; ++i)
		stCopy.insert(i);
	printSetInfo(st);
	printSetInfo(stCopy);

	// copy assignment 
	ft::set<int> stCopyAssign;
	stCopyAssign = st;

	for (int i = 50000; i < 55000; ++i)
		stCopyAssign.insert(i);
	printSetInfo(st);
	printSetInfo(stCopy);
}