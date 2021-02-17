/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:06:20 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/12 19:06:29 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>
# include <string>

template<typename P>
void iter(P * array, size_t size, void (*fct)(const P &)) {
    for(size_t i = 0; i < size; i++) {
        (*fct)(array[i]);
    }
}

template<typename T>
void add2(const T & n) {
    static int i = 0;
    std::cout << "tab["<< i++ << "] = " << n + 2 << std::endl;
}

#endif
