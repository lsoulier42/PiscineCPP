/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:54:51 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/02 17:55:05 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : _name("ScavTrap") {
	this->_announce();
}

ScavTrap::ScavTrap(const std::string &nameRef) : _hitPoints(100), _maxHitPoints(100), _energyPoints(50),
_maxEnergyPoints(50), _level(1), _name(nameRef), _meleeAttackDamage(20),
_rangedAttackDamage(15), _armorDamageReduction (3) {
	this->_announce();
}

ScavTrap::ScavTrap(const ScavTrap & src) {
	*this = src;
	this->_announce();
}

ScavTrap::~ScavTrap(void) {
	this->displayScavTrap();
	std::cout << " is dying : No fair! I wasn't ready." << std::endl;
}

void ScavTrap::_announce() const {
	this->displayScavTrap();
	std::cout << " is making its entrance :" << std::endl;
	std::cout << "       _\n"
				 "      [ ]\n"
				 "     (   )     Yes, I do look like the Wish version of a claptrap -_-\n"
				 "      |>|\n"
				 "   __/===\\__\n"
				 "  //| o=o |\\\\\n"
				 "<]  | o=o |  [>\n"
				 "    \\=====/\n"
				 "   / / | \\ \\\n"
				 "  <_________>" << std::endl;
}

unsigned int ScavTrap::getHitPoints() const {
	return this->_hitPoints;
}

unsigned int ScavTrap::getMaxHitPoints() const {
	return this->_maxHitPoints;
}

unsigned int ScavTrap::getEnergyPoints() const {
	return this->_energyPoints;
}

unsigned int ScavTrap::getMaxEnergyPoints() const {
	return this->_maxEnergyPoints;
}

unsigned int ScavTrap::getLevel() const {
	return this->_level;
}

std::string ScavTrap::getName(void) const {
	return this->_name;
}

unsigned int ScavTrap::getMeleeAttackDamage(void) const {
	return this->_meleeAttackDamage;
}

unsigned int ScavTrap::getRangedAttackDamage(void) const {
	return this->_rangedAttackDamage;
}

unsigned int ScavTrap::getArmorDamageReduction() const {
	return this->_armorDamageReduction;
}

void ScavTrap::displayScavTrap() const {
	std::cout << "ScavTrap " << this->_name << "<HP:" << this->_hitPoints << "/" << this->_maxHitPoints;
	std::cout << "-PP:" << this->_energyPoints << "/" << this->_maxEnergyPoints << ">";
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs) {
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

int ScavTrap::setEnergyPoints(unsigned int amount) {
	int effective_amount;

	this->displayScavTrap();
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

int ScavTrap::rangedAttack(std::string const & target) {
	this->displayScavTrap();
	if (this->_energyPoints >= RANGED_ATTACK_EP)
	{
		this->_energyPoints -= RANGED_ATTACK_EP;
		std::cout << " attacks " << target << " with ranged attack : I'm a tornado of death and bullets!";
		std::cout << " causing " << this->_rangedAttackDamage << " points of damage!" << std::endl;
		return (1);
	}
	std::cout << " tries to make a ranged attack";
	std::cout << " but they doesn't have enough energy point..." << std::endl;
	return (0);
}

int ScavTrap::meleeAttack(std::string const & target) {
	this->displayScavTrap();
	if (this->_energyPoints >= MELEE_ATTACK_EP)
	{
		this->_energyPoints -= MELEE_ATTACK_EP;
		std::cout << " runs on " << target << " : This is why you do your homework!";
		std::cout << " causing " << this->_meleeAttackDamage << " points of damage!" << std::endl;
		return (1);
	}
	std::cout << " tries to make a melee attack";
	std::cout << " but it doesn't have enough energy point..." << std::endl;
	return (0);
}

int ScavTrap::beRepaired(unsigned int amount) {
	unsigned int nb_repaired;

	this->displayScavTrap();
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

int ScavTrap::takeDamage(unsigned int amount) {
	unsigned int effective_damage;

	this->displayScavTrap();
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

int ScavTrap::challengeNewcomer(std::string const & target) {
	static int id = 0;
	std::time_t result = std::time(NULL);
	int randomId;
	std::string challenges_names[TOTAL_CHALLENGES] = {"Headhunter", "Lucky Shot", "Relentless",
		"What's in here?", "Pocket Change"};
	std::string challenges_display[TOTAL_CHALLENGES] = {"You have to kill 50 humans",
		"Make as much critical hits as you can, 50 would be a good start",
		"You must kill 5 enemies in succession with no more than 7 seconds in between each kill",
		"Open 50 Lootable objects", "Earn 10,000 Dollars"};

	this->displayScavTrap();
	if (this->_energyPoints >= CHALLENGE_NEWCOMER_EP)
	{
		this->_energyPoints -= CHALLENGE_NEWCOMER_EP;
		randomId = (result + id++) % TOTAL_CHALLENGES;
		std::cout << " wants to challenge " << target;
		std::cout << " and the category is : " << challenges_names[randomId] << std::endl;
		std::cout << challenges_display[randomId] << std::endl;
		return (1);
	}
	std::cout << " doesn't have enough point to challenge a new comer." << std::endl;
	return (0);
}
