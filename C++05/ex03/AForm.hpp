/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:39:35 by jomirand          #+#    #+#             */
/*   Updated: 2023/11/21 11:43:50 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;
	public:
		AForm();
		AForm(const AForm& obj);
		AForm&	operator=(const AForm& obj);
		virtual ~AForm();

		AForm(std::string name, int signGrade, int execGrade);
		const std::string getName() const;
		bool getSigned() const;
		int getSignGrade();
		int getExecGrade() const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw() {return "AForm grade too high.";}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw() {return "AForm grade too low.";}
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char * what() const throw() {return "AForm not signed.";}
		};

		void	beSigned(Bureaucrat& bureaucrat);
		virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream&	operator<<(std::ostream& output, AForm& obj);

#endif


