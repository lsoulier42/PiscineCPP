/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:08:39 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/03 11:08:41 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP
# include <iostream>
# include <ctime>
# include <string>
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"
# define RANGED_ATTACK_EP 10
# define MELEE_ATTACK_EP 15

class SuperTrap : public FragTrap, public NinjaTrap {
public:
	SuperTrap(void);
	SuperTrap(std::string const & nameRef);
	SuperTrap(SuperTrap const & src);
	~SuperTrap(void);

	int rangedAttack(std::string const & target);
	int meleeAttack(std::string const & target);

	SuperTrap & operator=(SuperTrap const & rhs);
private:
	void _announce(void) const;
};
#endif
