/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:36:13 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/05 12:45:13 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T *array, size_t length, void (*f)(T &))
{
	for(size_t i = 0; i < length; i++)
	{
		f(array[i]);
	}
}

template <typename T>
void	print(T &c)
{
	std::cout << c << " ";
}

template <typename T>
void	add5(T &c)
{
	c += 5;
}


#endif