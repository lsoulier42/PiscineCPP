/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 23:38:19 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/12 23:38:20 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0) {
}

Span::Span(unsigned int n) : _n(n) {
}

Span::Span(const Span &src) {
	*this = src;
}

Span & Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		this->_n = rhs._n;
		this->_numbers = rhs._numbers;
	}
	return *this;
}

Span::~Span() {
}

void Span::addNumber(int d) {
	if(this->_numbers.size() == this->_n)
		throw SpanFullException();
	this->_numbers.push_back(d);
}

void Span::addNumber(int min, int max) {
	if (max > min) {
		if ((this->_n - this->_numbers.size()) < static_cast<unsigned long>(max - min))
			throw SpanFullException();
		for (int i = min; i <= max; i++)
			this->_numbers.push_back(i);
	}
}

int Span::shortestSpan() {
	if (this->_numbers.size() <= 1)
		throw NoSpanToFindException();
	std::sort(this->_numbers.begin(), this->_numbers.end());
	int shortest = INT_MAX;
	for(std::vector<int>::iterator it = this->_numbers.begin(); it != this->_numbers.end(); it++)
		if ((it + 1) != this->_numbers.end() && shortest > *(it + 1) - *it)
			shortest = *(it + 1) - *it;
	return shortest;
}

int Span::longestSpan() {
	if (this->_numbers.size() <= 1)
		throw NoSpanToFindException();
	std::sort(this->_numbers.begin(), this->_numbers.end());
	return *(this->_numbers.end() - 1) - *(this->_numbers.begin());
}

const char* Span::SpanFullException::what() const throw() {
	return "this object is already full";
}

const char* Span::NoSpanToFindException::what() const throw() {
	return "not enough numbers in this object to find a span";
}

void Span::display_span() {
	std::cout << "This class contains the following ints: ";
	for(std::vector<int>::iterator it = this->_numbers.begin(); it != this->_numbers.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;
}
