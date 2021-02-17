/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:59:29 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/04 16:59:30 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "PowerFist.hpp"
#include "PlasmaRifle.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

int main()
{
	Character* me = new Character("me");

	std::cout << "Let's create a new `me' character : " << std::endl;
	std::cout << *me;

	std::cout << std::endl;
	std::cout << "Let's create 3 enemies, the third one is the copy of the first one : " << std::endl;
	Enemy* b = new RadScorpion();
	Enemy* c = new SuperMutant();
	RadScorpion* b_cast = dynamic_cast<RadScorpion*>(b);
	Enemy* b_copy = new RadScorpion(*b_cast);

	std::cout << std::endl;
	std::cout << "Let's create 3 weapons (there should be no output), the third one is the copy of the Plasma Riffle : " << std::endl;
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	PlasmaRifle* pr_cast = dynamic_cast<PlasmaRifle*>(pr);
	AWeapon* pr_copy = new PlasmaRifle(*pr_cast);

	std::cout << std::endl;
	std::cout << "Let's equip the powerfist and see `me' status : " << std::endl;
	me->equip(pf);
	std::cout << *me;

	std::cout << std::endl;
	std::cout << "We can attack the RadScorpion with the weapon and see the `me' status again : " << std::endl;
	me->attack(b);
	std::cout << *me;
	std::cout << std::endl;
	std::cout << "We can change the weapon to Plasma riffle : " << std::endl;
	me->equip(pr);
	std::cout << *me;
	std::cout << std::endl;
	std::cout << "Then attack the RadScorpion again : " << std::endl;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	std::cout << "At this point, the first RadScorpion should be dead (and so it has been deleted by the attack), but the copy should be alive" << std::endl;

	std::cout << std::endl;
	std::cout << "Let's try recover AP method: " << std::endl;
	me->recoverAP();
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;

	std::cout << std::endl;
	std::cout << "Let's equip the copy of the plasma riffle :" << std::endl;
	me->equip(pr_copy);
	std::cout << *me;
	std::cout << "Then attack the copy of the RadScorpion :" << std::endl;
	me->attack(b_copy);
	std::cout << *me;

	std::cout << std::endl;
	std::cout << "We can also attack the SuperMutant :" << std::endl;
	me->attack(c);
	std::cout << *me;
	me->attack(c);
	std::cout << *me;

	std::cout << std::endl;
	std::cout << "Now we have to clear the battle field :" << std::endl;
	delete me;
	delete c;
	delete pr;
	delete pf;
	delete b_copy;
	delete pr_copy;

	return 0;
}
