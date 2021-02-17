/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:29:38 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/29 12:29:42 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
}

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type) {
}

Zombie::~Zombie() {
	std::cout << "The zombie named " << this->_name << " is dead (again)." << std::endl;
}

void Zombie::announce() const {
	std::cout << "<" << this->_name << "> (" << this->_type << ")> Braiiiiiiinnnssss..." << std::endl;
}

std::string Zombie::getName() const {
	return (this->_name);
}

void Zombie::setName(std::string value) {
	this->_name = value;
}

std::string Zombie::getType() const {
	return (this->_type);
}

void Zombie::setType(std::string value) {
	this->_type = value;
}
