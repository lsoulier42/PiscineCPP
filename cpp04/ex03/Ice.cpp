/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:09:06 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/07 12:09:07 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
}

Ice::Ice(const Ice &src) {
	*this = src;
}

Ice::~Ice() {
}

Ice & Ice::operator=(const Ice &rhs) {
	if (this != &rhs)
		this->_xp = rhs.getXP();
	return *this;
}

Ice* Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
	this->AMateria::use(target);
}
