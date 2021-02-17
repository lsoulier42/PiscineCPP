/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:48:45 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/11 12:48:47 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

Foo::Foo() : _d(0) { }

Foo::Foo(int d) : _d(d) { }

Foo::Foo(const Foo &src) { *this = src; }

int Foo::getD() const {
    return this->_d;
}

Foo & Foo::operator=(const Foo &rhs) {
    if (this != &rhs)
        this->_d = rhs.getD();
    return *this;
}

Foo::~Foo() {
}

bool Foo::operator<=(const Foo &rhs) const {
    return this->_d <= rhs.getD();
}

bool Foo::operator>=(const Foo &rhs) const {
    return this->_d >= rhs.getD();
}

std::ostream & operator<<(std::ostream & o, Foo const & src) {
    o << src.getD();
    return o;
}