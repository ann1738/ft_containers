
#include "../testing.hpp"
#include <set>
#include <list>
#include <sstream>

#ifdef TESTING
# define ft std
#endif

static std::string	to_string(int _n){
	std::stringstream s;
	s << _n;
	return s.str();
}

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
	{
		/*const_iterators*/
		std::cout << "********** Testing Const_iterators: **********" << std::endl;
		std::list<std::string> myNameIsListy;
		for (int i = -10000; i < 10000; ++i)
			myNameIsListy.push_back(to_string(i));
		
		const ft::set<std::string> st(myNameIsListy.begin(), myNameIsListy.end());

		ft::set<std::string>::const_iterator it = st.begin();
		ft::set<std::string>::const_iterator ite = st.end();

		for(; it != ite; ++it)
			std::cout << *it << " - ";
		std::cout << std::endl;
		
		it = st.begin();
		ite--;
	
		for(; ite != it; --ite)
			std::cout << *ite << " - ";
		std::cout << std::endl;

		ft::set<std::string>::const_reverse_iterator rit = st.rbegin();
		ft::set<std::string>::const_reverse_iterator rite = st.rend();

		for(; rit != rite; ++rit)
			std::cout << *rit << " - ";
		std::cout << std::endl;
		
		rit = st.rbegin();
		rite--;
	
		for(; rite != rit; --rite)
			std::cout << *rite << " - ";
		std::cout << std::endl;
				
		/*relational operators for const_iterators*/
		it = st.begin();
		ite = st.end();

		std::cout << (it == ite) << std::endl;
		std::cout << (it != ite) << std::endl;
	}
	{
		/*empty*/
		std::cout << "********** Testing empty(): **********" << std::endl;

		ft::set<std::string> st;
		std::cout << st.empty() << std::endl;
		for (int i = 0; i < 100; ++i)
			st.insert(to_string(i));
		std::cout << st.empty() << std::endl;
		st.clear();
		std::cout << st.empty() << std::endl;
	}
	{
		/*Modifiers*/
		std::cout << "********** Testing Modifiers: **********" << std::endl;
		{
			/*insert*/
			std::cout << "# insert() #" << std::endl;
			ft::set<std::string> st;
			/*first type*/
			for (int i = 0; i < 10000; ++i)
				st.insert(::to_string(i));
			printSetInfo(st);
			std::cout << *(st.insert(::to_string(0)).first) << std::endl;
			std::cout << (st.insert(::to_string(0)).second) << std::endl;
			std::cout << *(st.insert(::to_string(1000)).first) << std::endl;
			std::cout << (st.insert(::to_string(1000)).second) << std::endl;
			std::cout << (st.insert(::to_string(10000)).second) << std::endl;
			printSetInfo(st);

			/*second type (with hint)*/
			std::cout << *st.insert(st.end(), ::to_string(10001)) << std::endl;
			std::cout << *st.insert(st.end(), ::to_string(10000)) << std::endl;
			std::cout << *st.insert(st.end(), ::to_string(9000)) << std::endl;
			std::cout << *st.insert(st.end(), ::to_string(5000)) << std::endl;
			printSetInfo(st);

			/*third type (range)*/
			std::list<std::string> myNameIsListy;
			for (int i = 50000; i < 55000; ++i)
				myNameIsListy.push_back(::to_string(i));
			
			st.insert(myNameIsListy.begin(), myNameIsListy.end());
			printSetInfo(st);

			/*erase*/
			std::cout << "# erase() #" << std::endl;

			/*first type (with position)*/
			ft::set<std::string>::iterator it = st.begin();
			for (int i = 0; i < 1000; ++i, ++it)
			{
				it = st.begin();
				st.erase(it);
				if (i % 100 == 0)
					printSetInfo(st);
			}

			/*second type (with key)*/
			for (int i = 49950; i < 55050; ++i)
			{
				std::cout << st.erase(::to_string(i)) << " - ";
				if (i % 1000 == 0)
					printSetInfo(st);
			}
			std::cout << std::endl;

			/*third type (range)*/
			ft::set<std::string>::iterator rangeIte = st.begin();
			
			for (int i = 0; i < 10; ++i)
			{
				rangeIte = st.begin();
				for (int i = 0; i < 500; ++i, ++rangeIte);
				st.erase(st.begin(), rangeIte);
				printSetInfo(st);
			}
			st.erase(st.begin(), st.end());
			printSetInfo(st);
		}
		{
			/*swap*/
			std::cout << "# swap() #" << std::endl;

			ft::set<int> stA;
			for (int i = 0; i < 545; ++i)
				stA.insert(i);
			ft::set<int> stB;
			for (int i = -777; i < -111; ++i)
				stB.insert(i);
			ft::set<int>::iterator OldItA = stA.begin();
			ft::set<int>::iterator OldItB = stB.begin();

			stA.swap(stB);
			printSetInfo(stA);
			printSetInfo(stB);
			std::cout << "Check iterator validity: " << std::endl;
			std::cout << (OldItA == stB.begin()) << std::endl;
			std::cout << (OldItB == stA.begin()) << std::endl;
		
			/*clear*/
			std::cout << "# clear() #" << std::endl;
			stA.clear();
			printSetInfo(stA);
			stB.clear();
			printSetInfo(stB);
		}
		{
			/*key_comp*/
			std::cout << "# key_comp() #" << std::endl;
				
			ft::set<float> st;
			ft::set<float>::key_compare keyCompReplica = st.key_comp();
			for (float f = 1.1; f < 10; f += 1.1)
				st.insert(f);
			
			ft::set<float>::iterator it = st.begin();
			for (; keyCompReplica(*it, *st.rbegin()); ++it)
				std::cout << *it << " - " << std::endl;			
			
			/*value_comp*/
			std::cout << "# value_comp() #" << std::endl;
			for (it = st.begin(); st.value_comp()(*it, *st.rbegin()); ++it)
				std::cout << *it << " - " << std::endl;
		}
		{
			/*find*/
			std::cout << "# find() #" << std::endl;
			std::list< std::string > myNameIsListy;
			for (int i = 0; i < 10000; ++i)
				myNameIsListy.push_back(::to_string(i));
		
			const ft::set<std::string> stConst(myNameIsListy.begin(), myNameIsListy.end());
			
			int	findMe = 0;
			// const
			for (findMe = -100; findMe < 1100; findMe += 50)
				if (stConst.find(to_string(findMe)) != stConst.end()) std::cout << *(stConst.find(to_string(findMe))) << std::endl;	

			/*count*/
			std::cout << "# count() #" << std::endl;
			for (findMe = -100; findMe < 1100; findMe += 30)
				std::cout << stConst.count(to_string(findMe)) << " - ";
			std::cout << std::endl;

			/*upper_bound*/
			for (findMe = -100; findMe < 1100; findMe += 10)
				if (stConst.upper_bound(to_string(findMe)) != stConst.end()) std::cout << *stConst.upper_bound(to_string(findMe)) << std::endl;	

			/*lower_bound*/
			for (findMe = -100; findMe < 1100; findMe += 10)
				if (stConst.lower_bound(to_string(findMe)) != stConst.end()) std::cout << *stConst.lower_bound(to_string(findMe)) << std::endl;

			/*equal_range*/
			std::cout << "# equal_range() #" << std::endl;
			for (findMe = -100; findMe < 1100; findMe += 10)
			{
				ft::pair< ft::set<std::string>::iterator, ft::set<std::string>::iterator > checkMeConst;
				checkMeConst = stConst.equal_range(to_string(findMe));
				if (checkMeConst.first != stConst.end())
					std::cout << *checkMeConst.first << " - ";
				if (checkMeConst.second != stConst.end())
					std::cout << *checkMeConst.second << std::endl;
			}
		}
		{
			/*get_allocator*/
			std::cout << "# get_allocator() #" << std::endl;
			ft::set<int> st;

			ft::set<int>::value_type *ptr = st.get_allocator().allocate(1000);

			for (int i = 0; i < 1000; ++i) st.get_allocator().construct(ptr + i, i);

			for (int i = 0; i < 1000; ++i) std::cout << ptr[i] << " - ";
			std::cout << std::endl;

			for (int i = 0; i < 1000; ++i) st.get_allocator().destroy(ptr + i);
			st.get_allocator().deallocate(ptr, 1000);
		}
	}
	{
		/*relational operators*/
		std::cout << "# relational operators #" << std::endl;
		std::list<int> myNameIsListy;
		for (int i = 0; i < 10000; ++i)
			myNameIsListy.push_back(i);
	
		ft::set<int> stA(myNameIsListy.begin(), myNameIsListy.end());

		myNameIsListy.clear();
		for (int i = 0; i < 454; ++i)
			myNameIsListy.push_back(i);
		ft::set<int> stB(myNameIsListy.begin(), myNameIsListy.end());

		std::cout << (stA == stB) << std::endl;
		std::cout << (stA != stB) << std::endl;
		std::cout << (stA < stB) << std::endl;
		std::cout << (stA <= stB) << std::endl;
		std::cout << (stA > stB) << std::endl;
		std::cout << (stA >= stB) << std::endl;
		
		/*std::swap specialization*/
		std::cout << "# std::swap specialization #" << std::endl;

		std::swap(stA, stB);
		printSetInfo(stA);
		printSetInfo(stB);
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