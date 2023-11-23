/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:33:12 by jomirand          #+#    #+#             */
/*   Updated: 2023/11/21 11:25:17 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		//****Orthodox Canonical Form****//
		Bureaucrat();
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat&	operator=(const Bureaucrat& obj);
		~Bureaucrat();
		//*******************************//

		Bureaucrat(std::string name, int grade);
		const std::string	getName();
		int			getGrade();
		void		incrementGrade();
		void		decrementGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw() {return("Bureaucrat grade is too high");}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw() {return("Bureaucrat grade is too low");}
		};

		void	signForm(Form& form);
};

std::ostream	&operator<<(std::ostream& output, Bureaucrat& obj);

#endif