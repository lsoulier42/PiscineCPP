/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:38:47 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/01 16:39:02 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {
private:
	int _value;

	static const int _nb_fractional_bits;

public :
	Fixed( void );
	~Fixed( void );
	Fixed( Fixed const & src );

	Fixed & operator=( Fixed const & rhs );
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif
