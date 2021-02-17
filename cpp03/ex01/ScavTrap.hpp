/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:55:17 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/02 17:56:00 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include <ctime>
# include <string>
# define RANGED_ATTACK_EP 10
# define MELEE_ATTACK_EP 15
# define CHALLENGE_NEWCOMER_EP 25

typedef enum	e_challenge_newcomer_attack {
	HEADHUNTER,
	LUCKY_SHOT,
	RELENTLESS,
	WHATS_IN_HERE,
	POCKET_CHANGE,
	TOTAL_CHALLENGES
}				t_challenge_newcomer_attack;

class ScavTrap {
public:
	ScavTrap(void);
	ScavTrap(std::string const & nameRef);
	ScavTrap(ScavTrap const & src);
	~ScavTrap(void);

	ScavTrap & operator=(ScavTrap const & rhs);
	int rangedAttack(std::string const & target);
	int meleeAttack(std::string const & target);
	int beRepaired(unsigned int amount);
	int takeDamage(unsigned int amount);
	int challengeNewcomer(std::string const & target);


	unsigned int getHitPoints(void) const;
	unsigned int getMaxHitPoints(void) const;
	unsigned int getEnergyPoints(void) const;
	unsigned int getMaxEnergyPoints(void) const;
	unsigned int getLevel(void) const;
	std::string getName(void) const;
	unsigned int getMeleeAttackDamage(void) const;
	unsigned int getRangedAttackDamage(void) const;
	unsigned int getArmorDamageReduction(void) const;
	void displayScavTrap(void) const;
	int setEnergyPoints(unsigned int amount);

private:
	unsigned int _hitPoints;
	unsigned int _maxHitPoints;
	unsigned int _energyPoints;
	unsigned int _maxEnergyPoints;
	unsigned int _level;
	std::string _name;
	unsigned int _meleeAttackDamage;
	unsigned int _rangedAttackDamage;
	unsigned int _armorDamageReduction;

	void _announce(void) const;
};
#endif
