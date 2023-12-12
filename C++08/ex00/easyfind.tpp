/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:54:54 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/06 15:54:17 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

template <typename T>
void	easyfind(T& container, int search)
{
	if(std::find(container.begin(), container.end(), search) != container.end())
		std::cout << "Found!" << std::endl;
	else
		throw NotFound();
}

#endif