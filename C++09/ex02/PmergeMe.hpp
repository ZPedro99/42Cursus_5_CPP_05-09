/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:17:42 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/26 17:16:41 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <limits.h>
#include <vector>
#include <deque>
#include <cstdlib>
#include <time.h>

class PmergeMe
{
	private:
		std::vector<int> _vectorArray;
		std::deque<int> _dequeArray;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& obj);
		PmergeMe&	operator=(const PmergeMe& obj);
		~PmergeMe();

		PmergeMe(char **numbers, int numberCount);

		void	sorting();

		void	mergeInsertVector(std::vector<int> &vector);
		void	mergeVec(std::vector<int> &left, std::vector<int> &right, std::vector<int> &vector);

		void	mergeInsertDeque(std::deque<int> &deque);
		void	mergeDeque(std::deque<int> &left, std::deque<int> &right, std::deque<int> &deque);
};

#endif