/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:07:59 by jomirand          #+#    #+#             */
/*   Updated: 2023/11/30 14:01:18 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
	int number;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& obj);
		Serializer&	operator=(const Serializer& obj);
		~Serializer();
	public:
		static uintptr_t	serialize(Data* ptr);
		//return ((uintptr_t(&ptr)))
		static Data*		deserialize(uintptr_t raw);
		//return ((Data*(raw)))
};

#endif