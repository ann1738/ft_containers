
#include "../testing.hpp"
#include <set>
#include <list>
#include <sstream>

#ifdef TESTING
# define ft std
#endif

// static std::string	to_string(int _n){
// 	std::stringstream s;
// 	s << _n;
// 	return s.str();
// }

template < class T >
void	printContainer(const T & container){
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << "\t";
	std::cout << std::endl;
}

template< class T >
static void	printSetInfo(const T & contatiner){
	std::cout << "Size: " << contatiner.size() << std::endl;
	std::cout << "Max Size: " << contatiner.max_size() << std::endl;
	std::cout << "Content: " << std::endl;
	printContainer(contatiner);
}

static void	test_performance()
{

}

static void	test_accuracy()
{
	{
		/*testing typenames*/
		std::cout << "********** Testing Typenames **********" << std::endl;
		ft::set<int>::key_type a;
		ft::set<int>::value_type b;
		ft::set<int>::key_compare c;
		ft::set<int>::value_compare d;
		ft::set<int>::allocator_type e;
		ft::set<int>::reference f = b;
		ft::set<int>::const_reference g = b;
		ft::set<int>::pointer h = NULL;
		ft::set<int>::const_pointer i = h;
		ft::set<int>::iterator j;
		ft::set<int>::const_iterator k;
		ft::set<int>::reverse_iterator l;
		ft::set<int>::const_reverse_iterator m;
		ft::set<int>::difference_type n;
		ft::set<int>::size_type o;
		(void)a; (void)b; (void)c; (void)d; (void)e;
		(void)f; (void)g; (void)h; (void)i; (void)j;
		(void)k; (void)l; (void)m; (void)n; (void)o;
	}
	{
		/*constructors, copy assignment, and destructor*/
		std::cout << "********** Testing constructors and copy assignment **********" << std::endl;
		
		std::list<int> myNameIsListy(1000, 1337);
		
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
	{
		/*iterators*/
		std::cout << "********** Testing Iterators: **********" << std::endl;
		ft::set<int> st;
		for (int i = 0; i < 10000; ++i)
			st.insert(i);
		printSetInfo(st);

		ft::set<int>::iterator it = st.begin();
		ft::set<int>::iterator ite = st.end();

		for(; it != ite; ++it)
			std::cout << *it << " - ";
		std::cout << std::endl;
		
		it = st.begin();
		ite--;
	
		for(; ite != it; --ite)
			std::cout << *ite << " - ";
		std::cout << std::endl;

		ft::set<int>::reverse_iterator rit = st.rbegin();
		ft::set<int>::reverse_iterator rite = st.rend();

		for(; rit != rite; ++rit)
			std::cout << *rit << " - ";
		std::cout << std::endl;
		
		rit = st.rbegin();
		rite--;
	
		for(; rite != rit; --rite)
			std::cout << *rite << " - ";
		std::cout << std::endl;
				
		/*relational operators for iterators*/
		it = st.begin();
		ite = st.end();

		std::cout << (it == ite) << std::endl;
		std::cout << (it != ite) << std::endl;
		
		/*relational operators for iterators and const_iterators*/
		ft::set<int>::const_iterator cit = st.begin();
		ft::set<int>::const_iterator cite = st.end();

		std::cout << (it == cite) << std::endl;
		std::cout << (it != cite) << std::endl;

		std::cout << (cit == ite) << std::endl;
		std::cout << (cit != ite) << std::endl;
	}
}

void	test_set()
{
	#ifndef SPEED
		test_accuracy();
	#else
		test_performance();
	#endif
	(void)(test_performance);
}