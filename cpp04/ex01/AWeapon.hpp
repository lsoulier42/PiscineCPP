/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:53:25 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/04 16:53:26 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP
# include <iostream>
# include <string>

class AWeapon {
public:
	AWeapon();
	AWeapon(std::string const & name, int apcost, int damage);
	AWeapon(AWeapon const & src);
	virtual ~AWeapon(void);

	AWeapon & operator=(AWeapon const & rhs);
	std::string const & getName() const;
	int getAPCost(void) const;
	int getDamage(void) const;
	virtual void attack(void) const = 0;

protected:
	std::string _name;
	int _apcost;
	int _damage;
};
#endif
