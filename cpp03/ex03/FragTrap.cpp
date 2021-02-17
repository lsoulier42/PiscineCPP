/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 23:08:30 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/02 23:08:33 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
	this->_announce();
}

FragTrap::FragTrap(const std::string &nameRef) : ClapTrap(100, 100, 100, 100, 1, nameRef,
	30, 20, 5) {
	this->_announce();
}

FragTrap::FragTrap(const FragTrap & src) {
	*this = src;
	this->_announce();
}

FragTrap::~FragTrap(void) {
	this->displayClapTrap();
	std::cout << " - the FragTrap - is destroyed : Argh arghargh death gurgle gurglegurgle urgh... death" << std::endl;
}

void FragTrap::_announce() const {
	this->displayClapTrap();
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
	this->displayClapTrap();
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
	this->displayClapTrap();
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

int FragTrap::vaulthunter_dot_exe(const std::string &target) {
	static int id = 0;
	std::time_t result = std::time(NULL);
	int randomId;
	std::string attacks_names[TOTAL_ATTACKS] = {"Gun Wizard", "Torgue Fiesta", "Pirate Ship Mode",
		"Laser Inferno", "One Shot Wonder"};
	std::string attacks_display[TOTAL_ATTACKS] = {"Uh, how do I cast magic missile?",
		"One for you, one for you, one for you!", "Time to get swabby!",
		"Everybody, dance time! Da-da-da-dun-daaa-da-da-da-dun-daaa!", "Kill, reload! Kill, reload! KILL! RELOAD!"};

	this->displayClapTrap();
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
