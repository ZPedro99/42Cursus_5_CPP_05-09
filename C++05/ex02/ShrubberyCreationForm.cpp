/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:35:14 by jomirand          #+#    #+#             */
/*   Updated: 2023/11/22 13:47:49 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm("ShrubberyCreationForm", 145, 137), _target(obj._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	if(this != &obj)
		_target = obj._target;
	return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm default destructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm target constructor called." << std::endl;
}

std::string ShrubberyCreationForm::getTarget()
{
	return(_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if(executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if(this->getSigned() == false)
		throw FormNotSignedException();
	std::string filename = _target + "_shrubbery";
	std::ofstream outputFile(filename.c_str());
	if(outputFile.is_open())
	{
		outputFile << "       _-_        " << std::endl;
		outputFile << "    /~~   ~~\\    " << std::endl;
		outputFile << " /~~         ~~\\ " << std::endl;
		outputFile << "{               } " << std::endl;
		outputFile << " \\  _-     -_  / " << std::endl;
		outputFile << "   ~  \\ //  ~    " << std::endl;
		outputFile << "_- -   | | _-     " << std::endl;
		outputFile << "  _ -  | |   -_   " << std::endl;
		outputFile << "      // \\       " << std::endl;
		outputFile << "##################" << std::endl;
		outputFile.close();

		std::cout << "(EXTRA) File created: " << filename << std::endl;
	}
	else
	{
		std::cout << "Error opening file for writing: " << filename << std::endl;
	}
}