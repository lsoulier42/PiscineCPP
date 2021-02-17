/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:49:50 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/10 18:49:51 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
# define C_HPP
# include "Base.hpp"
# include <iostream>

class C : public Base {
public:
	C();
	C(const C & src);
	C & operator=(const C & rhs);
	virtual ~C();
};
#endif
