/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:54:51 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/11 12:00:27 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::cout << "\033[1;33mInitializing tests...\033[0m" << std::endl;
	std::cout << "\033[1;34mTest 1: using easyfind() on a vector and finding the number.\033[0m" << std::endl;
	try
	{
		std::vector<int> numbers;

		numbers.push_back(1);
		numbers.push_back(4);
		numbers.push_back(2);
		numbers.push_back(98);
		numbers.push_back(56);

		easyfind(numbers, 56);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\033[1;34mTest 2: using easyfind() on a list and not finding the number.\033[0m" << std::endl;
	try
	{
		std::list<int> numbers2;

		numbers2.push_back(1);
		numbers2.push_back(104);
		numbers2.push_back(27);
		numbers2.push_back(98);
		numbers2.push_back(56);

		easyfind(numbers2, 105);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return(0);
}
