/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:07:46 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/11 18:29:21 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& obj)
{
	*this = obj;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& obj)
{
	std::stack<T>::operator=(this, obj);
	return(*this)
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return(this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return (this->c.end());
}

#endif
