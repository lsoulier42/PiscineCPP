/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 13:47:35 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/29 13:47:46 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human() {
}

Human::~Human() {
}

std::string Human::identify() const {
	return (this->_hisBrain.identify());
}

const Brain& Human::getBrain() const {
	return (this->_hisBrain);
}
