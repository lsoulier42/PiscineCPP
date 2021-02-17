/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 23:10:04 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/02 23:10:06 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP
# include <iostream>
# include <string>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# define RANGED_ATTACK_EP 10
# define MELEE_ATTACK_EP 15
# define NINJA_SHOEBOX_EP 25
# define NINJA_SHOEBOX_DAMAGE 100

class NinjaTrap : public ClapTrap {
public:
	NinjaTrap(void);
	NinjaTrap(std::string const & nameRef);
	NinjaTrap(NinjaTrap const & src);
	~NinjaTrap(void);

	NinjaTrap & operator=(NinjaTrap const & rhs);
	int rangedAttack(std::string const & target);
	int meleeAttack(std::string const & target);
	int ninjaShoebox(ClapTrap & target);
	int ninjaShoebox(FragTrap & target);
	int ninjaShoebox(ScavTrap & target);
	int ninjaShoebox(NinjaTrap & target);

private:
	void _announce(void);
};

#endif
