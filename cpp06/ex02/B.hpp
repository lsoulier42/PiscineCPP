/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:49:39 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/10 18:49:40 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
# define B_HPP
# include "Base.hpp"
# include <iostream>

class B : public Base {
public:
	B();
	B(const B & src);
	B & operator=(const B & rhs);
	virtual ~B();
};
#endif
