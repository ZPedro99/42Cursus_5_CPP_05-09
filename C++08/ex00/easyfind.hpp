/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:53:51 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/07 17:21:51 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

class NotFound : public std::exception
{
	public:
		virtual const char *what() const throw() {return("Not found.");};
};

template <typename T>
void	easyfind(T* container, int search);

#include "easyfind.tpp"

#endif