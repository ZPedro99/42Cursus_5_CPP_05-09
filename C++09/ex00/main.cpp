/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:42:44 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/18 11:44:13 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return(1);
	}
	try
	{
		BitcoinExchange	btc;

		btc.splitDatabase();
		btc.getInputLines(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return(0);
}
