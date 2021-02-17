/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:49:30 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/10 18:49:31 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
# define A_HPP
# include "Base.hpp"
# include <iostream>

class A : public Base {
public:
	A();
	A(const A & src);
	A & operator=(const A & rhs);
	virtual ~A();
};
#endif
