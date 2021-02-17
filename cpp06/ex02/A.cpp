/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:49:25 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/10 18:49:25 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

A::A() {
	std::cout << "Object A created" << std::endl;
}

A::A(const A &src) {
	*this = src;
}

A::~A() {
}

A & A::operator=(const A &rhs) {
	(void)rhs;
	return *this;
}
