/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:20:07 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/29 10:20:24 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main()
{
	ZombieEvent exercice02;
	Zombie* heapZombie;

	exercice02.setZombieType("dead zombies");
	std::cout << "Let's create a Zombie on the stack with randomChump() :" << std::endl;
	exercice02.randomChump();
	std::cout << "This Zombie was on the stack, so it was deleted at the end of randomChump()." <<std::endl;
	std::cout << "Now we'll create a Zombie on the heap with newZombie() :" << std::endl;
	heapZombie = exercice02.newZombie("Salameche");
	std::cout << "We have to delete it manually so there's no memory leaks." << std::endl;
	delete heapZombie;
	return (0);
}