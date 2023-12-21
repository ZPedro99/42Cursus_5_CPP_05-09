/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:11:34 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/21 12:50:53 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& obj)
{
	*this = obj;
}

RPN&	RPN::operator=(const RPN& obj)
{
	if(this != &obj)
		_numbers = obj._numbers;
	return(*this);
}

RPN::~RPN()
{
}

void	RPN::applyRPN(const std::string& expression)
{
	std::string operation;
	std::string number;
	for(size_t i = 0; i < expression.length(); i++)
	{
		if(expression[i] == ' ')
			continue;
		if(isdigit(expression[i]))
		{
			number = expression[i];
			_numbers.push(std::atof(number.c_str()));
		}
		if(isoperator(expression[i]) == true)
		{
			operation = expression[i];
			_numbers.push(doOperation(operation[0]));
		}
		if((isoperator(expression[i]) == false && isdigit(expression[i]) == false) && expression[i] != ' ')
			throw std::runtime_error("Error(4)");
	}
	std::cout << _numbers.top() << std::endl;
	_numbers.pop();
}

bool	RPN::isoperator(char operation)
{
	std::string	signals = "+-/*";
	if(std::find(signals.begin(), signals.end(), operation) != signals.end())
		return(true);
	return(false);
}

double	RPN::doOperation(char operation)
{
	double num1;
	double num2;

	if(_numbers.empty())
		throw std::runtime_error("Error(1)");
	num2 = _numbers.top();
	_numbers.pop();
	if(_numbers.empty())
		throw std::runtime_error("Error(2)");
	num1 = _numbers.top();
	_numbers.pop();
	switch(operation)
	{
		case '+':
			return(num1 + num2);
			break;
		case '-':
			return(num1 - num2);
			break;
		case '*':
			return(num1 * num2);
			break;
		case '/':
			return(num1 / num2);
			break;
		default:
			throw std::runtime_error("Error(3)");
			break;
	}
}