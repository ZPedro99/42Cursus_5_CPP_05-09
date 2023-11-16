/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:33:14 by jomirand          #+#    #+#             */
/*   Updated: 2023/11/16 17:32:46 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("no_name"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called.";
	std::cout << " name set to " << _name <<  "and grade set to " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name), _grade(obj._grade)
{
	std::cout << "Bureaucrat copy constructor called.";
	std::cout << " name set to " << _name << " and grade set to " << _grade << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& obj)
{
	std::cout << "Bureaucrat copy assignment operator called." << std::endl;
	if(this != &obj)
		_grade = obj._grade;
	return(*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if(_grade < 1)
		throw GradeTooHighException();
	if(_grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat name constructor called. Initialized with name " << _name;
	std::cout << " and grade " << _grade << std::endl;
}

std::string	Bureaucrat::getName()
{
	return(_name);
}

int	Bureaucrat::getGrade()
{
	return(_grade);
}

void	Bureaucrat::incrementGrade()
{
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	_grade++;
}

std::ostream&	Bureaucrat::operator<<(std::ostream& output)
{
	output << _name << ", bureaucrat grade " << _grade;
	return(output);
}