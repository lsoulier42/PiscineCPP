/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:57:52 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/04 16:57:53 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP
# include <iostream>
# include <string>
# include "AWeapon.hpp"

class PowerFist : public AWeapon {
public:
	PowerFist(void);
	PowerFist(PowerFist const & src);
	virtual ~PowerFist(void);

	PowerFist & operator=(PowerFist const & rhs);
	void attack(void) const;
};

#endif
