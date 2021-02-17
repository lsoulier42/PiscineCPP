/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 13:39:43 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/29 13:43:57 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string phrase = "HI THIS IS BRAIN";
	std::string *phrasePtr = &phrase;
	std::string &phraseRef = phrase;

	std::cout << "The aim of this exercice is to display 3 times the same string, with 3 differents ways of calling it" << std::endl;
	std::cout << "The string is : " << phrase << std::endl;
	std::cout << "Calling it with the ptr will result with : " << *phrasePtr << std::endl;
	std::cout << "Then with the reference : " << phraseRef << std::endl;
	return (0);
}


