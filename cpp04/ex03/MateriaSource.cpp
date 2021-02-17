/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:09:53 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/07 12:09:54 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for(int i = 0; i < MAX_MATERIA; i++)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src) {
	for(int i = 0; i < MAX_MATERIA; i++)
		this->_materias[i] = NULL;
	this->_deepCopy(src);
}

MateriaSource::~MateriaSource() {
	this->_deleteMaterias();
}

void MateriaSource::_deleteMaterias() {
	for(int i = 0; i < MAX_MATERIA; i++)
		if (this->_materias[i])
			delete this->_materias[i];
}

void MateriaSource::_deepCopy(const MateriaSource &src) {
	this->_deleteMaterias();
	for(int i = 0; i < MAX_MATERIA; i++) {
		if (src.getMateria(i) != NULL)
			this->_materias[i] = src.getMateria(i)->clone();
		else
			this->_materias[i] = NULL;
	}
}

MateriaSource & MateriaSource::operator=(const MateriaSource &rhs) {
	if (this != &rhs)
		this->_deepCopy(rhs);
	return *this;
}

AMateria* MateriaSource::getMateria(int idx) const {
	if (idx >= 0 && idx < MAX_MATERIA)
		return this->_materias[idx];
	return NULL;
}

void MateriaSource::learnMateria(AMateria *m) {
	int idx = -1;

	for(int i = 0; i < MAX_MATERIA; i++) {
		if (this->_materias[i] == NULL) {
			idx = i;
			break;
		}
	}
	if (idx >= 0 && m)
		this->_materias[idx] = m;
}

AMateria* MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (this->_materias[i] && this->_materias[i]->getType() == type)
			return this->_materias[i]->clone();
	}
	return (NULL);
}
