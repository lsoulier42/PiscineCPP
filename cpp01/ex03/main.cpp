/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:48:18 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/29 12:48:31 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

int main()
{
	int nb_zombies = 5;
	ZombieHorde walking_deads(nb_zombies);

	std::cout << "Now that " << nb_zombies << " zombies have been created, we call the announce() function :" << std::endl;
	walking_deads.announce();
	std::cout << "Since the horde have been created on stack, they'll be destroyed when the function ends,";
	std::cout << "which will call the destructor of the horde, who call delete [] for the zombies array." << std::endl;
	return (0);
}
