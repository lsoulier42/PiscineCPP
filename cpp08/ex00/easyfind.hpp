/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 20:13:14 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/12 20:13:15 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <stdexcept>
# include <algorithm>

class ElementNotFound : public std::exception {
public:
	virtual const char* what() const throw() {
		return "element not found in container";
	}
};

template<typename T>
typename T::const_iterator easyFind(T const & container, int d) {
	typename T::const_iterator it;

	it = std::find(container.begin(), container.end(), d);
	if (it == container.end())
		throw ElementNotFound();
	return it;
}

#endif
