/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:51:47 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/04 11:33:26 by jomirand         ###   ########.fr       */
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
	if(num < -std::numeric_limits<float>::max() || num > std::numeric_limits<float>::max())
		return(false);
	return(true);
}

bool	ScalarConverter::isDouble(const std::string& literal)
{
	if(literal.find_first_of('.') != literal.find_last_of('.') || literal.find('.') == std::string::npos)
		return(false);
	for(size_t i = 0; i < literal.length(); i++)
	{
		if(i == 0 && literal[i] == '-')
			continue;
		if(literal[i] == '.')
			continue;
		if(!isdigit(literal[i]))
			return(false);
	}
	long double	num = strtold(literal.c_str(), NULL);
	if(num < -std::numeric_limits<double>::max() || num > std::numeric_limits<double>::max())
		return(false);
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
	{
		if((literal >= 0 && literal <= 32) || literal == 127)
			std::cout << "char: Non displayable" << std::endl;
		else if(literal > 127)
			std::cout << "char: overflow" << std::endl;
	}
	std::cout << "int: " << literal << std::endl;
	if(literal - (int)literal == 0)
	{
		std::cout << "float: " << static_cast<float>(literal) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(literal) << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << static_cast<float>(literal) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(literal) << std::endl;
	}
}

void	ScalarConverter::printFloat(std::string& literal)
{
	float	literalFloat = atof(literal.c_str());
	if(literalFloat >= 32.0f && literalFloat <= 126.0f)
		std::cout << "char: '" << static_cast<char>(literalFloat)  << "'" << std::endl;
	else
	{
		if(literalFloat >= 0.0 && literalFloat <= 32.0)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: overflow" << std::endl;
	}
	if(literalFloat < std::numeric_limits<int>::min() || literalFloat > std::numeric_limits<int>::max())
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(literalFloat) << std::endl;
	if(literalFloat - (int)literalFloat == 0)
	{
		std::cout << "float: " << literalFloat << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(literalFloat) << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << literalFloat << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(literalFloat) << std::endl;
	}

}

void	ScalarConverter::printDouble(std::string& literal)
{
	double	literalDouble = atof(literal.c_str());
	if(literalDouble >= 32.0 && literalDouble <= 126.0)
		std::cout << "char: '" << static_cast<char>(literalDouble)  << "'" << std::endl;
	else
	{
		if(literalDouble >= 0.0 && literalDouble <= 32.0)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: overflow" << std::endl;
	}
	if(literalDouble < std::numeric_limits<int>::min() || literalDouble > std::numeric_limits<int>::max())
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(literalDouble) << std::endl;
	if(literalDouble - (int)literalDouble == 0)
	{
		std::cout << "float: " << static_cast<float>(literalDouble) << ".0f" << std::endl;
		std::cout << "double: " << literalDouble << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << static_cast<float>(literalDouble) << "f" << std::endl;
		std::cout << "double: " << literalDouble << std::endl;
	}
}

void	ScalarConverter::printSpecial(std::string& literal)
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
	{
		literal.erase(literal.end() - 1);
		std::cout << "double: " << literal  << std::endl;
	}
}

void	ScalarConverter::convert(std::string& literal)
{
	if(isChar(literal))
		printChar(literal[0]);
	else if(isInt(literal))
		printInt(atoi(literal.c_str()));
	else if(isFloat(literal))
		printFloat(literal);
	else if(isDouble(literal))
		printDouble(literal);
	else if(isSpecial(literal))
		printSpecial(literal);
	else
		std::cout << "Not a valid type." << std::endl;
}

