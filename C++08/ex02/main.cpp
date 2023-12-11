/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:07:42 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/11 18:36:08 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "\033[1;33mTesting with MutantStack\033[0m" << std::endl;
	std::cout << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
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

	std::cout << std::endl;
	std::cout << "\033[1;33mTesting with std::list\033[0m" << std::endl;
	std::cout << std::endl;

	std::list<int> list1;
	list1.push_back(5);
	list1.push_back(17);
	std::cout << list1.back() << std::endl;
	list1.pop_back();
	std::cout << list1.size() << std::endl;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(737);
	//[...]
	list1.push_back(0);
	std::list<int>::iterator it1 = list1.begin();
	std::list<int>::iterator ite1 = list1.end();
	++it1;
	--it1;
	while (it1 != ite1)
	{
		std::cout << *it1 << std::endl;
		++it1;
	}
	return 0;
}
