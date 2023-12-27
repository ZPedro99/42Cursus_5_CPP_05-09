/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:42:48 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/27 11:50:27 by jomirand         ###   ########.fr       */
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
		_databaseValues.clear();
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
		throw std::runtime_error("Error opening database file.");

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
		_databaseValues[date] = value;
	}
}

void	BitcoinExchange::getInputLines(char *filename)
{
	_inputFile.open(filename, std::ifstream::in);
	if(!_inputFile.is_open())
		throw std::runtime_error("Error opening input file.");
	std::string inputContent;
	if(!std::getline(_inputFile, inputContent)) //file without content
		return ;
	if(inputContent != "date | value")
		return ;
	while(std::getline(_inputFile, inputContent))
	{
		checkCorrectDate(inputContent);
	}
}

bool	BitcoinExchange::checkCorrectDate(std::string line)
{
	unsigned int pipeCount = 0;
	for(size_t i = 0; i < line.length(); i++)
	{
		if(line[i] == '|')
			pipeCount++;
	}
	if(pipeCount != 1)
		return(std::cout << "Error: bad input => " << line << std::endl, false);
	size_t		pipePos;
	pipePos = line.find("|");

	std::string	date;
	date = line.substr(0, pipePos);
	unsigned int dashCount = 0;
	for(size_t i = 0; i < line.length(); i++)
	{
		if(line[i] == '|')
			dashCount++;
	}
	if(dashCount != 1)
		return(std::cout << "Error: bad input => " << line << std::endl, false);
	if(date == "2009-01-01 ")
		return(std::cout << "Error: no current or previous date on database." << std::endl, false);

	std::string	year;
	year = date.substr(0, 4);
	if(checkYear(year) == false)
		return(std::cout << "Error: invalid year." << std::endl, false);

	std::string	month;
	month = date.substr(5, 2);
	if(checkMonth(month) == false)
		return(std::cout << "Error: invalid month." << std::endl, false);

	std::string	day;
	day = date.substr(5, 2);
	if(checkDay(day, month, year) == false)
		return(std::cout << "Error: invalid day." << std::cout, false);

	std::string	value;
	value = line.substr(pipePos + 2);
	if(checkValue(value, line) == false)
		return(false);

	printCorrectOutput(date, value);

	return(false);
}

bool	BitcoinExchange::checkYear(std::string year)
{
	for(unsigned int i = 0; i < year.length(); i++)
	{
		if(!isdigit(year[i]))
			return(false);
	}
	if(std::atoi(year.c_str()) < 2009)
		return(false);
	return(true);
}

bool	BitcoinExchange::checkMonth(std::string month)
{
	for(unsigned int i = 0; i < month.length(); i++)
	{
		if(!isdigit(month[i]))
			return(false);
	}
	if(std::atoi(month.c_str()) < 1 || std::atoi(month.c_str()) > 12)
		return(false);
	return(true);
}

bool	BitcoinExchange::checkDay(std::string day, std::string month, std::string year)
{
	for(unsigned int i = 0; i < day.length(); i++)
	{
		if(!isdigit(day[i]))
			return(false);
	}
	if(month == "02")
	{
		if(isLeapYear(std::atoi(year.c_str())) == true)
		{
			if(std::atoi(day.c_str()) < 1 || std::atoi(day.c_str()) > 29)
				return(false);
			else if(std::atoi(day.c_str()) < 1 || std::atoi(day.c_str()) > 28)
				return(false);
		}
	}
	else if(month == "04" || month == "06" || month == "09" || month == "11")
	{
		if(std::atoi(day.c_str()) < 1 || std::atoi(day.c_str()) > 30)
			return(false);
		else if(std::atoi(day.c_str()) < 1 || std::atoi(day.c_str()) > 31)
			return(false);
	}
	return(true);
}

bool	BitcoinExchange::checkValue(std::string value, std::string line)
{
	if(std::atof(value.c_str()) < 0.0)
		return(std::cout << "Error: not a positive number." << std::endl, false);
	if(std::atof(value.c_str()) > 1000.0)
		return(std::cout << "Error: too large a number." << std::endl, false);
	unsigned int	dotCount = 0;
	for(size_t i = 0; i < value.length(); i++)
	{
		if(value[0] == '.')
			return(std::cout << "Error: bad input => " << line << std::endl, false);
		if(value[i] == '.' && (!isdigit(value[i + 1]) || !isdigit(value[i - 1])))
			return(std::cout << "Error: bad input => " << line << std::endl, false);
		if(!isdigit(value[i]) && value[i] != '.')
			return(std::cout << "Error: bad input => " << line << std::endl, false);
	}
	if(dotCount > 1 || dotCount == value.length())
		return(std::cout << "Error: bad input => " << line << std::endl, false);
	return(true);
}

void	BitcoinExchange::printCorrectOutput(std::string date, std::string value)
{
	float		valueToUse = 0;
	std::map<std::string, float>::iterator it;
	for(it = _databaseValues.begin(); it != _databaseValues.end(); it++)
	{
		//std::cout << "iterator on: " << it->first << " and date is: " << date << std::endl;
		if(it->first > date)
		{
			--it;
			valueToUse = it->second;
			break;
		}
	}
	if(it == _databaseValues.end())
	{
		--it;
		valueToUse = it->second;
	}
	float	multipliedValue = std::atof(value.c_str()) * valueToUse;
	std::cout << date << " => " << value << " = " << multipliedValue << std::endl;
}

bool	BitcoinExchange::isLeapYear(int year)
{
	if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return(true);
	return(false);
}