/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:10:31 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/07 12:10:31 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

void print_inventory_char(ICharacter* src)
{
	Character* char_cast = dynamic_cast<Character*>(src);
	for (int i = 0; i < MAX_MATERIA; i++) {
		std::cout << "slot "<< i << ": ";
		if (char_cast->getMateria(i)) {
			std::cout << char_cast->getMateria(i)->getType();
			std::cout << " - exp: " << char_cast->getMateria(i)->getXP() << std::endl;
		}
		else
			std::cout << "null" << std::endl;
	}
}

void print_inventory_ms(IMateriaSource* src)
{
	MateriaSource* ms_cast = dynamic_cast<MateriaSource*>(src);
	for (int i = 0; i < MAX_MATERIA; i++) {
		std::cout << "slot "<< i << ": ";
		if (ms_cast->getMateria(i))
			std::cout << ms_cast->getMateria(i)->getType() << std::endl;
		else
			std::cout << "null" << std::endl;
	}
}

int main()
{
	std::cout << "Let's create a Materia source : " << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	std::cout << "The materia source is supposed to have learned Ice (twice) and Cure, let's see its content:" << std::endl;
	print_inventory_ms(src);

	std::cout << std::endl;
	std::cout << "Now let's create a new character named `me' : " << std::endl;
	ICharacter* me = new Character("me");
	std::cout << "It's inventory contains at creation : " << std::endl;
	print_inventory_char(me);

	std::cout << std::endl;
	std::cout << "Now let's equip the former learned Materias :" << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << "And see what the character has in its inventory :" << std::endl;
	print_inventory_char(me);

	std::cout << std::endl;
	std::cout << "Now let's create a second character, which name is : ";
	ICharacter* bob = new Character("bob");
	std::cout << bob->getName() << std::endl;
	std::cout << "His inventory contains : " << std::endl;
	print_inventory_char(bob);

	std::cout << std::endl;
	std::cout << "Now let's use the materias on bob :" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;
	std::cout << "Now let's unequip the slot 1 of `me' character and see its inventory: " << std::endl;
	me->unequip(1);
	delete tmp; // since unequip must not delete the Materia
	print_inventory_char(me);

	std::cout << std::endl;
	std::cout << "Let's create a copy of the materia source" << std::endl;
	MateriaSource* src_cast = dynamic_cast<MateriaSource*>(src);
	IMateriaSource* src_copy = new MateriaSource(*src_cast);
	std::cout << "What does the copy contains : " << std::endl;
	print_inventory_ms(src_copy);

	std::cout << std::endl;
	std::cout << "And equip only ice: " << std::endl;
	tmp = src_copy->createMateria("ice");
	me->equip(tmp);
	tmp = src_copy->createMateria("ice");
	me->equip(tmp);
	tmp = src_copy->createMateria("ice");
	me->equip(tmp);
	tmp = src_copy->createMateria("ice"); //this one should do nothing since the inventory is full
	me->equip(tmp);
	delete(tmp); // since the Materia is not equiped and won't be deleted by the copy destructor
	print_inventory_char(me);

	std::cout << std::endl;
	std::cout << "And use the ice again on bob : " << std::endl;
	me->use(4, *bob); // this line should do nothing, 4 is not a valid index
	me->use(0, *bob);
	me->use(2, *bob);
	std::cout << std::endl;
	std::cout << "Now let's see if the materias have gained some exp : " << std::endl;
	print_inventory_char(me);

	delete bob;
	delete me;
	delete src;
	delete src_copy;

	return 0;
}
