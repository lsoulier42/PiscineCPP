/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:01:46 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/29 15:02:06 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP
# include "Weapon.hpp"
# include <iostream>
# include <string>
# include <sstream>

class HumanB {
public:
	HumanB(std::string name);
	~HumanB();

	void attack() const;
	void setWeapon(Weapon &newWeapon);

private:
	std::string _name;
	Weapon *_hisWeapon;
};

#endif
