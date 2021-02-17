/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 23:09:10 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/02 23:09:12 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include <ctime>
# include <string>
# include "ClapTrap.hpp"
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

class ScavTrap : public ClapTrap {
public:
	ScavTrap(void);
	ScavTrap(std::string const & nameRef);
	ScavTrap(ScavTrap const & src);
	~ScavTrap(void);

	ScavTrap & operator=(ScavTrap const & rhs);
	int rangedAttack(std::string const & target);
	int meleeAttack(std::string const & target);
	int challengeNewcomer(std::string const & target);

private:
	void _announce(void) const;
};
#endif
