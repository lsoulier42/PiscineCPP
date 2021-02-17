/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:57:50 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/01 17:57:52 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed {
private:
	int _value;

	static const int _nb_fractional_bits;

public :
	Fixed( void );
	~Fixed( void );
	Fixed( Fixed const & src );
	Fixed ( int n );
	Fixed ( float f );

	Fixed & operator=( Fixed const & rhs );
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & src);

#endif
