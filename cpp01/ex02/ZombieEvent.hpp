/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:19:36 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/29 10:19:40 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP
# include "Zombie.hpp"
# include <string>
# include <iostream>
# include <ctime>

class ZombieEvent {
public:
	ZombieEvent();
	~ZombieEvent();

	Zombie* newZombie(std::string name) const;
	void setZombieType(std::string value);
	void randomChump() const;

private:
	std::string _type;

	std::string _getRandomName() const;
};

#endif
