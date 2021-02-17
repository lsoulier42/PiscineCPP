/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:30:56 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/28 16:40:27 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void memoryLeak()
{
	std::string* panther = new std::string("String panther");
	std::cout << *panther << std::endl;
	delete panther;
}

int main()
{
	std::string buffer;

	memoryLeak();
	std::cout << "New open a new terminal and type `leaks a.out'";
	std::cout << " to see if memory leaks are still there." << std::endl;
	std::cout << "Press <return> to finish the program." << std::endl;
	std::getline(std::cin, buffer);
	return (0);
}

