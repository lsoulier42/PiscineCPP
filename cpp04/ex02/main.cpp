/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 12:27:32 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/05 12:27:33 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int main()
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;

	ISquad* vlc = new Squad;
	Squad *vlc_squad = dynamic_cast<Squad*>(vlc);
	if (!vlc_squad)
		return (0);

	vlc->push(bob);
	vlc->push(jim);

	std::cout << std::endl;
	std::cout << "Let's clone our squad :" << std::endl;
	ISquad* clone_squad = new Squad(*vlc_squad);

	std::cout << std::endl;
	std::cout << "Let's see if the deep copy works (address should be differents) :" << std::endl;
	std::cout << "Addr of first squad first marine : " << vlc->getUnit(0) << std::endl;
	std::cout << "Addr of second squad first marine : " << clone_squad->getUnit(0) << std::endl;

	std::cout << std::endl;
	std::cout << "First squad attacks" << std::endl;
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	std::cout << std::endl;
	std::cout << "Second squad attacks" << std::endl;
	for (int i = 0; i < clone_squad->getCount(); ++i)
	{
		ISpaceMarine* cur = clone_squad->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	std::cout << std::endl;
	std::cout << "Now let's see if everybody dies correctly :" << std::endl;
	delete vlc;
	delete clone_squad;

	return 0;
}
