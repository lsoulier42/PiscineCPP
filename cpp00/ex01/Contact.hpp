/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:49:42 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/25 16:49:45 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>

typedef enum	e_params
{
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	LOGIN,
	POSTAL_ADDRESS,
	EMAIL_ADDRESS,
	PHONE_NUMBER,
	BIRTHDAY_DATE,
	FAVORITE_MEAL,
	UNDERWEAR_COLOR,
	DARKEST_SECRET,
	TOTAL_PARAMS
}				t_params;

class Contact {
public:
	Contact();
	~Contact();

	std::string	getParam(int paramId) const;
	void		setParam(int paramId, std::string &value);
	void 		displayContactInfo() const;
	std::string	getParamDisplay(int paramId) const;
	void 		displayAllParams() const;

private:
	int			_contactId;
	std::string _params[TOTAL_PARAMS];
	std::string _param_display[TOTAL_PARAMS];

	static int	_nbContacts;
};
#endif
