/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 13:47:08 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/29 13:47:28 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>
# include <sstream>

typedef enum	e_characteristics {
	HAS_CORTEX,
	HAS_THALAMUS,
	HAS_AMYGDAL,
	HAS_HIPPOCAMPUS,
	HAS_CEREBELLUM,
	HAS_SPINAL_CHORD,
	TOTAL_CHARACTERISTICS
}				t_characteristics;

class Brain {
public:
	Brain();
	~Brain();

	std::string	identify() const;

private:
	std::string _ownerName;
	bool 		_characteristics[TOTAL_CHARACTERISTICS];
};
#endif
