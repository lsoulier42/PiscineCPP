/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 21:36:25 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/01 21:36:28 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include <string>
# include <ctime>
# define RANGED_ATTACK_EP 10
# define MELEE_ATTACK_EP 15
# define VAULTHUNTER_DOT_EXE_EP 25
# define VAULTHUNTER_DOT_EXE_DAMAGE 50

typedef enum	e_vaulthunter_attack {
	GUN_WIZARD,
	TORGUE_FIESTA,
	PIRATE_SHIP_MODE,
	ONE_SHOT_WONDER,
	LASER_INFERNO,
	TOTAL_ATTACKS
}				t_vaulthunter_attack;

class FragTrap {
public:
	FragTrap(void);
	FragTrap(std::string const & nameRef);
	FragTrap(FragTrap const & src);
	~FragTrap(void);

	FragTrap & operator=(FragTrap const & rhs);
	int rangedAttack(std::string const & target);
	int meleeAttack(std::string const & target);
	int beRepaired(unsigned int amount);
	int takeDamage(unsigned int amount);
	int vaulthunter_dot_exe(std::string const & target);

	unsigned int getHitPoints(void) const;
	unsigned int getMaxHitPoints(void) const;
	unsigned int getEnergyPoints(void) const;
	unsigned int getMaxEnergyPoints(void) const;
	unsigned int getLevel(void) const;
	std::string getName(void) const;
	unsigned int getMeleeAttackDamage(void) const;
	unsigned int getRangedAttackDamage(void) const;
	unsigned int getArmorDamageReduction(void) const;
	void displayFragTrap(void) const;

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
