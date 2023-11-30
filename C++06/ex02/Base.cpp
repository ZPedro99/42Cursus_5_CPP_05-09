/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:57:32 by jomirand          #+#    #+#             */
/*   Updated: 2023/11/30 16:04:53 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base*	generate()
{
	srand(time(NULL));
	int	i = rand() % 3;
	switch (i)
	{
	case 0:
		std::cout << "A instanciated." << std::endl;
		return(new A());
	case 1:
		std::cout << "B instanciated." << std::endl;
		return(new B());
	case 2:
		std::cout << "C instanciated." << std::endl;
		return(new C());
	default:
		std::cout << "No valid object was instanciated." << std::endl;
		break;
	}
	return(NULL);
}

void	identify(Base* p)
{
	std::cout << "Calling identify() that receives a pointer." << std::endl;
	if(A* Aobj = dynamic_cast<A*>(p))
		std::cout << "On pointer-type identifier, object is type A" << std::endl;
	else if(B* Bobj = dynamic_cast<B*>(p))
		std::cout << "On pointer-type identifier, object is type B" << std::endl;
	else if(C* Cobj = dynamic_cast<C*>(p))
		std::cout << "On pointer-type identifier, object is type C" << std::endl;
}

void	identify(Base& p)
{
	std::cout << "Calling identify() that receives an address." << std::endl;
	try
	{
		A&	AAddress = dynamic_cast<A&>(p);
		(void)AAddress;
		std::cout << "On address-type identifier, object type is A." << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B&	BAddress = dynamic_cast<B&>(p);
		(void)BAddress;
		std::cout << "On address-type identifier, object type is B." << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C&	CAddress = dynamic_cast<C&>(p);
		(void)CAddress;
		std::cout << "On address-type identifier, object type is C." << std::endl;
	}
	catch(const std::exception& e)
	{
	}

}