/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:11:36 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/20 17:41:00 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

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
		bool	isoperator(char operator);
		double	doOperation(char operator);
};

#endif