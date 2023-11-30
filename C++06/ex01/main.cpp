/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:07:25 by jomirand          #+#    #+#             */
/*   Updated: 2023/11/30 14:32:35 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data	data;
	data.number = 42;

	std::cout << "Data address is: " << &data << std::endl;
	std::cout << "Data number value is: " << data.number << std::endl;

	uintptr_t	postSerialize = Serializer::serialize(&data);

	std::cout << std::endl;
	std::cout << "Post serialization: " << postSerialize << std::endl;

	Data*	postDeserialize = Serializer::deserialize(postSerialize);

	std::cout << std::endl;
	std::cout << "Post deserialization: " << postDeserialize << std::endl;
	std::cout << "Post deserialization number value: " << postDeserialize->number << std::endl;
	return(0);
}