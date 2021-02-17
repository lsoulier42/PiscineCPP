/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 14:57:43 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/29 14:59:41 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon {
public:
	Weapon(std::string type);
	~Weapon();

	std::string const & getType() const;
	void setType(std::string type);

private:
	std::string _type;
};
#endif
