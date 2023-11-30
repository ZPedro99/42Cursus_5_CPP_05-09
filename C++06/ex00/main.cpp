/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:53:54 by jomirand          #+#    #+#             */
/*   Updated: 2023/11/29 11:16:07 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if(argc != 2)
	{
		return(std::cout << "Invalid number of arguments." << std::endl, 1);
	}
	std::string	literal(argv[1]);
	ScalarConverter::convert(literal);
	return(0);
}