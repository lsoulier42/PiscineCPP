/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:01:23 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/29 15:01:35 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _hisWeapon(NULL) {
}

HumanB::~HumanB() {
}

void HumanB::attack() const {
	if (this->_hisWeapon)
		std::cout << this->_name << " attacks with his " << this->_hisWeapon->getType() << std::endl;
	else
		std::cout << this->_name << " doesn't have a weapon" << std::endl;
}

void HumanB::setWeapon(Weapon &newWeapon) {
	this->_hisWeapon = &newWeapon;
}
