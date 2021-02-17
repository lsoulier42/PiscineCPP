/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:00:10 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/29 15:01:04 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP
# include "Weapon.hpp"
# include <string>
# include <iostream>

class HumanA {
public:
	HumanA(std::string name, Weapon &hisWeapon);
	~HumanA();

	void attack() const;

private:
	std::string _name;
	Weapon& _hisWeapon;
};

#endif
