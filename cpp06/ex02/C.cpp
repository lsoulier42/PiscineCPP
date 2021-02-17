/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:49:45 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/10 18:49:46 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

C::C() {
	std::cout << "Object C created" << std::endl;
}

C::C(const C &src) {
	*this = src;
}

C & C::operator=(const C &rhs) {
	(void)rhs;
	return *this;
}

C::~C() {
}
