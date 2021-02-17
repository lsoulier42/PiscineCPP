/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:44:47 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/04 19:44:48 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("noname"), _ap(MAX_AP), _weapon(0) {
}

Character::Character(const std::string &name) : _name(name), _ap(MAX_AP), _weapon(0) {
}

Character::Character(const Character &src) {
	*this = src;
}

Character::~Character(void) {
}

Character & Character::operator=(const Character &rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_weapon = rhs.getWeapon();
		this->_ap = rhs.getAP();
	}
	return *this;
}

std::string const & Character::getName(void) const {
	return this->_name;
}

int Character::getAP(void) const {
	return this->_ap;
}

AWeapon* Character::getWeapon(void) const {
	return this->_weapon;
}

void Character::recoverAP(void) {
	int nb_effective;

	nb_effective = this->_ap < MAX_AP - RECOVER_AP ? RECOVER_AP : MAX_AP - this->_ap;
	this->_ap += nb_effective;
}

void Character::equip(AWeapon *newWeapon) {
	this->_weapon = newWeapon;
}

void Character::attack(Enemy *enemy) {
	if (this->_weapon && this->_ap >= this->_weapon->getAPCost())
	{
		std::cout << this->_name << " attacks " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
		this->_weapon->attack();
		this->_ap -= this->_weapon->getAPCost();
		enemy->takeDamage(this->_weapon->getDamage());
		if(enemy->getHP() <= 0)
			delete(enemy);
	}
}

std::ostream & operator<<(std::ostream & o, Character & src)
{
	o << src.getName() << " has " << src.getAP() << " AP and ";
	if (src.getWeapon())
		o << "wields a " << src.getWeapon()->getName() << std::endl;
	else
		o << "is unarmed" << std::endl;
	return o;
}
