/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 14:57:20 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/29 14:57:32 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
}

Weapon::~Weapon() {
}

std::string const & Weapon::getType() const {
	std::string const & typeRef = this->_type;
	return (typeRef);
}

void Weapon::setType(std::string type) {
	this->_type = type;
}
