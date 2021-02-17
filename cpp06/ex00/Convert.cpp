/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:00:15 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/09 14:00:16 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() {
}

Convert::Convert(std::string const & input) : _isInf(false), _isNan(false), _isNeg(false) {
	if (!this->hasSign(input) && (input[0] < '0' || input[0] > '9')) {
		if (!input[1])
			this->_num = static_cast<double>(input[0]);
		else if (this->isNan(input))
			this->_isNan = true;
		else if (this->isInf(input)) {
			this->_isInf = true;
			this->_isNeg = input[0] == '-';
		}
		else
			throw Convert::InvalidArgumentException();
	}
	else {
		this->_num = std::strtod(input.c_str(), NULL);
	}
}

Convert::Convert(const Convert &src) {
	*this = src;
}

Convert::~Convert() {
}

Convert & Convert::operator=(const Convert &rhs) {
	if (this != &rhs)
		this->_num = rhs.getNum();
	return *this;
}

double Convert::getNum() const {
	return this->_num;
}

void Convert::displayChar() const {
	std::cout << "char: ";
	if (this->_isNan || this->_isInf || this->_num > CHAR_MAX || this->_num < CHAR_MIN)
		std::cout << "Impossible" << std::endl;
	else {
		char c = static_cast<char>(this->_num);
		if (std::isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
}

void Convert::displayInt() const {
	std::cout << "int: ";
	if (this->_isNan || this->_isInf || this->_num > INT_MAX || this->_num < INT_MIN)
		std::cout << "Impossible" << std::endl;
	else {
		int i = static_cast<int>(this->_num);
		std::cout << i << std::endl;
	}
}

void Convert::displayFloat() const {
	std::string sign = this->_isNeg ? "-" : "+";

	std::cout << "float: ";
	if (this->_isNan)
		std::cout << "nanf" << std::endl;
	else if (this->_isInf) {
		std::cout << sign << "inff" << std::endl;
	}
	else {
		float f = static_cast<float>(this->_num);
		std::cout << std::fixed << std::setprecision(2) << f << "f" << std::endl;
	}
}

void Convert::displayDouble() const {
	std::string sign = this->_isNeg ? "-" : "+";

	std::cout << "double: ";
	if (this->_isNan)
		std::cout << "nan" << std::endl;
	else if (this->_isInf) {
		std::cout << sign << "inf" << std::endl;
	}
	else
		std::cout << std::fixed << std::setprecision(2) << this->_num << std::endl;
}

const char * Convert::InvalidArgumentException::what() const throw() {
	return "Invalid argument.\nUsage: ./convert [number or a unique printable char]";
}

bool Convert::hasSign(std::string const & input) const {
	return ((input[0] == '+' || input[0] == '-') && std::isdigit(input[1]));
}

bool Convert::isNan(const std::string &input) const {
	return (input.find("nan") != std::string::npos || input.find("NaN") != std::string::npos);
}

bool Convert::isInf(const std::string &input) const {
	int begin = input[0] == '+' || input[0] == '-' ? 1 : 0;

	return (input.find("inf", begin) != std::string::npos);
}
