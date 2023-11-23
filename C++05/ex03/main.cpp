/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:33:08 by jomirand          #+#    #+#             */
/*   Updated: 2023/11/23 11:36:11 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main()
{
	std::cout << "\033[1;36mInitializing test...\033[0m" << std::endl;
	std::cout << "\033[1;33mTest 1: calling Intern to create a ShrubberyForm.\033[0m" << std::endl;
	{
		AForm*	shrubberyForm = 0;
		try
		{
			Intern I1;

			Bureaucrat	A("Eu", 1);
			shrubberyForm = I1.makeForm("shrubbery creation" , "target");
			A.signForm(*shrubberyForm);
			std::cout << *shrubberyForm;
			delete shrubberyForm;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			delete shrubberyForm;
		}
	}
	std::cout << std::endl;
	std::cout << "\033[1;33mTest 2: calling Intern to create a RobotomyForm.\033[0m" << std::endl;
	{
		AForm*	robotomyForm = 0;
		try
		{
			Intern I1;

			Bureaucrat	A("Eu", 1);
			robotomyForm = I1.makeForm("robotomy request" , "target");
			A.signForm(*robotomyForm);
			std::cout << *robotomyForm;
			delete robotomyForm;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			delete robotomyForm;
		}
	}
	std::cout << std::endl;
	std::cout << "\033[1;33mTest 3: calling Intern to create a PresidentialForm.\033[0m" << std::endl;
	{
		AForm*	presidentialForm = 0;
		try
		{
			Intern I1;

			Bureaucrat	A("Eu", 1);
			presidentialForm = I1.makeForm("presidential pardon" , "target");
			A.signForm(*presidentialForm);
			std::cout << *presidentialForm;
			delete presidentialForm;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			delete presidentialForm;
		}
	}
	std::cout << std::endl;
	std::cout << "\033[1;33mTest 4: calling Intern to create a non-existant form.\033[0m" << std::endl;
	{
		AForm*	noForm = 0;
		try
		{
			Intern I1;

			Bureaucrat	A("Eu", 1);
			noForm = I1.makeForm("42 Porto" , "target");
			A.signForm(*noForm);
			std::cout << *noForm;
			delete noForm;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			delete noForm;
		}
	}
	return(0);
}
