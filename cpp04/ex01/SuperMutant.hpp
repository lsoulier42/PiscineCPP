/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:58:27 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/04 16:58:28 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP
# include <iostream>
# include <string>
# include "Enemy.hpp"

class SuperMutant : public Enemy {
public:
	SuperMutant(void);
	SuperMutant(SuperMutant const & src);
	virtual ~SuperMutant(void);

	SuperMutant & operator=(SuperMutant const & rhs);
	void takeDamage(int);

private:
	void _announce(void) const;
};
#endif