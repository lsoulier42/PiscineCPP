/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:09:47 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/07 12:09:48 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <string>
# include <iostream>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
	MateriaSource();
	MateriaSource(const MateriaSource & src);
	virtual ~MateriaSource();

	MateriaSource & operator=(const MateriaSource & rhs);
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
	AMateria* getMateria(int idx) const;

private:
	AMateria* _materias[MAX_MATERIA];
	void _deepCopy(const MateriaSource & src);
	void _deleteMaterias();
};

#endif
