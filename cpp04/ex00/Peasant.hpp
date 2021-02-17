/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peasant.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:49:59 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/04 11:50:02 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEASANT_HPP
# define PEASANT_HPP
# include <iostream>
# include <string>
# include "Victim.hpp"

class Peasant : public Victim {
public:
	Peasant();
	Peasant(std::string const & nameRef);
	Peasant(Peasant const & src);
	virtual ~Peasant(void);

	Peasant & operator=(Peasant const & rhs);
	void getPolymorphed(void) const;

private:
	void _announce(void) const;
};
#endif
