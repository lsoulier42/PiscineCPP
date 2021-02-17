/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Calepin.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:09:31 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/26 12:09:51 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALEPIN_HPP
# define CALEPIN_HPP
# define MAX_CONTACTS 8
# include "Contact.hpp"
# include <iostream>
# include <string>

class	Calepin {
public:
	Calepin(void);
	~Calepin(void);

	Contact	*getContact(int contactId);
	void 	displayAllContacts(void) const;
	void 	displayContact(int contactId) const;
private:
	Contact	_contacts[MAX_CONTACTS];
};
#endif
