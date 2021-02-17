/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:18:44 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/03 17:18:46 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Peasant.hpp"

int main()
{
	std::cout << "/////////Standard main :" << std::endl;
	Sorcerer robert("Robert", "the Magnificent");

	Victim jim("Jimmy");
	Peon joe("Joe");

	std::cout << robert << jim << joe;

	robert.polymorph(jim);
	robert.polymorph(joe);

	std::cout << std::endl;
	std::cout << "/////////More objects : " << std::endl;
	Sorcerer john("John", "the Fantastic");
	Peasant arthas("Arthas");
	Peon tim("Tim");
	Peasant james("James");

	std::cout << john << arthas << tim << james;

	john.polymorph(arthas);
	john.polymorph(tim);
	john.polymorph(james);

	std::cout << std::endl;
	std::cout << "/////////Now the destructors : " << std::endl;

	return 0;
}
