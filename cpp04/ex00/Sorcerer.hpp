/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:17:46 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/03 17:17:48 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP
# include <iostream>
# include <string>
# include "Victim.hpp"

class Sorcerer {
public:
	Sorcerer(std::string const & nameRef, std::string const & titleRef);
	Sorcerer(Sorcerer const & src);
	~Sorcerer();

	Sorcerer & operator=(Sorcerer const & rhs);
	std::string const & getName(void) const;
	std::string const & getTitle(void) const;
	void polymorph(Victim const & src) const;

private:
	std::string _name;
	std::string _title;

	void _announce(void) const;
};

std::ostream & operator<<(std::ostream & o, Sorcerer & src);
#endif
