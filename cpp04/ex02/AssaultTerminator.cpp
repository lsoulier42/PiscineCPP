/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 12:26:28 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/05 12:26:29 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator() {
	this->_announce();
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator &src) {
	*this = src;
	this->_announce();
}

void AssaultTerminator::_announce() const {
	std::cout << "* teleports from space *" << std::endl;
}

void AssaultTerminator::battleCry() const {
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void AssaultTerminator::rangedAttack() const {
	std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack() const {
	std::cout << "* attacks with chainfists *" << std::endl;
}

AssaultTerminator::~AssaultTerminator() {
	std::cout << "I’ll be back..." << std::endl;
}

AssaultTerminator & AssaultTerminator::operator=(const AssaultTerminator &rhs) {
	(void)rhs;
	return *this;
}

AssaultTerminator* AssaultTerminator::clone() const {
	return new AssaultTerminator(*this);
}
