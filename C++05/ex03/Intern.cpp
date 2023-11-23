/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:02:41 by jomirand          #+#    #+#             */
/*   Updated: 2023/11/23 11:24:48 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(const Intern& obj)
{
	std::cout << "Intern copy constructor called." << std::endl;
	(void)obj;
}

Intern&	Intern::operator=(const Intern& obj)
{
	(void)obj;
	return(*this);
}

Intern::~Intern()
{
	std::cout << "Intern default destructor called." << std::endl;
}

AForm*	Intern::createShruberry(std::string target)
{
	std::cout << "Intern creates Shrubbery Form" << std::endl;
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::createRobotomy(std::string target)
{
	std::cout << "Intern creates Robotomy Form" << std::endl;
	return new RobotomyRequestForm(target);
}

AForm*	Intern::createPresidential(std::string target)
{
	std::cout << "Intern creates Presidential Form" << std::endl;
	return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	std::string	form_names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(Intern::*functionArray[])(std::string) = {&Intern::createShruberry, &Intern::createRobotomy, &Intern::createPresidential};
	for(int i = 0; i < 3; i++)
	{
		if(name == form_names[i])
			return(this->*functionArray[i])(target);
	}
	throw NoFormException();
	return NULL;
}