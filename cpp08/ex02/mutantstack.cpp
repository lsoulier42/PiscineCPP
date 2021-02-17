/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 19:15:04 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/14 19:15:05 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

template<typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack<T> & rhs) {
	if (this != &rhs)
		this->c = rhs.c;
	return *this;
}