/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:17:40 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/26 17:16:32 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& obj) : _vectorArray(obj._vectorArray), _dequeArray(obj._dequeArray)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
	if(this != &obj)
	{
		_vectorArray = obj._vectorArray;
		_dequeArray = obj._dequeArray;
	}
	return(*this);
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(char **numbers, int numberCount)
{
	for(int i = 1; i < numberCount; i++)
	{
		_vectorArray.push_back(std::atoi(numbers[i]));
		_dequeArray.push_back(std::atoi(numbers[i]));
	}
}

void	PmergeMe::sorting()
{
	std::cout << "Before: ";
	for(size_t i = 0; i < _vectorArray.size(); i++)
	{
		std::cout << _vectorArray[i];
		if(i != _vectorArray.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;

	clock_t startVec = clock();
	mergeInsertVector(_vectorArray);
	clock_t endVec = clock();

	clock_t startDeq = clock();
	mergeInsertDeque(_dequeArray);
	clock_t endDeq = clock();

	std::cout << "After: ";
	for(size_t i = 0; i < _vectorArray.size(); i++)
	{
		std::cout << _vectorArray[i];
		if(i != _vectorArray.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;

	double time_elapsedVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 100;
	std::cout << "Time to process a range of " << _vectorArray.size() << " elements with std::vector : " << time_elapsedVec << " ms" << std::endl;
	double time_elapsedDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 100;
	std::cout << "Time to process a range of " << _dequeArray.size() << " elements with std::deque : " << time_elapsedDeq << " ms" << std::endl;
}

void	PmergeMe::mergeInsertVector(std::vector<int> &vector)
{
	if(vector.size() == 1)
		return;

	int	mid = vector.size() / 2;

	std::vector<int> left = std::vector<int>(vector.begin(), vector.begin() + mid);
	std::vector<int> right = std::vector<int>(vector.begin() + mid, vector.end());

	mergeInsertVector(left);
	mergeInsertVector(right);
	mergeVec(left, right, vector);
}

void	PmergeMe::mergeVec(std::vector<int> &left, std::vector<int> &right, std::vector<int> &vector)
{
	size_t l = 0, r = 0, v = 0;
	while(l < left.size() && r < right.size())
	{
		if(left[l] < right[r])
		{
			vector[v] = left[l];
			v++;
			l++;
		}
		else
		{
			vector[v] = right[r];
			v++;
			r++;
		}
	}
	while(l < left.size())
	{
		vector[v] = left[l];
		v++;
		l++;
	}
	while(r < right.size())
	{
		vector[v] = right[r];
		v++;
		r++;
	}
}

void	PmergeMe::mergeInsertDeque(std::deque<int> &deque)
{
	if(deque.size() == 1)
		return;

	int	mid = deque.size() / 2;

	std::deque<int> left = std::deque<int>(deque.begin(), deque.begin() + mid);
	std::deque<int> right = std::deque<int>(deque.begin() + mid, deque.end());

	mergeInsertDeque(left);
	mergeInsertDeque(right);
	mergeDeque(left, right, deque);
}

void	PmergeMe::mergeDeque(std::deque<int> &left, std::deque<int> &right, std::deque<int> &deque)
{
	size_t l = 0, r = 0, v = 0;
	while(l < left.size() && r < right.size())
	{
		if(left[l] < right[r])
		{
			deque[v] = left[l];
			v++;
			l++;
		}
		else
		{
			deque[v] = right[r];
			v++;
			r++;
		}
	}
	while(l < left.size())
	{
		deque[v] = left[l];
		v++;
		l++;
	}
	while(r < right.size())
	{
		deque[v] = right[r];
		v++;
		r++;
	}
}