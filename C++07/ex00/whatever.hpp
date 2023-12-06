/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:51:18 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/04 17:30:28 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void	swap(T &x, T &y)
{
	T	temp;
	temp = x;
	x = y;
	y = temp;
}

template <typename T>
T	max(T t1, T t2)
{
	return(t1 > t2) ? t1 : t2;
}

template <typename T>
T	min(T t1, T t2)
{
	return(t1 < t2) ? t1 : t2;
}

#endif