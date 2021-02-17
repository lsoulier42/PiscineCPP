/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:31:14 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/29 12:31:22 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N) : _nb_zombies(N) {
	this->_zombies = new Zombie[N];
	for (int i = 0; i < this->_nb_zombies; i++) {
		_zombies[i].setName(getRandomName());
		_zombies[i].setType("ugly");
	}
}

ZombieHorde::~ZombieHorde() {
	delete [] _zombies;
}

void ZombieHorde::announce() const {
	for (int i = 0; i < this->_nb_zombies; i++) {
		_zombies[i].announce();
	}
}

std::string  ZombieHorde::getRandomName() const {
	std::string names[] = {"Ambrine", "Bettina", "Colombe", "Ysee", "Eudoxie",
		"Claire-Marie",	"Garance", "Aristide", "Charles-Henri", "Cyr", "Franklin",
		"Pierre-Antoine", "Mayeul", "Jean-Eude"};
	int size = 14;
	static int rand_int = 0;
	std::time_t result = std::time(NULL);

	return (names[(result + rand_int++) % size]);
}
