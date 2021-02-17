/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:08:39 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/07 12:08:41 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>
# include "ICharacter.hpp"
# define MAX_MATERIA 4

class ICharacter;

class AMateria {
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria & src);
	virtual ~AMateria();

	AMateria & operator=(const AMateria & rhs);
	std::string const & getType() const;
	unsigned int getXP() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

protected:
	unsigned int _xp;
	std::string _type;
};

#endif
