/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:34:48 by jomirand          #+#    #+#             */
/*   Updated: 2023/11/22 12:41:43 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm("RobotomyRequestForm", 72, 45), _target(obj._target)
{
	std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if(this != &obj)
		_target = obj._target;
	return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm default destructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm target constructor called." << std::endl;
}

std::string RobotomyRequestForm::getTarget()
{
	return(_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if(executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if(this->getSigned() == false)
		throw FormNotSignedException();
	std::cout << "Drilling noises!!!" << std::endl;
	srand(time(NULL));
	int i = (rand() % 2) + 1;
	if(i == 1)
		std::cout << _target << " has been robotomized." << std::endl;
	else
		std::cout << _target << " robotomy failed." << std::endl;
}