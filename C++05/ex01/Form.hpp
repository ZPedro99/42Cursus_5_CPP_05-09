/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:39:35 by jomirand          #+#    #+#             */
/*   Updated: 2023/11/20 17:15:34 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

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
		const int getSignGrade();
		const int getExecGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * wait() const throw() {return "Form grade too high.";}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * wait() const throw() {return "Form grade too low.";}
		};
};

std::ostream&	operator<<(std::ostream& output, Form& obj);

#endif


