/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:49:35 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/10 18:49:35 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

B::B() {
	std::cout << "Object B created" << std::endl;
}

B::B(const B &src) {
	*this = src;
}

B & B::operator=(const B &rhs) {
	(void)rhs;
	return *this;
}

B::~B() {
}
