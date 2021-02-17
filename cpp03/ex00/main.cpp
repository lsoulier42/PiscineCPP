/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 21:36:33 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/01 21:36:35 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap clap("CL4P-TP");
	FragTrap josy("J0XS-TP");

	if (clap.meleeAttack(josy.getName()))
		josy.takeDamage(clap.getMeleeAttackDamage());
	if (josy.rangedAttack(clap.getName()))
		clap.takeDamage(josy.getRangedAttackDamage());
	if (clap.vaulthunter_dot_exe(josy.getName()))
		josy.takeDamage(VAULTHUNTER_DOT_EXE_DAMAGE);
	if (josy.vaulthunter_dot_exe(clap.getName()))
		clap.takeDamage(VAULTHUNTER_DOT_EXE_DAMAGE);
	if (josy.vaulthunter_dot_exe(clap.getName()))
		clap.takeDamage(VAULTHUNTER_DOT_EXE_DAMAGE);
	josy.beRepaired(50);
	clap.beRepaired(1000);
	if (josy.vaulthunter_dot_exe(clap.getName()))
		clap.takeDamage(VAULTHUNTER_DOT_EXE_DAMAGE);
	if (josy.vaulthunter_dot_exe(clap.getName()))
		clap.takeDamage(VAULTHUNTER_DOT_EXE_DAMAGE);
	return(0);
}
