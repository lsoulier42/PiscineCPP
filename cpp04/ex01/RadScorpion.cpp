/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:58:56 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/04 16:58:57 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion(void) : Enemy(80, "RadScorpion") {
	this->_announce();
}

RadScorpion::RadScorpion(const RadScorpion &src) {
	*this = src;
	this->_announce();
}

void RadScorpion::_announce(void) const {
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion(void) {
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion & RadScorpion::operator=(const RadScorpion &rhs) {
	if (this != &rhs) {
		this->_type = rhs.getType();
		this->_hp = rhs.getHP();
	}
	return *this;
}
