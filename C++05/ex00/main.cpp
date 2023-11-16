/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:33:08 by jomirand          #+#    #+#             */
/*   Updated: 2023/11/16 17:33:01 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "\033[1;36mInitializing test...\033[0m" << std::endl;
	std::cout << "\033[1;33mTest 1: creating a Bureaucrat.\033[0m" << std::endl;
	{
		Bureaucrat	A("Kelvin", 1);

		std::cout << "Bureaucrat " << A.getName() << " was created with grade " << A.getGrade() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\033[1;33mTest 2: creating a Bureaucrat with copy constructor.\033[0m" << std::endl;
	{
		Bureaucrat	A("Ze", 60);
		Bureaucrat	B(A);

		std::cout << "Bureaucrat " << B.getName() << " was created with grade " << B.getGrade() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\033[1;33mTest 3: assigning values to a Bureaucrat with copy assignment operator.\033[0m" << std::endl;
	{
		Bureaucrat	A("Este", 33);
		Bureaucrat	B("Aquele", 110);

		B = A;
		std::cout << "Bureaucrat " << B.getName() << " was created with grade " << B.getGrade() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\033[1;33mTest 4: creating a Bureaucrat with a grade over 150.\033[0m" << std::endl;
	{
		try
		{
			Bureaucrat	A("O outro", 151);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "\033[1;33mTest 5: creating a Bureaucrat with a grade under 1.\033[0m" << std::endl;
	{
		try
		{
			Bureaucrat	A("Ali", 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return(0);
}