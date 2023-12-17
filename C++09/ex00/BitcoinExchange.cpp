/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:42:48 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/14 18:00:59 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
	*this = obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
	if(this != &obj)
	{
		_databaseValues = obj._databaseValues;
	}
	return(*this);
}

BitcoinExchange::~BitcoinExchange()
{
	if(_inputFile.is_open())
		_inputFile.close();
	if(_databaseFile.is_open())
		_databaseFile.close();
	_databaseValues.clear();
}

void	BitcoinExchange::splitDatabase()
{
	_databaseFile.open("data.csv", std::ifstream::in);
	if(!_databaseFile.is_open())
		throw std::runtime_error("Error opening the files.");

	std::string	dbContent;
	std::string	date;
	std::string	valueAsString;
	size_t		commaPos;
	float		value;
	std::getline(_databaseFile, dbContent);

	while(std::getline(_databaseFile, dbContent))
	{
		commaPos = dbContent.find(",");
		date = dbContent.substr(0, commaPos);
		valueAsString = dbContent.substr(commaPos + 1, dbContent.size());
		value = atof(valueAsString.c_str());
		std::cout << "Date: " << date;
		std::cout << " Value: " << std::setprecision(7) << value << std::endl;
		//std::cout << date << "," << std::setprecision(7) << value << std::endl;
		_databaseValues[date] = value;
	}
}

/* void	BitcoinExchange::getInputLines()
{
	_inputFile.open(filename, std::ifstream::in);
	if(!_inputFile.is_open())
		throw std::runtime_error("Error opening the files.");

	std::string content;
	while(std::getline(_inputFile, content))
	{
		std::cout << content << std::endl;
	}
} */
