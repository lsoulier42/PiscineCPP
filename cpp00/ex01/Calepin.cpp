/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Calepin.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:09:13 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/26 12:09:24 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Calepin.hpp"

Calepin::Calepin() {
	std::cout << "A new Phonebook has been created." << std::endl;
}

Calepin::~Calepin() {
	std::cout << "The Phonebook has been deleted." << std::endl;
}

Contact*	Calepin::getContact(int contactId) {
	return (this->_contacts + contactId);
}

void Calepin::displayAllContacts() const {
	Contact current;

	std::cout << "|id        ";
	std::cout << "|first name";
	std::cout << "|last name ";
	std::cout << "|nickname  |" << std::endl;
	for(int i = 0; i < MAX_CONTACTS; i++)
		if (!(this->_contacts[i].getParam(0).empty()))
			this->_contacts[i].displayContactInfo();
}

void Calepin::displayContact(int contactId) const {
	this->_contacts[contactId].displayAllParams();
}
