/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:59:04 by smoore-a          #+#    #+#             */
/*   Updated: 2025/04/18 20:55:16 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPtr = &str;
	std::string &strRef = str;

	std::cout << "The memory address of the string variable: " << &str
			  << std::endl
			  << "The memory address held by strPtr: " << strPtr
			  << std::endl
			  << "The memory address held by strRef: " << &strRef
			  << std::endl
			  << "The value of the string variable: " << str
			  << std::endl
			  << "The value pointed to by strPtr: " << *strPtr
			  << std::endl
			  << "The value pointed to by strRef: " << strRef
			  << std::endl;
	return 0;
}
