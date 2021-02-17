/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:09:14 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/07 12:09:15 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include <string>
# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure: public AMateria {
public:
	Cure();
	Cure(const Cure & src);
	virtual ~Cure();

	Cure & operator=(const Cure & rhs);
	Cure* clone() const;
	void use(ICharacter & target);
};

#endif
