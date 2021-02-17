/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 23:09:56 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/02 23:09:58 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void) {
	this->_announce();
}

NinjaTrap::NinjaTrap(std::string const & nameRef) : ClapTrap(60, 60, 120, 120, 1, nameRef, 60, 5, 0) {
	this->_announce();
}

NinjaTrap::NinjaTrap(NinjaTrap const & src) {
	*this = src;
	this->_announce();
}

NinjaTrap::~NinjaTrap() {
	this->displayClapTrap();
	std::cout << " - the NinjaTrap - has gone out : Good thing I don't have a soul!" << std::endl;
}

void NinjaTrap::_announce(void) {
	this->displayClapTrap();
	std::cout << " comes out of nowhere :" << std::endl;
	std::cout << "      ___\n"
				 "     /___\\_/\n"
				 "     |\\_/|<\\    I'm a robot ninja...I'm invisible!\n"
				 "     (`o`) `   __(\\_            |\\_\n"
				 "     \\ ~ /_.-`` _|__)  ( ( ( ( /()/\n"
				 "    _/`-`  _.-``               `\\|\n"
				 " .-`      (    .-.\n"
				 "(   .-     \\  /   `-._\n"
				 " \\  (\\_    /\\/        `-.__-()\n"
				 "  `-|__)__/ /  /``-.   /_____8\n"
				 "        \\__/  /     `-`\n"
				 "       />|   /\n"
				 "      /| J   L\n"
				 "      `` |   |\n"
				 "         L___J\n"
				 "          ( |" << std::endl;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & rhs) {
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

int NinjaTrap::rangedAttack(std::string const & target) {
	this->displayClapTrap();
	if (this->_energyPoints >= RANGED_ATTACK_EP)
	{
		this->_energyPoints -= RANGED_ATTACK_EP;
		std::cout << " attacks at range the mighty " << target;
		std::cout << " : Roses are red and/Violets are blue/Wait... how many syllables was that?";
		std::cout << " causing " << this->_rangedAttackDamage << " points of damage!" << std::endl;
		return (1);
	}
	std::cout << " tries to make a ranged attack";
	std::cout << " but they doesn't have enough energy point..." << std::endl;
	return (0);
}

int NinjaTrap::meleeAttack(std::string const & target) {
	this->displayClapTrap();
	if (this->_energyPoints >= MELEE_ATTACK_EP)
	{
		this->_energyPoints -= MELEE_ATTACK_EP;
		std::cout << " runs on the vicious " << target << " : I AM ON FIRE!!! OH GOD, PUT ME OUT!!";
		std::cout << " causing " << this->_meleeAttackDamage << " points of damage!" << std::endl;
		return (1);
	}
	std::cout << " tries to make a melee attack";
	std::cout << " but it doesn't have enough energy point..." << std::endl;
	return (0);
}

int NinjaTrap::ninjaShoebox(ClapTrap & target) {
	this->displayClapTrap();
	if (this->_energyPoints < NINJA_SHOEBOX_EP)
	{
		std::cout << " tries to make a ninja shoebox attacks, but doesn't have enough energy" << std::endl;
		return (0);
	}
	this->_energyPoints -= NINJA_SHOEBOX_EP;
	std::cout <<  " uses NinjaShoebox attack : ";
	std::cout << " it's throwing a slice of sharp pizza at the terrific " << target.getName() << std::endl;
	target.takeDamage(NINJA_SHOEBOX_DAMAGE);
	return (1);
}

int NinjaTrap::ninjaShoebox(FragTrap & target) {
	this->displayClapTrap();
	if (this->_energyPoints < NINJA_SHOEBOX_EP)
	{
		std::cout << " tries to make a ninja shoebox attacks, but doesn't have enough energy" << std::endl;
		return (0);
	}
	this->_energyPoints -= NINJA_SHOEBOX_EP;
	std::cout <<  " uses NinjaShoebox attack : ";
	std::cout << " it beats the hideous " << target.getName() << " with its awsome Nunchaku of death" << std::endl;
	target.takeDamage(NINJA_SHOEBOX_DAMAGE);
	return (1);
}

int NinjaTrap::ninjaShoebox(ScavTrap & target) {
	this->displayClapTrap();
	if (this->_energyPoints < NINJA_SHOEBOX_EP)
	{
		std::cout << " tries to make a ninja shoebox attacks, but doesn't have enough energy" << std::endl;
		return (0);
	}
	this->_energyPoints -= NINJA_SHOEBOX_EP;
	std::cout <<  " uses NinjaShoebox attack : ";
	std::cout << " it's using its katana from Hattori Hanzo againt the dreadful " << target.getName() << std::endl;
	target.takeDamage(NINJA_SHOEBOX_DAMAGE);
	return (1);
}

int NinjaTrap::ninjaShoebox(NinjaTrap & target) {
	this->displayClapTrap();
	if (this->_energyPoints < NINJA_SHOEBOX_EP)
	{
		std::cout << " tries to make a ninja shoebox attacks, but doesn't have enough energy" << std::endl;
		return (0);
	}
	if (this == &target)
	{
		std::cout << " tries to attack " << target.getName() << " but it cannot attack himself" << std::endl;
		return (0);
	}
	this->_energyPoints -= NINJA_SHOEBOX_EP;
	std::cout <<  " uses NinjaShoebox attack : ";
	std::cout << " it's trying to get at " << target.getName() << " but its moves to fast to touch him" << std::endl;
	return (1);
}
