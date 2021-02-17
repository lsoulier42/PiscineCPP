/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Program.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:21:46 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/26 14:21:54 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Program.hpp"

Program::Program() : _run(1), _nbContacts(0) {
}

Program::~Program() {
}

void Program::exit(Calepin *phonebook) {
	(void)phonebook;
	this->_run = 0;
}

void Program::add(Calepin *phonebook) {
	std::string	value;
	Contact *current;
	int		mandatory = 0;

	if (this->_nbContacts == MAX_CONTACTS)
	{
		std::cout << "The max contacts limit has been reached, ";
		std::cout << "you cannot add a new contact." << std::endl;
	}
	else
	{
		current = phonebook->getContact(_nbContacts);
		for (int i = 0; i < TOTAL_PARAMS; i++)
		{
			value.clear();
			mandatory = i < 3;
			while(!(std::cin.eof()))
			{
				std::cout << "What is the " << current->getParamDisplay(i) << " ? ";
				std::getline(std::cin, value);
				if (value.empty() && mandatory)
					std::cout << "This field cannot be empty." << std::endl;
				else
					break;
			}
			if (std::cin.eof())
			{
				std::cout << std::endl;
				break;
			}
			current->setParam(i, value);
		}
		this->_nbContacts++;
	}
}

void Program::search(Calepin *phonebook) {
	(void)phonebook;
	std::string input;
	int id;
	Contact *current;

	phonebook->displayAllContacts();
	do {
		input.clear();
		id = -1;
		std::cout << "Please type the id of the contact you want to see: ";
		std::getline(std::cin, input);
		if (!input.empty() && this->isNumber(input))
		{
			id = std::atoi(input.c_str());
			if (id >= 0 && id < MAX_CONTACTS)
			{
				current = phonebook->getContact(id);
				if (!(current->getParam(0).empty()))
				{
					phonebook->displayContact(id);
					break;
				}
			}
		}
		std::cout << "This id doesn't exist in the phonebook." << std::endl;
	} while (input.empty() && !(std::cin.eof()) && id == -1);
}

void Program::help(Calepin *phonebook) {
	(void)phonebook;
	std::cout << "Please, type one of the following command : " << std::endl;
	std::cout << "- 'EXIT' : quits the program and all contacts will be lost forever." << std::endl;
	std::cout << "- 'ADD' : will display the form to enter a new contact info." << std::endl;
	std::cout << "- 'SEARCH' : will display every contacts mandatory info ";
	std::cout << "then will ask for id to get the optional ones."  << std::endl;
	std::cout << "- 'HELP' : will display this message agin." << std::endl;
	std::cout << "Note : there cannot be more than 8 contacts in the Phonebook." << std::endl;
}

int Program::getRun() const{
	return (this->_run);
}

bool Program::isNumber(const std::string &str) const {
	for(size_t i = 0; i < str.size(); i++)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}
