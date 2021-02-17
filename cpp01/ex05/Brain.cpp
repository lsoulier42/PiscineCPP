/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 13:46:58 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/29 13:47:04 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : _ownerName("") {
	for(int i = 0; i < TOTAL_CHARACTERISTICS; i++)
		this->_characteristics[i] = true;
}

Brain::~Brain() {
}

std::string Brain::identify() const {
	std::stringstream ss;
	ss << this;
	return (ss.str());
}
