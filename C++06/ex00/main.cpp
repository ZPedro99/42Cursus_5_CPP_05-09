/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:53:54 by jomirand          #+#    #+#             */
/*   Updated: 2023/11/28 17:39:01 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "Invalid number of arguments." << std::endl;
		return(1);
	}
	ScalarConverter::convert(argv[1]);
	return(0);
}