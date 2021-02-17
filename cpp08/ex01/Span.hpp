/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 23:38:26 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/12 23:38:27 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <stdexcept>
# include <algorithm>
# include <vector>
# include <limits.h>
# include <iostream>

class Span {
public:
	Span(unsigned int n);
	Span(const Span & src);
	Span & operator=(const Span & rhs);
	virtual ~Span();

	void addNumber(int d);
	void addNumber(int min, int max);
	int shortestSpan();
	int longestSpan();
	void display_span();

	class SpanFullException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class NoSpanToFindException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:
	Span();
	unsigned int _n;
	std::vector<int> _numbers;
};
#endif
