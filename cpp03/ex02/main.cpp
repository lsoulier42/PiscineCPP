/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 20:27:28 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/02 20:27:30 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap mother(100, 100, 100, 100, 1, "5L5-TP", 30, 20, 5);
	FragTrap clap("CL4P-TP");
	ScavTrap cucumber("CU5TM-TP");

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
	return(0);
}
