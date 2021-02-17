/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:05:21 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/03 11:05:25 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include <string>
# include <ctime>
# include "ClapTrap.hpp"
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

class FragTrap : virtual public ClapTrap {
public:
	FragTrap(void);
	FragTrap(std::string const & nameRef);
	FragTrap(FragTrap const & src);
	~FragTrap(void);

	FragTrap & operator=(FragTrap const & rhs);
	int rangedAttack(std::string const & target);
	int meleeAttack(std::string const & target);
	int vaulthunter_dot_exe(std::string const & target);

private:
	void _announce(void) const;
};
#endif
