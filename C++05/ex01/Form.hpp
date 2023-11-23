/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:39:35 by jomirand          #+#    #+#             */
/*   Updated: 2023/11/21 11:43:50 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;
	public:
		Form();
		Form(const Form& obj);
		Form&	operator=(const Form& obj);
		~Form();

		Form(std::string name, int signGrade, int execGrade);
		const std::string getName();
		bool getSigned();
		int getSignGrade();
		int getExecGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw() {return "Form grade too high.";}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw() {return "Form grade too low.";}
		};

		void	beSigned(Bureaucrat& bureaucrat);
};

std::ostream&	operator<<(std::ostream& output, Form& obj);

#endif


