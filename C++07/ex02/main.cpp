/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:54:48 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/06 10:05:16 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"

int	main()
{
	try
	{
		Array<int>	arrayInt(5);
		for(unsigned int i = 0; i < arrayInt.size(); i++)
			std::cout << arrayInt[i] << std::endl;
		std::cout << "all indexes printed with success." << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Array<int>	arrayInt2(5);
		std::cout << arrayInt2[6] << std::endl;
		std::cout << "all indexes printed with success." << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Array<int>	arrayInt3(5);
		arrayInt3[6] = 25;
		std::cout << "all indexes printed with success." << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}