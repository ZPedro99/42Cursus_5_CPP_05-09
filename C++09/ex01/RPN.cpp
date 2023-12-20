/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:11:34 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/20 17:34:14 by jomirand         ###   ########.fr       */
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

RPN&	operator=(const RPN& obj)
{
	if(this != &obj)
	{
		_numbers = obj._numbers;
	}
	return(*this);
}

RPN::~RPN()
{
}

void	RPN::applyRPN(const std::string& expression)
{
	std::string operator;
	std::string number;
	for(size_t i = 0; i < expression.length(); i++)
	{
		if(expression[i] == ' ')
			continue;
		if(isdigit(expression[i]))
		{
			number = expression[i];
			_numbers.push(atof(number));
		}
		if(isoperator(expression[i]) == true)
		{
			operator = expression[i];
			_numbers.push(doOperation(operator));
			//i = 0;
		}
	}
	std::cout << _numbers.top() << std::endl;
}

bool	RPN::isoperator(char operator)
{
	if(std::find("+-/*", operator) != std::string::npos)
		return(true);
	return(false);
}

double	RPN::doOperation(char operator)
{
	double num1;
	double num2;

	num2 = _numbers.top();
	_numbers.pop();
	num1 = _numbers.top();
	_numbers.pop();
	switch(operator)
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
			std::cout << "Not a valid operator." << std::endl;
			break;
	}
}