/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:11:32 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/20 16:54:54 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "Error: invalid number of arguments." << std::endl;
		return(1);
	}
	try
	{
		RPN	numberSet;

		numberSet.applyRPN(argv[1]);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return(0);
}