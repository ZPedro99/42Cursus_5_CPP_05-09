/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:35:54 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/11 17:28:51 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main()
{
	std::cout << "\033[1;33mInitializing tests...\033[0m" << std::endl;
	std::cout << "\033[1;34mTest 1: creating a set of numbers randomly.\033[0m" << std::endl;
	try
	{
		Span	numberSet(10);

		numberSet.generateNumbers();
		numberSet.printNumbers();

		numberSet.shortestSpan();
		numberSet.longestSpan();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	/* std::cout << std::endl;
	std::cout << "\033[1;34mTest 2: creating a set of numbers randomly and adding an extra one (going over the size).\033[0m" << std::endl;
	try
	{
		Span	numberSet(10);

		numberSet.generateNumbers();
		numberSet.printNumbers();

		numberSet.addNumber(1);

		numberSet.shortestSpan();
		numberSet.longestSpan();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\033[1;34mTest 3: creating a set of numbers with size 0.\033[0m" << std::endl;
	try
	{
		Span	numberSet(0);

		numberSet.generateNumbers();
		numberSet.printNumbers();

		numberSet.shortestSpan();
		numberSet.longestSpan();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\033[1;34mTest 4: creating a set of numbers with size 1.\033[0m" << std::endl;
	try
	{
		Span	numberSet(1);

		numberSet.generateNumbers();
		numberSet.printNumbers();

		numberSet.shortestSpan();
		numberSet.longestSpan();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\033[1;34mTest 4: creating a set of nicer numbers\033[0m" << std::endl;
	try
	{
		Span	numberSet(10);

		numberSet.addNumber(-54);
		numberSet.addNumber(23);
		numberSet.addNumber(1);
		numberSet.addNumber(0);
		numberSet.addNumber(12);
		numberSet.addNumber(30);
		numberSet.addNumber(10);
		numberSet.addNumber(77);
		numberSet.addNumber(100);
		numberSet.addNumber(42);

		numberSet.printNumbers();

		numberSet.shortestSpan();
		numberSet.longestSpan();

	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	} */
	/* Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl; */

	return(0);
}
