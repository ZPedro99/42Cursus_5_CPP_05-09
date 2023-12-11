/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:40:38 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/11 18:27:27 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack& obj);
		MutantStack&	operator=(const MutantStack& obj);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin(void);
		iterator end(void);
};

#include "MutantStack.tpp"

#endif
