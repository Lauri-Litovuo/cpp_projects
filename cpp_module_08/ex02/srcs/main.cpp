#include "MutantStack.hpp"
 #include <iostream>
 #include <list>
 #include <vector>
 #include <stack>

 
 int main()
 {
	{
	std::cout << "subject test" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	}

	{
		std::cout << "Subject test with list" << std::endl;
		std::list<int> mlist;
		mlist.push_back(5);
		mlist.push_back(17);
		std::cout << mlist.back() << std::endl;
		mlist.pop_back();
		std::cout << "size: " << mlist.size() << std::endl;
		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		//[...]
		mlist.push_back(0);
		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mlist);
	}

	{
		std::cout << "Testing with char" << std::endl;
		MutantStack<char> mstack;
		mstack.push('a');
		mstack.push('b');
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size: " << mstack.size() << std::endl;
		mstack.push('c');
		mstack.push('d');
		mstack.push('e');
		//[...]
		mstack.push('z');
		MutantStack<char>::iterator it = mstack.begin();
		MutantStack<char>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<char> s(mstack);
	}

	{
		std::cout << "Testing with float" << std::endl;
		MutantStack<float> mstack;
		mstack.push(5.5f);
		mstack.push(17.5f);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size: " << mstack.size() << std::endl;
		mstack.push(3.5f);
		mstack.push(5.5f);
		mstack.push(737.5f);
		//[...]
		mstack.push(0.5f);
		MutantStack<float>::iterator it = mstack.begin();
		MutantStack<float>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<float> s(mstack);
	}

	{
		std::cout << "Testing with double" << std::endl;
		MutantStack<double> mstack;
		mstack.push(5.5);
		mstack.push(17.5);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size: " << mstack.size() << std::endl;
		mstack.push(3.5);
		mstack.push(5.5);
		mstack.push(737.5);
		//[...]
		mstack.push(0.5);
		MutantStack<double>::iterator it = mstack.begin();
		MutantStack<double>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<double> s(mstack);
	}

	{
		std::cout << "Testing with vector" << std::endl;
		std::vector <int> vec = {5, 17, 3, 5, 737, 0};
		MutantStack<int, std::vector<int>> mstack(vec);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size: " << mstack.size() << std::endl;
		mstack.push(3);
		std::cout << mstack.top() << std::endl;
		MutantStack<int, std::vector<int>>::iterator it = mstack.begin();
		MutantStack<int, std::vector<int>>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return 0;
 }