/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:17:54 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/03 17:17:56 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string const & nameRef,
	std::string const & titleRef) : _name(nameRef), _title(titleRef) {
	this->_announce();
}

Sorcerer::Sorcerer(Sorcerer const & src) {
	*this = src;
	this->_announce();
}

Sorcerer::~Sorcerer() {
	std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same!" << std::endl;
}

void Sorcerer::_announce() const {
	std::cout << this->_name << ", " << this->_title << ", is born!" << std::endl;
}

Sorcerer & Sorcerer::operator=(Sorcerer const & rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_title = rhs.getTitle();
	}
	return *this;
}

std::string const & Sorcerer::getName(void) const {
	return this->_name;
}

std::string const & Sorcerer::getTitle(void) const {
	return this->_title;
}

void Sorcerer::polymorph(Victim const & src) const {
	src.getPolymorphed();
}

std::ostream & operator<<(std::ostream & o, Sorcerer & src) {
	o << "I am " << src.getName() << ", " << src.getTitle() << " and I like ponies!" << std::endl;
	return o;
}
