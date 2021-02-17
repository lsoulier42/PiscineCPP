/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:00:22 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/09 14:00:23 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP
# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>
# include <climits>

class Convert {
public:
	Convert(std::string const & input);
	Convert(Convert const & src);
	~Convert();

	Convert & operator=(Convert const & rhs);
	void displayChar() const;
	void displayInt() const;
	void displayFloat() const;
	void displayDouble() const;
	double getNum() const;
	bool hasSign(std::string const & input) const;
	bool isInf(std::string const & input) const;
	bool isNan(std::string const & input) const;

	class InvalidArgumentException : std::exception {
	public:
		virtual const char* what() const throw();
	};

private:
	Convert();
	double _num;
	bool _isInf;
	bool _isNan;
	bool _isNeg;
};

#endif
