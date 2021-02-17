/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:58:48 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/04 16:58:49 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP
# include <iostream>
# include <string>
# include "Enemy.hpp"

class RadScorpion : public Enemy {
public:
	RadScorpion(void);
	RadScorpion(RadScorpion const & src);
	virtual ~RadScorpion(void);

	RadScorpion & operator= (RadScorpion const & rhs);

private:
	void _announce(void) const;
};
#endif
