/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:44:25 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/10 18:44:27 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base() {
}

Base::Base(const Base &src) {
	*this = src;
}

Base::~Base() {
}

Base & Base::operator=(const Base &rhs) {
	(void)rhs;
	return *this;
}
