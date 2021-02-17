/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:29:55 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/29 12:30:00 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

class Zombie {
public:
	Zombie();
	Zombie(std::string name, std::string type);
	~Zombie();

	void announce() const;
	std::string getName() const;
	void setName(std::string value);
	std::string getType() const;
	void setType(std::string value);

private:
	std::string _name;
	std::string _type;
};
#endif
