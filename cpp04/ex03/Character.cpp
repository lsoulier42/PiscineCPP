/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:09:37 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/07 12:09:38 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("noname") {
	for(int i = 0; i < MAX_MATERIA; i++)
		this->_materias[i] = NULL;
}

Character::Character(const std::string &name) : _name(name) {
	for(int i = 0; i < MAX_MATERIA; i++)
		this->_materias[i] = NULL;
}

Character::Character(const Character &src) {
	for(int i = 0; i < MAX_MATERIA; i++)
		this->_materias[i] = NULL;
	this->_deepCopy(src);
}

Character::~Character() {
	this->_deleteMaterias();
}

void Character::_deepCopy(const Character &src) {
	this->_deleteMaterias();
	this->_name = src.getName();
	for(int i = 0; i < MAX_MATERIA; i++) {
		if (src.getMateria(i))
			this->_materias[i] = src.getMateria(i)->clone();
		else
			this->_materias[i] = NULL;
	}
}

void Character::_deleteMaterias() {
	for(int i = 0; i < MAX_MATERIA; i++)
		if (this->_materias[i])
			delete this->_materias[i];
}

Character & Character::operator=(const Character &rhs) {
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_deepCopy(rhs);
	}
	return *this;
}

std::string const & Character::getName() const {
	return this->_name;
}

AMateria* Character::getMateria(int idx) const {
	if (idx >= 0 && idx < MAX_MATERIA)
		return this->_materias[idx];
	return NULL;
}

void Character::equip(AMateria *m) {
	int idx = -1;

	for(int i = 0; i < MAX_MATERIA; i++) {
		if (this->_materias[i] == NULL)
		{
			idx = i;
			break;
		}
	}
	if (idx >= 0 && m)
		this->_materias[idx] = m;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < MAX_MATERIA && this->_materias[idx] != NULL)
		this->_materias[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx < MAX_MATERIA && this->_materias[idx] != NULL)
		this->_materias[idx]->use(target);
}
