/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:18:09 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/03 17:18:11 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim() : _name("noname") {
	this->_announce();
}

Victim::Victim(std::string const & nameRef) : _name(nameRef) {
	this->_announce();
}

Victim::Victim(const Victim &src) {
	*this = src;
	this->_announce();
}

Victim::~Victim(void) {
	std::cout << "Victim " << this->_name << " just died for no apparent reason!" << std::endl;
}

void Victim::_announce(void) const {
	std::cout << "Some random victim called " << this->_name << " just appeared!" << std::endl;
}

std::string const & Victim::getName(void) const {
	return this->_name;
}

Victim & Victim::operator=(const Victim &rhs) {
	if (this != &rhs)
		this->_name = rhs.getName();
	return *this;
}

void Victim::getPolymorphed(void) const {
	std::cout << this->_name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream & operator<<(std::ostream & o, Victim & src){
	o << "I'm " << src.getName() << " and I like otters!" << std::endl;
	return o;
}
