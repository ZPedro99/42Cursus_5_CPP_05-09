/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:17:38 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/26 16:43:17 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if(argc < 2)
		return(std::cout << "Error(1)" << std::endl, 1);
	for(int i = 1; i < argc; i++)
	{
		if(std::atol(argv[i]) < 0 || std::atol(argv[i]) > INT_MAX  || std::atol(argv[i]) < INT_MIN)
			return(std::cout << "Error(2)" << std::endl, 1);
		for(int j = 0; argv[i][j] != '\0'; j++)
		{
			if(!isdigit(argv[i][j]))
				return(std::cout << "Error(3)" << std::endl, 1);
		}
	}

	PmergeMe	numbers(argv, argc);

	numbers.sorting();
	return(0);
}