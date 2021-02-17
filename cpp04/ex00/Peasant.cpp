/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peasant.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:49:50 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/04 11:49:53 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peasant.hpp"

Peasant::Peasant() : Victim() {
	this->_announce();
}

Peasant::Peasant(const std::string &nameRef) : Victim(nameRef) {
	this->_announce();
}

Peasant::Peasant(const Peasant &src) {
	*this = src;
	this->_announce();
}

void Peasant::_announce() const {
	std::cout << "Yes, milord! Ready to work." << std::endl;
}

Peasant::~Peasant(void) {
	std::cout << "That's it. I'm dead." << std::endl;
}

Peasant & Peasant::operator=(Peasant const & rhs) {
	if (this != &rhs)
		this->_name = rhs.getName();
	return *this;
}

void Peasant::getPolymorphed(void) const {
	std::cout << this->_name << " has been turned into a dumb ork!" << std::endl;
}
