/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:58:12 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/04 16:58:13 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP
# include <string>
# include <iostream>
class Enemy {
public:
	Enemy();
	Enemy(int hp, std::string const & type);
	Enemy(Enemy const & src);
	virtual ~Enemy(void);

	Enemy & operator=(Enemy const & rhs);
	std::string const & getType(void) const;
	int getHP(void) const;
	virtual void takeDamage(int);

protected:
	int _hp;
	std::string _type;
};
#endif
