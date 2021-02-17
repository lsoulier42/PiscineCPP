/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 12:25:36 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/05 12:25:41 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad() : _beginMarines(NULL) {
}

t_list* Squad::_engageMarine(ISpaceMarine *current) {
	t_list *new_marine;

	new_marine = new t_list;
	new_marine->marine = current;
	new_marine->next = NULL;
	return (new_marine);
}

void Squad::_deleteMarines() {
	t_list *el = this->_beginMarines;
	t_list *next;

	while (el)
	{
		delete el->marine;
		next = el->next;
		delete el;
		el = next;
	}
}

void Squad::_deepCopy(const Squad &src) {
	int nb = src.getCount();

	this->_deleteMarines();
	for(int i = 0; i < nb; i++) {
		this->push(src.getUnit(i)->clone());
	}
}

Squad::Squad(const Squad &src) : _beginMarines(NULL) {
	this->_deepCopy(src);
}

Squad::~Squad() {
	this->_deleteMarines();
}

Squad & Squad::operator=(const Squad &rhs) {
	if (this != &rhs)
		this->_deepCopy(rhs);
	return *this;
}

int Squad::getCount() const {
	int i = 0;
	t_list *el = this->_beginMarines;

	while (el)
	{
		i++;
		el = el->next;
	}
	return (i);
}

ISpaceMarine* Squad::getUnit(int N) const {
	int i = 0;
	t_list *el = this->_beginMarines;

	while (el)
	{
		if (N == i)
			break ;
		i++;
		el = el->next;
	}
	return (el->marine);
}

int Squad::push(ISpaceMarine *current) {
	t_list *el = this->_beginMarines;
	int i = 0;

	if (el)
	{
		while (el->next)
		{
			if (el->marine == current)
				return (0);
			i++;
			el = el->next;
		}
		el->next = this->_engageMarine(current);
		return (i + 1);
	}
	this->_beginMarines = this->_engageMarine(current);
	return (1);
}
