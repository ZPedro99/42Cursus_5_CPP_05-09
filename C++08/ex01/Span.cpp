/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:11:04 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/11 17:08:18 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _integers(0)
{
}

Span::Span(const Span& obj) : _storedNumbers(obj._storedNumbers), _integers(obj._integers)
{
}

Span&	Span::operator=(const Span& obj)
{
	if(this != &obj)
	{
		_integers = obj._integers;
		_storedNumbers.clear();
		_storedNumbers = obj._storedNumbers;
	}
	return(*this);
}

Span::~Span()
{
}

Span::Span(unsigned int numbers) : _integers(numbers)
{
}

void	Span::addNumber(int numberToAdd)
{
	if(_storedNumbers.size() >= _integers)
		throw MaxNumbers();
	_storedNumbers.push_back(numberToAdd);
}

unsigned int	Span::shortestSpan()
{
	if(_integers <= 1)
		throw NoSpanFound();
	unsigned int minDiff = std::numeric_limits<unsigned int>::max();
	int	short1;
	int	short2;
	for(std::vector<int>::iterator i = _storedNumbers.begin(); i != _storedNumbers.end(); i++)
	{
		for(std::vector<int>::iterator x = _storedNumbers.begin(); x != _storedNumbers.end(); x++)
		{
			if(i == x)
				continue;
			if(std::abs(*i - *x) < minDiff)
			{
				minDiff = std::abs(*i - *x);
				short1 = *i;
				short2 = *x;
			}
		}
	}
	std::cout << "Shortest span calculation between " << short1 << " and " << short2 << std::endl;
	std::cout << "The shortest span is " << minDiff << std::endl;
	return(minDiff);
}

unsigned int	Span::longestSpan()
{
	if(_integers <= 1)
		throw NoSpanFound();
	std::vector<int> sortedNumbers = _storedNumbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	int lowest = sortedNumbers.front();
	int highest = sortedNumbers.back();
	std::cout << "Highest number is " << highest << " and the lowest is " << lowest << ". Calculating longest span..." << std::endl;
	std::cout << "The longest span is " << highest - lowest << std::endl;
	return(highest - lowest);
}

void	Span::generateNumbers()
{
	if(_integers <= 1)
		throw NoSpanFound();
	std::srand(std::time(NULL));
	std::vector<int> multipleNumbers;
	for(unsigned int i = 0; i < _integers; i++)
		multipleNumbers.push_back(rand());
	addMultipleNumbers(multipleNumbers);
}

void	Span::printNumbers()
{
	if(_integers <= 1)
		throw NoSpanFound();
	std::cout << "Numbers inside the vector: ";
	for(std::vector<int>::iterator i = _storedNumbers.begin(); i != _storedNumbers.end(); i++)
	{
		std::cout << *i;
		if(i == _storedNumbers.end() - 1)
			std::cout << "." << std::endl;
		else
			std::cout << ", ";
	}
}

void	Span::addMultipleNumbers(std::vector<int> multipleNumbers)
{
	if(_storedNumbers.size() + multipleNumbers.size() > _integers)
		throw MaxNumbers();
	_storedNumbers.insert(_storedNumbers.end(), multipleNumbers.begin(), multipleNumbers.end());
}
