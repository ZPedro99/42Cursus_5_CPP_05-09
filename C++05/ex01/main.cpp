/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:33:08 by jomirand          #+#    #+#             */
/*   Updated: 2023/11/21 11:51:09 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	std::cout << "\033[1;36mInitializing test...\033[0m" << std::endl;
	std::cout << "\033[1;33mTest 1: creating a Bureaucrat and a signable form.\033[0m" << std::endl;
	{
		try
		{
			Bureaucrat	A("Eu", 15);
			Form		B("contrato", 20, 10);
			B.beSigned(A);
			std::cout << B << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

	}
	std::cout << std::endl;
	std::cout << "\033[1;33mTest 2: creating a Bureaucrat and an unsignable form (grade too low).\033[0m" << std::endl;
	{
		try
		{
			Bureaucrat	A("Eu", 25);
			Form		B("contrato", 20, 10);
			A.signForm(B);
			std::cout << B;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "\033[1;33mTest 3: creating a Bureaucrat and increment to sign form.\033[0m" << std::endl;
	{
		try
		{
			Bureaucrat	A("Eu", 25);
			Form		B("contrato", 24, 10);
			A.incrementGrade();
			A.signForm(B);
			std::cout << B << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "\033[1;33mTest 4: creating a Bureaucrat and decrement to not sign form.\033[0m" << std::endl;
	{
		try
		{
			Bureaucrat	A("Eu", 25);
			Form		B("contrato", 25, 10);
			A.decrementGrade();
			A.signForm(B);
			std::cout << B << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return(0);
}