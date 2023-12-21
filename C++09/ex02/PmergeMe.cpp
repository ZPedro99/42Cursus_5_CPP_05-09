/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:17:40 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/21 15:11:35 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& obj) : _vectorArray(obj._vectorArray), _listArray(obj._listArray)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
	if(this != &obj)
	{
		_vectorArray = obj._vectorArray;
		_listArray = obj._listArray;
	}
	return(*this);
}

PmergeMe::~PmergeMe()
{
}