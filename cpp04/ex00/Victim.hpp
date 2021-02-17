/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:18:01 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/03 17:18:03 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP
# include <iostream>
# include <string>

class Victim {
public:
	Victim();
	Victim(std::string const & nameRef);
	Victim(Victim const & src);
	virtual ~Victim(void);

	Victim & operator=(Victim const & rhs);
	std::string const & getName(void) const;
	virtual void getPolymorphed(void) const;

protected:
	std::string _name;

private:
	void _announce(void) const;
};

std::ostream & operator<<(std::ostream & o, Victim & src);

#endif
