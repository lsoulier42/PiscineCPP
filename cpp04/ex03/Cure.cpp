/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:09:20 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/07 12:09:22 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
}

Cure::Cure(const Cure &src) {
	*this = src;
}

Cure::~Cure() {
}

Cure & Cure::operator=(const Cure &rhs) {
	if (this != &rhs)
		this->_xp = rhs.getXP();
	return *this;
}

Cure* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	this->AMateria::use(target);
}
