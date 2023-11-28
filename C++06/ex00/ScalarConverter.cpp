/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:51:47 by jomirand          #+#    #+#             */
/*   Updated: 2023/11/28 18:01:12 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
	(void)obj;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& obj)
{
	(void)obj;
	return(*this);
}

ScalarConverter::~ScalarConverter() {}

bool	ScalarConverter::isChar(const std::string& literal)
{
	std::size_t length = literal.length();
	if(length != 1)
		return(false);
	if(literal[0] >= '0' && literal[0] <= '9')
		return(false);
	return(true);
}

bool	ScalarConverter::isInt(const std::string& literal)
{
	for(size_t i = 0; i < literal.length(); i++)
	{
		if(i == 0 && literal[i] == '-')
			continue;
		if(!isdigit(literal[i]))
			return(false);
	}

	long	num = atol(literal.c_str());
	if(num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
		return(false);
	return(true);
}

bool	ScalarConverter::isFloat(const std::string& literal)
{
	if(literal[literal.length() - 1] != 'f')
		return(false);
	if(literal.find_first_of('.') != literal.find_last_of('.') || literal.find('.') == std::string::npos)
		return(false);
	for(size_t i = 0; i < literal.length() -1; i++)
	{
		if(i == 0 && literal[i] == '-')
			continue;
		if(literal[i] == '.')
			continue;
		if(!isdigit(literal[i]))
			return(false);
	}
	double	num = strtod(literal.c_str(), NULL);
	if(num < std::numeric_limits<double>::min() || num > std::numeric_limits<double>::max())
		return(false);
	return(true);
}

bool	ScalarConverter::isDouble(const std::string& literal)
{
	if(literal.find_first_of('.') != literal.find_last_of('.') || literal.find('.') == std::string::npos)
		return(false);
	for(size_t i = 0; i < literal.length() -1; i++)
	{
		if(i == 0 && literal[i] == '-')
			continue;
		if(literal[i] == '.')
			continue;
		if(!isdigit(literal[i]))
			return(false);
	}
	return(true);
}

bool	ScalarConverter::isSpecial(const std::string& literal)
{
	if(literal == "-inff" || literal == "+inff" || literal == "nanf" || literal == "-inf" || literal == "+inf" || literal == "nan")
		return(true);
	return(false);
}

void	ScalarConverter::printChar(char literal)
{
	if(literal >= 32 && literal <= 126)
		std::cout << "char: '" << literal << "'"<< std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(literal) << std::endl;
	std::cout << "float: " << static_cast<float> (literal)<< ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(literal) << ".0" << std::endl;
}

void	ScalarConverter::printInt(int literal)
{
	if(literal >= 32 && literal <= 126)
		std::cout << "char: '" << static_cast<char>(literal) << "'"<< std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << literal << std::endl;
	std::cout << "float: " << static_cast<float> (literal)<< ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(literal) << ".0" << std::endl;
}

void	ScalarConverter::printSpecial(const std::string& literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if(literal == "-inff" || literal == "+inff" || literal == "nanf")
		std::cout << "float: " << literal << std::endl;
	else
		std::cout << "float: " << literal << "f" << std::endl;
	if(literal == "-inf" || literal == "+inf" || literal == "nan")
		std::cout << "double: " << literal << std::endl;
	else
		std::cout << literal.erase(literal.end() - 1) << std::endl;
}

void	ScalarConverter::convert(const std::string& literal)
{
	if(isChar(literal))
		printChar(literal[0]);
	else if(isInt(literal))
		printInt(atoi(literal.c_str()));
	/* else if(isFloat(literal))
		printFloat(literal);
	else if(isDouble(literal))
		printDouble(literal); */
	else if(isSpecial(literal))
		printSpecial(literal);
	else
		std::cout << "Not a valid type." << std::endl;
}

