/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:04:56 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/03 11:04:58 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
	this->_announce();
}

ClapTrap::ClapTrap(unsigned int hitPoints, unsigned int maxHitPoints, unsigned int energyPoints,
	unsigned int maxEnergyPoints, unsigned int level, std::string name, unsigned int meleeAttackDamage,
	unsigned int rangedAttackDamage, unsigned int armorDamageReduction) : _hitPoints(hitPoints), _maxHitPoints(maxHitPoints),
	_energyPoints(energyPoints), _maxEnergyPoints(maxEnergyPoints), _level(level), _name(name), _meleeAttackDamage(meleeAttackDamage),
	_rangedAttackDamage(rangedAttackDamage), _armorDamageReduction(armorDamageReduction) {
	this->_announce();
}

ClapTrap::ClapTrap(const ClapTrap & src) {
	*this = src;
	this->_announce();
}

ClapTrap::~ClapTrap(void) {
	std::cout << "The ClapTrap " << this->_name << " is dead, rest in peace my robotic friend" << std::endl;
}

void ClapTrap::_announce() const {
	std::cout << "BEHOLD VAULTHUNTER!!!! A new Claptrap arrives!!" << std::endl;
}

unsigned int ClapTrap::getHitPoints() const {
	return this->_hitPoints;
}

unsigned int ClapTrap::getMaxHitPoints() const {
	return this->_maxHitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
	return this->_energyPoints;
}

unsigned int ClapTrap::getMaxEnergyPoints() const {
	return this->_maxEnergyPoints;
}

unsigned int ClapTrap::getLevel() const {
	return this->_level;
}

std::string ClapTrap::getName(void) const {
	return this->_name;
}

unsigned int ClapTrap::getMeleeAttackDamage(void) const {
	return this->_meleeAttackDamage;
}

unsigned int ClapTrap::getRangedAttackDamage(void) const {
	return this->_rangedAttackDamage;
}

unsigned int ClapTrap::getArmorDamageReduction() const {
	return this->_armorDamageReduction;
}

void ClapTrap::displayClapTrap() const {
	std::cout << this->_name << "<HP:" << this->_hitPoints << "/" << this->_maxHitPoints;
	std::cout << "-PP:" << this->_energyPoints << "/" << this->_maxEnergyPoints << ">";
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs) {
	this->_hitPoints = rhs.getHitPoints();
	this->_maxHitPoints = rhs.getMaxHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_maxEnergyPoints = rhs.getMaxEnergyPoints();
	this->_level = rhs.getLevel();
	this->_name = rhs.getName();
	this->_meleeAttackDamage = rhs.getMeleeAttackDamage();
	this->_rangedAttackDamage = rhs.getRangedAttackDamage();
	this->_armorDamageReduction = rhs.getArmorDamageReduction();
	return *this;
}

int ClapTrap::beRepaired(unsigned int amount) {
	unsigned int nb_repaired;

	this->displayClapTrap();
	if (this->_hitPoints == this->_maxHitPoints)
	{
		std::cout << " is already fully healed and cannot be repaired" << std::endl;
		return (0);
	}
	nb_repaired = amount + this->_hitPoints < this->_maxHitPoints ? amount : this->_maxHitPoints - this->_hitPoints;
	this->_hitPoints += nb_repaired;
	std::cout << " has earned " << nb_repaired << " HP" << std::endl;
	return (1);
}

int ClapTrap::takeDamage(unsigned int amount) {
	unsigned int effective_damage;

	this->displayClapTrap();
	if (this->_hitPoints == 0)
	{
		std::cout << " has already been defeated and cannot take anymore damage." << std::endl;
		return (0);
	}
	if (amount - this->_armorDamageReduction <= 0)
	{
		std::cout << " is well protected and doesn't take any damage." << std::endl;
		return (0);
	}
	effective_damage = amount - this->_armorDamageReduction;
	effective_damage = effective_damage < this->_hitPoints ? effective_damage : this->_hitPoints;
	this->_hitPoints -= effective_damage;
	std::cout << " has taken " << effective_damage << " points of damage" << std::endl;
	return (1);
}

int ClapTrap::setEnergyPoints(unsigned int amount) {
	int effective_amount;

	this->displayClapTrap();
	std::cout << " tries to gets its energy back : ";
	if (amount > this->_maxEnergyPoints)
	{
		std::cout << "You're punking me ? You can't get that much energy points" << std::endl;
		return (0);
	}
	if (this->_energyPoints == this->_maxEnergyPoints)
	{
		std::cout << "Your energy points are already full" << std::endl;
		return (0);
	}
	effective_amount = amount + this->_energyPoints > this->_maxEnergyPoints ? this->_maxEnergyPoints - this->_energyPoints : amount;
	this->_energyPoints += effective_amount;
	std::cout << " you've earned " << effective_amount << " PP" << std::endl;
	return (1);
}
