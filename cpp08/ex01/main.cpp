/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 23:38:31 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/12 23:38:32 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main()
{
	std::cout << "The first tests are the main from the subject :" << std::endl;
	Span sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	sp.display_span();
	std::cout << "The shortest span is: " << sp.shortestSpan() << std::endl;
	std::cout << "The longest span is: " << sp.longestSpan() << std::endl;

	std::cout << std::endl;
	std::cout << "The second tests will test the exceptions: " << std::endl;
	Span sp2 = Span(1);

	sp2.addNumber(45);
	sp2.display_span();
	std::cout << "Test limit for shortest span: ";
	try {
		int test = sp2.shortestSpan();
		std::cout << "The shortest span is:" << test << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "Test limit for longest span: ";
	try {
		int test = sp2.longestSpan();
		std::cout << "The longest span is:" << test << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "Test limit of the class by adding another: ";
	try {
		sp2.addNumber(56);
		std::cout << "The int 56 has been added to the class successfully (which shouldn't happen)" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "The third tests will test the range add number and his exception: " << std::endl;
	Span sp3 = Span(50);

	sp3.addNumber(-10, 30);
	sp3.display_span();
	std::cout << "The shortest span is: " << sp3.shortestSpan() << std::endl;
	std::cout << "The longest span is: " << sp3.longestSpan() << std::endl;

	std::cout << "Now let's test the exception by adding 100 more numbers: ";
	try {
		sp3.addNumber(-50, 50);
		std::cout << "The range of int has been added successfully (which shouldn't happen)" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
