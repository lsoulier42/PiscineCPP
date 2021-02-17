/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 12:25:46 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/05 12:25:47 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP
# include "ISquad.hpp"
# include "ISpaceMarine.hpp"
# include <iostream>

typedef struct	s_list {
	ISpaceMarine	*marine;
	struct s_list	*next;
}				t_list;

class Squad : public ISquad {
public :
	Squad();
	Squad(Squad const & src);
	virtual ~Squad();

	Squad & operator=(Squad const & rhs);
	int getCount() const;
	ISpaceMarine* getUnit(int) const;
	int push(ISpaceMarine*);

private:
	t_list*	_beginMarines;
	t_list*	_engageMarine(ISpaceMarine*);
	void	_deepCopy(const Squad &src);
	void	_deleteMarines(void);
};

#endif