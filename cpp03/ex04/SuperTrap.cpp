/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:08:30 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/03 11:08:32 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void) {
	this->_announce();
}

SuperTrap::SuperTrap(const std::string &nameRef) : ClapTrap(100, 100, 120, 120, 1, nameRef, 60, 20, 5),
FragTrap(nameRef), NinjaTrap(nameRef) {
	this->_announce();
}

SuperTrap::SuperTrap(const SuperTrap &src) {
	this->_announce();
	*this = src;
}

SuperTrap::~SuperTrap() {
	this->displayClapTrap();
	std::cout << " - the SuperTrap - can never die (except with kryptonite)" << std::endl;
}

void SuperTrap::_announce() const {
	this->displayClapTrap();
	std::cout << " flies in the air :" << std::endl;
	std::cout << "             .=.,\n"
				 "            ;c =\\\n"
				 "          __|  _/     I will prove to you my robotic superiority!\n"
				 "        .'-'-._/-'-._\n"
				 "       /..   ____    \\\n"
				 "      /' _  [<_->] )  \\\n"
				 "     (  / \\--\\_>/-/'._ )\n"
				 "      \\-;_/\\__;__/ _/ _/\n"
				 "       '._}|==o==\\{_\\/\n"
				 "        /  /-._.--\\  \\_\n"
				 "       // /   /|   \\ \\ \\\n"
				 "      / | |   | \\;  |  \\ \\\n"
				 "     / /  | :/   \\: \\   \\_\\\n"
				 "    /  |  /.'|   /: |    \\ \\\n"
				 "    |  |  |--| . |--|     \\_\\\n"
				 "    / _/   \\ | : | /___--._) \\\n"
				 "   |_(---'-| >-'-| |       '-'\n"
				 "snd       /_/     \\_\\" << std::endl;
}

SuperTrap & SuperTrap::operator=(SuperTrap const & rhs) {
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

int SuperTrap::rangedAttack(const std::string &target) {
	return FragTrap::rangedAttack(target);
}

int SuperTrap::meleeAttack(const std::string &target) {
	return NinjaTrap::meleeAttack(target);
}
