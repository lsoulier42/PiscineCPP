/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:57:44 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/01 17:57:45 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_nb_fractional_bits = 8;

Fixed::Fixed( void ) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed & src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed( int n ) : _value(n << Fixed::_nb_fractional_bits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed ( float f ) : _value(roundf(f * (1 << Fixed::_nb_fractional_bits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed & Fixed::operator=( const Fixed & rhs ) {
	std::cout << "Assignation operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const {
	return (this->_value);
}

void Fixed::setRawBits( const int raw ) {
	this->_value = raw;
}

int Fixed::toInt( void ) const {
	return (int)(this->_value >> Fixed::_nb_fractional_bits);
}

float Fixed::toFloat ( void ) const {
	return (float)this->_value / (float)(1 << Fixed::_nb_fractional_bits);
}

std::ostream & operator<<( std::ostream & o, Fixed const & src ) {
	o << src.toFloat();
	return o;
}
