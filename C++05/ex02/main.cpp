/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:33:08 by jomirand          #+#    #+#             */
/*   Updated: 2023/11/22 14:59:43 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main()
{
	std::cout << "\033[1;36mInitializing test...\033[0m" << std::endl;
	std::cout << "\033[1;33mTest 1: creating a Bureaucrat and a signable and executable ShrubberyCreationForm form.\033[0m" << std::endl;
	{
		try
		{
			Bureaucrat				A("Eu", 1);
			ShrubberyCreationForm	B("Shrubbery1");
			A.signForm(B);
			A.executeForm(B);
		}
		catch(const std::exception& e)
		{
			std::cerr << "error while running simulation." << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "\033[1;33mTest 2: creating a Bureaucrat and a signable and executable PresidentialPardonForm form.\033[0m" << std::endl;
	{
		try
		{
			Bureaucrat				A("Eu", 1);
			PresidentialPardonForm	B("President");
			A.signForm(B);
			A.executeForm(B);
		}
		catch(const std::exception& e)
		{
			std::cerr << "error while running simulation." << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "\033[1;33mTest 3: creating a Bureaucrat and a signable and executable RobotomyRequestForm form.\033[0m" << std::endl;
	{
		try
		{
			Bureaucrat			A("Eu", 1);
			RobotomyRequestForm	B("Robotomy");
			A.signForm(B);
			A.executeForm(B);
		}
		catch(const std::exception& e)
		{
			std::cerr << "error while running simulation." << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "\033[1;33mTest 4: creating a Bureaucrat and a signable and non-executable ShrubberyCreationForm form.\033[0m" << std::endl;
	{
		try
		{
			Bureaucrat				A("Eu", 140);
			ShrubberyCreationForm	B("Shrubbery2");
			A.signForm(B);
			A.executeForm(B);
		}
		catch(const std::exception& e)
		{
			std::cerr << "error while running simulation." << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "\033[1;33mTest 5: creating a Bureaucrat and a signable and non-executable PresidentialPardonForm form.\033[0m" << std::endl;
	{
		try
		{
			Bureaucrat				A("Eu", 10);
			PresidentialPardonForm	B("President");
			A.signForm(B);
			A.executeForm(B);
		}
		catch(const std::exception& e)
		{
			std::cerr << "error while running simulation." << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "\033[1;33mTest 6: creating a Bureaucrat and a signable and non-executable RobotomyRequestForm form.\033[0m" << std::endl;
	{
		try
		{
			Bureaucrat			A("Eu", 51);
			RobotomyRequestForm	B("Robotomy");
			A.signForm(B);
			A.executeForm(B);
		}
		catch(const std::exception& e)
		{
			std::cerr << "error while running simulation." << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "\033[1;33mTest 7: creating a Bureaucrat and a non-signable and non-executable ShrubberyCreationForm form.\033[0m" << std::endl;
	{
		try
		{
			Bureaucrat				A("Eu", 150);
			ShrubberyCreationForm	B("Shrubbery3");
			A.signForm(B);
			A.executeForm(B);
		}
		catch(const std::exception& e)
		{
			std::cerr << "error while running simulation." << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "\033[1;33mTest 8: creating a Bureaucrat and a non-signable and non-executable PresidentialPardonForm form.\033[0m" << std::endl;
	{
		try
		{
			Bureaucrat				A("Eu", 150);
			PresidentialPardonForm	B("President");
			A.signForm(B);
			A.executeForm(B);
		}
		catch(const std::exception& e)
		{
			std::cerr << "error while running simulation." << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "\033[1;33mTest 9: creating a Bureaucrat and a non-signable and non-executable RobotomyRequestForm form.\033[0m" << std::endl;
	{
		try
		{
			Bureaucrat			A("Eu", 150);
			RobotomyRequestForm	B("Robotomy");
			A.signForm(B);
			A.executeForm(B);
		}
		catch(const std::exception& e)
		{
			std::cerr << "error while running simulation." << std::endl;
		}
	}
	return(0);
}