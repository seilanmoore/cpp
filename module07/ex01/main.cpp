/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:49:14 by smoore-a          #+#    #+#             */
/*   Updated: 2025/06/02 10:15:47 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include <ctype.h>

#include "iter.hpp"

int main()
{
	int int_array[] = {1, 2, 3, 4, 5};
	std::size_t int_length = sizeof(int_array) / sizeof(int);

	std::cout << "Array de enteros original: ";
	iter(int_array, int_length, printElement<int>);
	std::cout << std::endl;

	std::cout << "Array de enteros después de incrementElement: ";
	iter(int_array, int_length, incrementElement<int>);
	iter(int_array, int_length, printInteger);
	std::cout << std::endl
			  << std::endl;

	std::string string_array[] = {"apple", "banana", "cherry", "date"};
	std::size_t string_length = sizeof(string_array) / sizeof(std::string);

	std::cout << "Array de strings original: ";
	iter(string_array, string_length, printElement<std::string>);
	std::cout << std::endl;

	std::cout << "Array de strings en mayúsculas: ";
	iter(string_array, string_length, toUpper);
	iter(string_array, string_length, printElement<std::string>);
	std::cout << std::endl;

	return 0;
}
