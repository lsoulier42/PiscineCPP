/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:58:02 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/04 16:58:03 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50) {
}

PowerFist::PowerFist(const PowerFist &src) {
	*this = src;
}

PowerFist::~PowerFist(void) {
}

PowerFist & PowerFist::operator=(const PowerFist &rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_apcost = rhs.getAPCost();
		this->_damage = rhs.getDamage();
	}
	return *this;
}

void PowerFist::attack(void) const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
