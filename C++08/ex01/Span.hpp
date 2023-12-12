/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:05:05 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/11 16:47:30 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <ctime>

class Span
{
	private:
		std::vector<int> _storedNumbers;
		unsigned int _integers;
	public:
		Span();
		Span(const Span& obj);
		Span&	operator=(const Span& obj);
		~Span();

		Span(unsigned int numbers);

		void			addNumber(int numberToAdd);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void			generateNumbers();
		void			printNumbers();
		void			addMultipleNumbers(std::vector<int> MultipleNumbers);

		class MaxNumbers : public std::exception
		{
			public:
				virtual const char *what() const throw() {return("Max numbers stored.");}
		};
		class NoSpanFound : public std::exception
		{
			public:
				virtual const char *what() const throw() {return("No span found due to insuffiecient size.");}
		};
};

#endif
