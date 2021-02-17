/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:04:54 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/28 15:05:04 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void ponyOnTheHeap() {
	int chars[TOTAL_CHARACTERISTICS] = {1, 1, 1, 1, 0, 1, 1};
	Pony* lily = new Pony("Lily", "white", "rainbow", "straight-horned", "European",
		145, 128, chars);

	lily->displayPony();
	lily->jump();
	lily->kick();
	lily->poop();
	delete lily;
}

void ponyOnTheStack() {
	int chars[TOTAL_CHARACTERISTICS] = {0, 0, 0, 0, 1, 0, 0};
	Pony buttercup = Pony("Buttercup", "brown", "black", "falabella", "Asian",
		98, 85, chars);

	buttercup.displayPony();
	buttercup.eat();
	buttercup.race();
	buttercup.whinny();
}

int main()
{
	ponyOnTheHeap();
	std::cout << std::endl;
	ponyOnTheStack();
	return (0);
}