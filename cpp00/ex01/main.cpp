/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:21:31 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/25 17:22:14 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Program.hpp"

bool in_array(std::string &buffer, std::string *array, int size)
{
	for (int i = 0; i < size; i++)
		if (array[i] == buffer)
			return (true);
	return (false);
}

std::string toupper(std::string oldstr)
{
	std::string newstr;

	newstr = oldstr;
	for(int i = 0; i < (int)(oldstr.size()); i++)
		newstr[i] = std::toupper(oldstr[i]);
	return (newstr);
}

int prompt(Program *minishell, Calepin *phonebook)
{
	std::string buffer;
	std::string commands_str[TOTAL_COMMANDS] = {"EXIT",
		"ADD", "SEARCH", "HELP"};
	void (Program::*f[TOTAL_COMMANDS])(Calepin *phonebook) = {&Program::exit,
		&Program::add, &Program::search, &Program::help};

	std::cout << "?> ";
	std::getline(std::cin, buffer);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		return (0);
	}
	buffer = toupper(buffer);
	if (in_array(buffer, commands_str, TOTAL_COMMANDS))
	{
		for (int i = 0; i < TOTAL_COMMANDS; i++)
			if (commands_str[i] == buffer)
				(minishell->*f[i])(phonebook);
	}
	else
		std::cout << "This command doesn't exist." << std::endl;
	return (minishell->getRun());
}

int main()
{
	Program minishell;
	Calepin	phonebook;

	minishell.help(&phonebook);
	while(prompt(&minishell, &phonebook))
		;
	return (0);
}
