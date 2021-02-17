/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:19:44 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/29 10:19:56 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent() {
}

ZombieEvent::~ZombieEvent() {
}

void ZombieEvent::setZombieType(std::string value) {
	this->_type = value;
}

Zombie* ZombieEvent::newZombie(std::string name) const {
	Zombie* current = new Zombie(name, this->_type);
	current->announce();
	return (current);
}

std::string  ZombieEvent::_getRandomName() const {
	std::string names[] = {"Ambrine", "Bettina", "Colombe", "Ysee", "Eudoxie",
		"Claire-Marie",	"Garance", "Aristide", "Charles-Henri", "Cyr", "Franklin",
		"Pierre-Antoine", "Mayeul", "Jean-Eude"};
	int size = 14;
	std::time_t result = std::time(NULL);

	return (names[result % size]);
}

void ZombieEvent::randomChump() const {
	Zombie current = Zombie(this->_getRandomName(), this->_type);
	current.announce();
}
