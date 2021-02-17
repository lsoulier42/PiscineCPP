/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:40:48 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/02 19:40:54 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	FragTrap clap("CL4P-TP");
	ScavTrap cucumber("CU5TM-TP");

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
