/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:56:45 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/10 18:56:46 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <ctime>
# include <cstdlib>
# include <iostream>
# include <stdexcept>

Base* generate(void);
Base* makeA(void);
Base* makeB(void);
Base* makeC(void);
void identify_from_pointer(Base * p);
void identify_from_reference(Base & ref);
#endif
