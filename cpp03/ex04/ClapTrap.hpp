/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:05:03 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/03 11:05:04 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string>
# include <ctime>

class ClapTrap {
public:
	ClapTrap(void);
	ClapTrap(unsigned int hitPoints, unsigned int maxHitPoints, unsigned int energyPoints, unsigned int maxEnergyPoints,
		  unsigned int level, std::string name, unsigned int meleeAttackDamage, unsigned int rangedAttackDamage,
		  unsigned int armorDamageReduction);
	ClapTrap(ClapTrap const & src);
	~ClapTrap(void);

	ClapTrap & operator=(ClapTrap const & rhs);
	int beRepaired(unsigned int amount);
	int takeDamage(unsigned int amount);

	unsigned int getHitPoints(void) const;
	unsigned int getMaxHitPoints(void) const;
	unsigned int getEnergyPoints(void) const;
	unsigned int getMaxEnergyPoints(void) const;
	unsigned int getLevel(void) const;
	std::string getName(void) const;
	unsigned int getMeleeAttackDamage(void) const;
	unsigned int getRangedAttackDamage(void) const;
	unsigned int getArmorDamageReduction(void) const;
	void displayClapTrap(void) const;
	int setEnergyPoints(unsigned int amount);

protected:
	unsigned int _hitPoints;
	unsigned int _maxHitPoints;
	unsigned int _energyPoints;
	unsigned int _maxEnergyPoints;
	unsigned int _level;
	std::string _name;
	unsigned int _meleeAttackDamage;
	unsigned int _rangedAttackDamage;
	unsigned int _armorDamageReduction;

private:
	void _announce(void) const;
};
#endif
