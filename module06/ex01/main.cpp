/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:30:04 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/23 14:42:05 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>
#include <stdio.h>

#include "Serializer.hpp"

int main()
{
	Data data[] = {{"Jose", 42}};
	std::cout << "Data->name is " << data->name << std::endl;
	std::cout << "Data->age is " << data->age << std::endl;
	std::cout << "Data address is " << data << std::endl;

	uintptr_t i;
	i = Serializer::serialize(data);
	std::cout << "\nuintptr is " << i << std::endl;

	Data *ptr = Serializer::deserialize(i);
	std::cout << "\nCopy Data->name is " << ptr->name << std::endl;
	std::cout << "Copy Data->age is " << ptr->age << std::endl;
	std::cout << "Copy data address is " << ptr << std::endl;
	return 0;
}
