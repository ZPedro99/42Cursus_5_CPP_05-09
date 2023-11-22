/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:33:14 by jomirand          #+#    #+#             */
/*   Updated: 2023/11/22 14:40:11 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
	std::cout << "Bureaucrat default destructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat name constructor called. Initialized with name " << _name;
	std::cout << " and grade " << _grade << std::endl;
	if(_grade < 1)
		throw GradeTooHighException();
	if(_grade > 150)
		throw GradeTooLowException();
}

const std::string	Bureaucrat::getName()
{
	return(_name);
}

int	Bureaucrat::getGrade() const
{
	return(_grade);
}

void	Bureaucrat::incrementGrade()
{
	_grade--;
	std::cout << "Bureaucrat "<< _name << " grade incremented. Value set to " << _grade << std::endl;
	if(_grade < 1)
		throw GradeTooHighException();
}

void	Bureaucrat::decrementGrade()
{
	_grade++;
	std::cout << "Bureaucrat "<< _name << " grade decremented. Value set to " << _grade << std::endl;
	if(_grade > 150)
		throw GradeTooLowException();
}

std::ostream&	operator<<(std::ostream& output, Bureaucrat& obj)
{
	output << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return(output);
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}

}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}

}