/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:48:26 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/25 16:49:18 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : _contactId(Contact::_nbContacts++) {
	std::string display[TOTAL_PARAMS] = {"first name", "last name", "nickname",
		"login", "postal address", "email address", "phone number",
		"birthday date", "favourite meal", "underwear color", "darkest secret"};
	for (int i = 0; i < TOTAL_PARAMS; i++)
		this->_param_display[i] = display[i];
}

Contact::~Contact() {
}

std::string	Contact::getParam(int paramId) const {
	return (this->_params[paramId]);
}

std::string Contact::getParamDisplay(int paramId) const {
	return (this->_param_display[paramId]);
}

void		Contact::setParam(int paramId, std::string &value) {
	this->_params[paramId] = value;
}

void		Contact::displayContactInfo() const {
	std::string	param;

	std::cout << "|" << this->_contactId << "         |";
	for (int i = 0; i < 3; i++)
	{
		param = this->getParam(i);
		if (param.size() > 10)
		{
			param.resize(9);
			param.push_back('.');
		}
		else
			param.resize(10, ' ');
		std::cout << param << "|";
	}
	std::cout << std::endl;
}

void 		Contact::displayAllParams() const {
	for(int i = 0; i < TOTAL_PARAMS; i++)
		std::cout << this->_param_display[i] << ": " << this->_params[i] << std::endl;
}

int			Contact::_nbContacts = 0;