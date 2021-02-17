/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:56:30 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/04 16:56:31 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP
# include <string>
# include <iostream>
# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
public:
	PlasmaRifle(void);
	PlasmaRifle(PlasmaRifle const & src);
	virtual ~PlasmaRifle(void);

	PlasmaRifle & operator=(PlasmaRifle const & rhs);
	void attack(void) const;
};

#endif
