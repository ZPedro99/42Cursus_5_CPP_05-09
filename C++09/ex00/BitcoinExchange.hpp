/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:42:46 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/20 12:04:25 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <ctype.h>

class BitcoinExchange
{
	private:
		std::ifstream					_inputFile;
		std::ifstream					_databaseFile;
		std::map<std::string, float>	_databaseValues;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange& operator=(const BitcoinExchange& obj);
		~BitcoinExchange();

		void	splitDatabase();
		void	getInputLines(char *filename);
		bool	checkCorrectDate(std::string line);
		bool	checkYear(std::string year);
		bool	checkMonth(std::string month);
		bool	checkDay(std::string day, std::string month, std::string year);
		bool	checkValue(std::string value, std::string line);
		bool	isLeapYear(int year);
		void	printCorrectOutput(std::string date, std::string vale);
};

#endif
