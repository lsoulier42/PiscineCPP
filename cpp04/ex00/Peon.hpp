/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:18:18 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/03 17:18:19 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP
# include <iostream>
# include <string>
# include "Victim.hpp"

class Peon : public Victim {
public:
	Peon();
	Peon(std::string const & nameRef);
	Peon(Peon const & src);
	virtual ~Peon(void);

	Peon & operator=(Peon const & rhs);
	void getPolymorphed(void) const;

private:
	void _announce(void) const;
};

#endif
