/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 14:40:49 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/10 14:40:52 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP
# include <string>
# include <iostream>
# include <ctime>
# include <cstdlib>
# define STR_SIZE 8

struct	Data {
	std::string	s1;
	int			randomInt;
	std::string	s2;
};

void*	serialize(void);
Data* 	deserialize(void * raw);
#endif
