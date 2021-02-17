/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:05:36 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/03 11:05:38 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main()
{
	ClapTrap mother(100, 100, 100, 100, 1, "5L5-TP", 30, 20, 5);
	FragTrap clap("CL4P-TP");
	ScavTrap cucumber("CU5TM-TP");
	NinjaTrap cobrakai("C0BR4-TP");
	SuperTrap superman("SUP5R-TP");

	if(clap.rangedAttack(mother.getName()))
		mother.takeDamage(clap.getRangedAttackDamage());
	if (clap.meleeAttack(cucumber.getName()))
		cucumber.takeDamage(clap.getMeleeAttackDamage());
	if (cucumber.rangedAttack(clap.getName()))
		clap.takeDamage(cucumber.getRangedAttackDamage());
	if (cucumber.meleeAttack(clap.getName()))
		clap.takeDamage(cucumber.getMeleeAttackDamage());
	if (clap.vaulthunter_dot_exe(cucumber.getName()))
		cucumber.takeDamage(VAULTHUNTER_DOT_EXE_DAMAGE);
	cucumber.beRepaired(50);
	clap.beRepaired(1000);

	cucumber.challengeNewcomer(clap.getName());
	cucumber.setEnergyPoints(1000);
	cucumber.setEnergyPoints(50);
	cucumber.challengeNewcomer(clap.getName());
	cucumber.challengeNewcomer(clap.getName());

	cobrakai.ninjaShoebox(mother);
	cobrakai.ninjaShoebox(clap);
	cobrakai.ninjaShoebox(cucumber);
	cobrakai.ninjaShoebox(cobrakai);

	cobrakai.beRepaired(100);
	cucumber.beRepaired(100);
	clap.beRepaired(100);

	if (superman.rangedAttack(cobrakai.getName()))
		cobrakai.takeDamage(superman.getRangedAttackDamage());
	superman.ninjaShoebox(cobrakai);
	superman.setEnergyPoints(100);
	if(superman.vaulthunter_dot_exe(cucumber.getName()))
		cucumber.takeDamage(VAULTHUNTER_DOT_EXE_DAMAGE);

	return(0);
}
