/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:58:32 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/04 16:58:34 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant") {
	this->_announce();
}

SuperMutant::SuperMutant(const SuperMutant &src) {
	*this = src;
	this->_announce();
}

void SuperMutant::_announce(void) const {
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant(void) {
	std::cout << "Aaargh..." << std::endl;
}
SuperMutant & SuperMutant::operator=(const SuperMutant &rhs) {
	if (this != &rhs) {
		this->_hp = rhs.getHP();
		this->_type = rhs.getType();
	}
	return *this;
}

void SuperMutant::takeDamage(int amount) {
	Enemy::takeDamage(amount - 3);
}
