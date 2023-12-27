/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:11:36 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/21 11:21:43 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <stdlib.h>
#include <algorithm>

class RPN
{
	private:
		std::stack<double> _numbers;
	public:
		RPN();
		RPN(const RPN& obj);
		RPN&	operator=(const RPN& obj);
		~RPN();

		void	applyRPN(const std::string& expression);
		bool	isoperator(char operation);
		double	doOperation(char operation);
};

#endif