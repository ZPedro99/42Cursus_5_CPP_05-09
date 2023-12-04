/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:20:21 by jomirand          #+#    #+#             */
/*   Updated: 2023/11/30 14:31:26 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& obj)
{
	(void)obj;
}

Serializer&	Serializer::operator=(const Serializer& obj)
{
	(void)obj;
	return(*this);
}

Serializer::~Serializer() {}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data*>(raw));
}