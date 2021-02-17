/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:56:39 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/10 18:56:40 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

Base* makeA(void) {
	return new A;
}

Base* makeB(void) {
	return new B;
}

Base* makeC(void) {
	return new C;
}

Base* generate(void) {
	static int add = 42;
	Base* (*tab_fct[3])(void) = {&makeA, &makeB, &makeC};
	std::srand(std::time(NULL));
	Base* ret = (tab_fct[(rand() + add) % 3])();
	add += 20;
	return ret;
}

void identify_from_pointer(Base * p) {
	A* a = dynamic_cast<A*>(p);
	B* b = dynamic_cast<B*>(p);
	C* c = dynamic_cast<C*>(p);

	std::cout << "/!\\ Identification from pointer /!\\" << std::endl;
	std::cout << "The type of the randomly generate pointer is : ";
	if (a)
		std::cout << "A";
	else if (b)
		std::cout << "B";
	else if (c)
		std::cout << "C";
	else
		std::cout << "unknown";
	std::cout << std::endl;
	std::cout << std::endl;
}

void identify_from_reference(Base & ref) {
	std::cout << "/!\\ Identification from reference /!\\" << std::endl;
	std::cout << "The type of the randomly generate pointer is : ";
	try {
		A & a = dynamic_cast<A&>(ref);
		(void)a;
		std::cout << "A";
	}
	catch (std::exception & e) {
		(void)e;
	}

	try {
		B & b = dynamic_cast<B&>(ref);
		(void)b;
		std::cout << "B";
	}
	catch (std::exception & e) {
		(void)e;
	}

	try {
		C & c = dynamic_cast<C&>(ref);
		(void)c;
		std::cout << "C";
	}
	catch (std::exception & e) {
		(void)e;
	}

	std::cout << std::endl;
}
