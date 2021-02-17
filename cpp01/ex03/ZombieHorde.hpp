/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:31:30 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/29 12:31:48 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HORDE_HPP
# define ZOMBIE_HORDE_HPP
# include "Zombie.hpp"
# include <ctime>

class ZombieHorde {
public:
	ZombieHorde(int N);
	~ZombieHorde();

	void announce() const;
private:
	int _nb_zombies;
	Zombie* _zombies;
	std::string getRandomName() const;
};
#endif
