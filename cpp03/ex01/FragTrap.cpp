/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:51:28 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/02 17:51:41 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : _name("FragTrap") {
	this->_announce();
}

FragTrap::FragTrap(const std::string &nameRef) : _hitPoints(100), _maxHitPoints(100), _energyPoints(100),
												 _maxEnergyPoints(100), _level(1), _name(nameRef), _meleeAttackDamage(30),
												 _rangedAttackDamage(20), _armorDamageReduction(5) {
	this->_announce();
}

FragTrap::FragTrap(const FragTrap & src) {
	*this = src;
	this->_announce();
}

FragTrap::~FragTrap(void) {
	this->displayFragTrap();
	std::cout << " is destroyed : Argh arghargh death gurgle gurglegurgle urgh... death" << std::endl;
}

void FragTrap::_announce() const {
	this->displayFragTrap();
	std::cout << " has appeared :" << std::endl;
	std::cout << "   ,\n"
				 "       |\n"
				 "    ]  |.-._      Success! My spell to make you want to hang out with me worked!\n"
				 "     \\|\"(0)\"| _]\n"
				 "     `|=\\#/=|\\/\n"
				 "      :  _  :\n"
				 "       \\/_\\/ \n"
				 "        |=| \n"
				 "        `-' " << std::endl;
}

unsigned int FragTrap::getHitPoints() const {
	return this->_hitPoints;
}

unsigned int FragTrap::getMaxHitPoints() const {
	return this->_maxHitPoints;
}

unsigned int FragTrap::getEnergyPoints() const {
	return this->_energyPoints;
}

unsigned int FragTrap::getMaxEnergyPoints() const {
	return this->_maxEnergyPoints;
}

unsigned int FragTrap::getLevel() const {
	return this->_level;
}

std::string FragTrap::getName(void) const {
	return this->_name;
}

unsigned int FragTrap::getMeleeAttackDamage(void) const {
	return this->_meleeAttackDamage;
}

unsigned int FragTrap::getRangedAttackDamage(void) const {
	return this->_rangedAttackDamage;
}

unsigned int FragTrap::getArmorDamageReduction() const {
	return this->_armorDamageReduction;
}

void FragTrap::displayFragTrap() const {
	std::cout << "FragTrap " << this->_name << "<HP:" << this->_hitPoints << "/" << this->_maxHitPoints;
	std::cout << "-PP:" << this->_energyPoints << "/" << this->_maxEnergyPoints << ">";
}

FragTrap & FragTrap::operator=(FragTrap const & rhs) {
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

int FragTrap::rangedAttack(std::string const & target) {
	this->displayFragTrap();
	if (this->_energyPoints >= RANGED_ATTACK_EP)
	{
		this->_energyPoints -= RANGED_ATTACK_EP;
		std::cout << " attacks " << target;
		std::cout << " at range, causing " << this->_rangedAttackDamage << " points of damage!" << std::endl;
		return (1);
	}
	std::cout << " tries to make a ranged attack";
	std::cout << " but they doesn't have enough energy point..." << std::endl;
	return (0);
}

int FragTrap::meleeAttack(std::string const & target) {
	this->displayFragTrap();
	if (this->_energyPoints >= MELEE_ATTACK_EP)
	{
		this->_energyPoints -= MELEE_ATTACK_EP;
		std::cout << " runs on " << target << " : Hyah! Take that!";
		std::cout << " causing " << this->_meleeAttackDamage << " points of damage!" << std::endl;
		return (1);
	}
	std::cout << " tries to make a melee attack";
	std::cout << " but it doesn't have enough energy point..." << std::endl;
	return (0);
}

int FragTrap::beRepaired(unsigned int amount) {
	unsigned int nb_repaired;

	this->displayFragTrap();
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

int FragTrap::takeDamage(unsigned int amount) {
	unsigned int effective_damage;

	this->displayFragTrap();
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

int FragTrap::vaulthunter_dot_exe(const std::string &target) {
	static int id = 0;
	std::time_t result = std::time(NULL);
	int randomId;
	std::string attacks_names[TOTAL_ATTACKS] = {"Gun Wizard", "Torgue Fiesta", "Pirate Ship Mode",
		"Laser Inferno", "One Shot Wonder"};
	std::string attacks_display[TOTAL_ATTACKS] = {"Uh, how do I cast magic missile?",
		"One for you, one for you, one for you!", "Time to get swabby!",
		"Everybody, dance time! Da-da-da-dun-daaa-da-da-da-dun-daaa!", "Kill, reload! Kill, reload! KILL! RELOAD!"};

	this->displayFragTrap();
	if (this->_energyPoints > VAULTHUNTER_DOT_EXE_EP)
	{
		this->_energyPoints -= VAULTHUNTER_DOT_EXE_EP;
		randomId = (result + id++) % TOTAL_ATTACKS;
		std::cout << " uses vaulthunter.EXE : " << attacks_names[randomId] << std::endl;
		std::cout << attacks_display[randomId] << std::endl;
		std::cout << "It causes " << VAULTHUNTER_DOT_EXE_DAMAGE << " points of damage to ";
		std::cout << target << std::endl;
		return (1);
	}
	std::cout << " tries to make vaulthunter.EXE but doesn't have enought energy point" << std::endl;
	return (0);
}
