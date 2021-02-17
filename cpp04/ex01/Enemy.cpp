/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:58:16 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/04 16:58:17 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy() : _hp(0), _type("notype") {
}

Enemy::Enemy(int hp, std::string const & type) : _hp(hp), _type(type) {
}

Enemy::Enemy(Enemy const & src) {
	*this = src;
}

Enemy::~Enemy(void) {
}

Enemy & Enemy::operator=(const Enemy &rhs) {
	if (this != &rhs) {
		this->_hp = rhs.getHP();
		this->_type = rhs.getType();
	}
	return *this;
}

std::string const & Enemy::getType(void) const {
	return this->_type;
}

int Enemy::getHP(void) const {
	return this->_hp;
}

void Enemy::takeDamage(int amount) {
	int nb_effective;

	if (amount >= 0) {
		nb_effective = amount > this->_hp ? this->_hp : amount;
		this->_hp -= nb_effective;
	}
}
