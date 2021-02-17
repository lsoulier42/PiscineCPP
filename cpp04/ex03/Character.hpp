/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:09:30 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/07 12:09:31 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <string>
# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter {
public:
	Character();
	Character(std::string const & name);
	Character(const Character & src);
	virtual ~Character();

	Character & operator=(const Character & rhs);
	std::string const & getName() const;
	AMateria* getMateria(int idx) const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

private:
	std::string _name;
	AMateria* _materias[MAX_MATERIA];
	void _deepCopy(const Character & src);
	void _deleteMaterias();
};
#endif
