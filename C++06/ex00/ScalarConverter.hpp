/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:54:40 by jomirand          #+#    #+#             */
/*   Updated: 2023/11/28 18:01:15 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <stdlib.h>
#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter& operator=(const ScalarConverter& obj);
		~ScalarConverter();
	public:
		static void	convert(const std::string& literal);

		static bool	isChar(const std::string& literal);
		static bool	isInt(const std::string& literal);
		static bool	isFloat(const std::string& literal);
		static bool	isDouble(const std::string& literal);
		static bool	isSpecial(const std::string& literal);

		static void	printChar(char literal);
		static void	printInt(int literal);
		static void	printFloat(const std::string& literal);
		static void	printDouble(const std::string& literal);
		static void	printSpecial(const std::string& literal);
};

#endif