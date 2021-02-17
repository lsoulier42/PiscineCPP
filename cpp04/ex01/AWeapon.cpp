/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:56:18 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/04 16:56:20 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon() : _name("noname"), _apcost(0), _damage(0) {
}

AWeapon::AWeapon(const std::string &name, int apcost, int damage) : _name(name),
	_apcost(apcost), _damage(damage) {
}

AWeapon::AWeapon(const AWeapon &src) {
	*this = src;
}

AWeapon::~AWeapon(void) {
}

AWeapon & AWeapon::operator=(const AWeapon &rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_apcost = rhs.getAPCost();
		this->_damage = rhs.getDamage();
	}
	return *this;
}

std::string const & AWeapon::getName() const {
	return this->_name;
}

int AWeapon::getDamage(void) const {
	return this->_damage;
}

int AWeapon::getAPCost(void) const {
	return this->_apcost;
}
