/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:18:24 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/03 17:18:34 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon() : Victim() {
	this->_announce();
}

Peon::Peon(std::string const & nameRef) : Victim(nameRef) {
	this->_announce();
}

Peon::Peon(const Peon &src) {
	*this = src;
	this->_announce();
}

void Peon::_announce() const {
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon(void) {
	std::cout << "Bleuark..." << std::endl;
}

Peon & Peon::operator=(const Peon &rhs) {
	if (this != &rhs)
		this->_name = rhs.getName();
	return *this;
}

void Peon::getPolymorphed(void) const {
	std::cout << this->_name << " has been turned into a pink pony!" << std::endl;
}
