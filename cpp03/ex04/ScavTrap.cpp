/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:06:03 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/03 11:06:04 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
	this->_announce();
}

ScavTrap::ScavTrap(const std::string &nameRef) : ClapTrap(100, 100, 50, 50, 1, nameRef,
		20, 15, 3) {
	this->_announce();
}

ScavTrap::ScavTrap(const ScavTrap & src) {
	*this = src;
	this->_announce();
}

ScavTrap::~ScavTrap(void) {
	this->displayClapTrap();
	std::cout << " - the ScavTrap - is dying : No fair! I wasn't ready." << std::endl;
}

void ScavTrap::_announce() const {
	this->displayClapTrap();
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

int ScavTrap::rangedAttack(std::string const & target) {
	this->displayClapTrap();
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
	this->displayClapTrap();
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

	this->displayClapTrap();
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
