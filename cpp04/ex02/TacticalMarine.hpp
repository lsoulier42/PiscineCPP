/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 12:26:07 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/05 12:26:08 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP
# include "ISpaceMarine.hpp"
# include <iostream>

class TacticalMarine : public ISpaceMarine {
public:
	TacticalMarine();
	TacticalMarine(const TacticalMarine & src);
	virtual ~TacticalMarine();

	TacticalMarine & operator=(const TacticalMarine & rhs);
	TacticalMarine* clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;

private:
	void _announce() const;
};
#endif
