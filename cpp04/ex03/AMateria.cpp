/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:08:46 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/07 12:08:47 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _xp(0), _type("noname") {
}

AMateria::AMateria(const std::string &type) : _xp(0), _type(type) {
}

AMateria::AMateria(const AMateria &src) {
	*this = src;
}

AMateria::~AMateria() {
}

AMateria & AMateria::operator=(const AMateria &rhs) {
	if (this != &rhs) {
		this->_type = rhs.getType();
		this->_xp = rhs.getXP();
	}
	return *this;
}

std::string const & AMateria::getType() const {
	return this->_type;
}

unsigned int AMateria::getXP() const {
	return this->_xp;
}

void AMateria::use(ICharacter& target) {
	(void)target;
	this->_xp += 10;
}
