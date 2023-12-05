/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:36:11 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/05 12:43:27 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	std::cout << "\033[1;33mTesting an array of chars\033[0m" << std::endl;

	char	array[] = {'1', '3', '2', '4', '5'};
	iter<char>(array, 5, print<char>);

	std::cout << std::endl;
	std::cout << "\033[1;33mTesting an array of ints\033[0m" << std::endl;

	int	array2[] = {1, 3, 2, 4, 5};
	iter<int>(array2, 5, print<int>);

	std::cout << std::endl;
	std::cout << "\033[1;33mTesting a string\033[0m" << std::endl;

	std::string	array3 = "ola";
	iter<const char>(array3.c_str(), array3.length(), print<const char>);

	std::cout << std::endl;
	std::cout << "\033[1;33mTesting an array of doubles\033[0m" << std::endl;

	double	array4[] = {1.5, 3.5, 2.5, 4.5, 5.5};
	iter<double>(array4, 5, print<double>);

	std::cout << std::endl;
	std::cout << "\033[1;33mTesting an array of ints but adding 5 to each one and printing\033[0m" << std::endl;

	int	array5[] = {1, 3, 2, 4, 5};
	iter<int>(array5, 5, add5<int>);
	iter<int>(array5, 5, print<int>);

	std::cout << std::endl;

	return(0);
}