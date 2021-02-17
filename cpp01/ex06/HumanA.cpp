/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 14:59:49 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/29 15:00:03 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &hisWeapon) : _name(name), _hisWeapon(hisWeapon) {
}

HumanA::~HumanA() {
}

void HumanA::attack() const {
	std::cout << this->_name << " attacks with his " << this->_hisWeapon.getType() << std::endl;
}
