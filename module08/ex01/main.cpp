/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 20:19:55 by smoore-a          #+#    #+#             */
/*   Updated: 2025/06/07 11:13:44 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "Span.hpp"

int main()
{
	std::string str;

	{
		Span sp;

		std::cout << (str = "ADD TO EMPTY") << std::endl;
		std::cout << std::setw(str.length()) << std::setfill('-') << "" << std::endl;

		try
		{
			sp.addNumber();
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			sp.addNumber(3);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << sp;

		std::cout << (str = "\nADD SUBJECT NUMBERS") << std::endl;
		std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;

		sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp;

		std::cout << (str = "\nADD TOO MANY NUMBERS") << std::endl;
		std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;

		try
		{
			sp.addNumber();
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			sp.addNumber(0);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << (str = "\nFIND SHORTEST SPAN") << std::endl;
		std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;

		try
		{
			long shortest = sp.shortestSpan();
			std::cout << "shortest span is " << shortest << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << (str = "\nFIND LONGEST SPAN") << std::endl;
		std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;

		try
		{
			long longest = sp.longestSpan();
			std::cout << "longest span is " << longest << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		Span sp = Span(5);

		std::cout << (str = "\nADD NUMBERS IN ONE CALL") << std::endl;
		std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
		sp.addNumber();
		std::cout << sp;
		try
		{
			sp.addNumber(0);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			sp.addNumber();
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		Span sp = Span(5);

		std::cout << (str = "\nADD OVER MAX INT NUMBER") << std::endl;
		std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;

		long num = __INT_MAX__;
		++num;
		try
		{
			sp.addNumber(num);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}

		sp.addNumber(--num);

		std::cout << (str = "\nADD BEHIND MIN INT NUMBER") << std::endl;
		std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;

		num = -2147483648;
		--num;
		try
		{
			sp.addNumber(num);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}

		sp.addNumber(++num);
		sp.addNumber(-6);
		sp.addNumber(-10);
		sp.addNumber(-5);

		std::cout << (str = "\nADD LIMIT NUMBERS") << std::endl;
		std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;

		std::cout << sp;

		std::cout << (str = "\nFIND SHORTEST SPAN") << std::endl;
		std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
		try
		{
			long shortest = sp.shortestSpan();
			std::cout << "shortest span is " << shortest << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << (str = "\nFIND LONGEST SPAN") << std::endl;
		std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;

		try
		{
			long longest = sp.longestSpan();
			std::cout << "longest span is " << longest << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	// {
	// 	std::cout << (str = "\nCREATEA A SIZE 10 000 SPAN") << std::endl;
	// 	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;

	// 	Span sp(10000);

	// 	sp.addNumber();
	// 	std::cout << sp;
	// }

	return 0;
}
