/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:59:10 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/04 16:59:11 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include <string>
# include "AWeapon.hpp"
# include "Enemy.hpp"
# define MAX_AP 40
# define RECOVER_AP 10

class Character {
public:
	Character();
	Character(std::string const & name);
	Character(Character const & src);
	~Character(void);

	Character & operator=(Character const & rhs);
	void recoverAP(void);
	void equip(AWeapon*);
	void attack(Enemy*);

	std::string const & getName(void) const;
	int getAP(void) const;
	AWeapon* getWeapon(void) const;

private:
	std::string _name;
	int _ap;
	AWeapon *_weapon;
};

std::ostream & operator<<(std::ostream & o, Character & src);

#endif
