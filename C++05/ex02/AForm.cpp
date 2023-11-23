/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:39:37 by jomirand          #+#    #+#             */
/*   Updated: 2023/11/21 11:38:38 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default_AForm"), _signed(false), _signGrade(150), _execGrade(150)
{
	std::cout << "AForm default constructor called." << std::endl;
}

AForm::AForm(const AForm& obj) : _name(obj._name), _signed(obj._signed), _signGrade(obj._signGrade), _execGrade(obj._execGrade)
{
	std::cout << "AForm copy constructor called." << std::endl;
	if(_signGrade < 1)
		throw GradeTooHighException();
	if(_signGrade > 150)
		throw GradeTooLowException();
}

AForm&	AForm::operator=(const AForm& obj)
{
	if(this != &obj)
		_signed = obj._signed;
	return(*this);
}

AForm::~AForm()
{
	std::cout << "AForm default destructor called." << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if(_signGrade < 1)
		throw GradeTooHighException();
	if(_signGrade > 150)
		throw GradeTooLowException();
	std::cout << "AForm type constructor called. ";
	std::cout << "Name set to " << _name << ", ";
	std::cout << "sign grade set to " << _signGrade;
	std::cout << " and execute grade set to " << _execGrade << std::endl;
}

const std::string	AForm::getName() const
{
	return(_name);
}

bool	AForm::getSigned() const
{
	return(_signed);
}

int	AForm::getSignGrade()
{
	return(_signGrade);
}

int	AForm::getExecGrade() const
{
	return(_execGrade);
}

std::ostream&	operator<<(std::ostream& output, AForm& obj)
{
	output << "AForm name: " << obj.getName() << "; signed: " << obj.getSigned() << "; sign grade: " << obj.getSignGrade() << "; exec grade " << obj.getExecGrade() << std::endl;
	return(output);
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if(bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	std::cout << "Bureaucrat " << bureaucrat.getName() << " has signed the AForm \"" << _name << "\"" << std::endl;
	_signed = true;
}
