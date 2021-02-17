/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:09:02 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/07 12:09:03 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria {
public:
	Ice();
	Ice(const Ice & src);
	virtual ~Ice();

	Ice & operator=(const Ice & rhs);
	Ice* clone() const;
	void use(ICharacter& target);
};

#endif
