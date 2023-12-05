/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:51:16 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/04 18:01:26 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main(void)
{
	/* int	a = 5;
	int	b = 7;
	std::cout << "Before swap: " << a << " , " << b << std::endl;
	swap<int>(a, b);
	std::cout << "After swap: " << a << " , " << b << std::endl;
	std::cout << "The max number is " << max<int>(a, b) << std::endl;
	std::cout << "The min number is " << min<int>(a, b) << std::endl; */

	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return(0);
}