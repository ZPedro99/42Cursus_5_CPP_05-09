/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:39:37 by jomirand          #+#    #+#             */
/*   Updated: 2023/11/21 11:38:38 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default_form"), _signed(false), _signGrade(150), _execGrade(150)
{
	std::cout << "Form default constructor called." << std::endl;
}

Form::Form(const Form& obj) : _name(obj._name), _signed(obj._signed), _signGrade(obj._signGrade), _execGrade(obj._execGrade)
{
	std::cout << "Form copy constructor called." << std::endl;
	if(_signGrade < 1)
		throw GradeTooHighException();
	if(_signGrade > 150)
		throw GradeTooLowException();
}

Form&	Form::operator=(const Form& obj)
{
	if(this != &obj)
		_signed = obj._signed;
	return(*this);
}

Form::~Form()
{
	std::cout << "Form default destructor called." << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if(_signGrade < 1)
		throw GradeTooHighException();
	if(_signGrade > 150)
		throw GradeTooLowException();
	std::cout << "Form type constructor called. ";
	std::cout << "Name set to " << _name << ", ";
	std::cout << "sign grade set to " << _signGrade;
	std::cout << " and execute grade set to " << _execGrade << std::endl;
}

const std::string	Form::getName()
{
	return(_name);
}

bool	Form::getSigned()
{
	return(_signed);
}

int	Form::getSignGrade()
{
	return(_signGrade);
}

int	Form::getExecGrade()
{
	return(_execGrade);
}

std::ostream&	operator<<(std::ostream& output, Form& obj)
{
	output << "Form name: " << obj.getName() << "; signed: " << obj.getSigned() << "; sign grade: " << obj.getSignGrade() << "; exec grade " << obj.getExecGrade() << std::endl;
	return(output);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if(bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	std::cout << "Bureaucrat " << bureaucrat.getName() << " has signed the Form \"" << _name << "\"" << std::endl;
	_signed = true;
}