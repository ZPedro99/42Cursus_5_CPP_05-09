/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:02:38 by jomirand          #+#    #+#             */
/*   Updated: 2023/11/23 11:19:36 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& obj);
		Intern&	operator=(const Intern& obj);
		~Intern();

		AForm	*makeForm(std::string name, std::string target);
		AForm	*createShruberry(std::string target);
		AForm	*createRobotomy(std::string target);
		AForm	*createPresidential(std::string target);
		class NoFormException : public std::exception
		{
			public:
				virtual const char * what() const throw() {return("Couldn't find a form with that name.");}
		};
};

#endif