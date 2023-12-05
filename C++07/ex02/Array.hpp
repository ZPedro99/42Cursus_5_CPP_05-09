/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:54:50 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/05 17:38:36 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T>
class Array
{
	private:
		T *_array;
		unsigned int _arraySize;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array &original);
		Array &operator=(const Array &original);
		~Array();

		T &operator[](unsigned int i);

		unsigned int size() const;

		class IndexOutOfBounds : public std::exception
		{
		public:
			virtual const char *what() const throw() {return("invalid index (out of bounds)");};
		};
};

#include "Array.tpp"

#endif