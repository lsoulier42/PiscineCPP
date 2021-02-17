/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:34:49 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/25 15:35:05 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <locale>
#include <string>

int main(int argc, char **argv)
{
	int			i;
	int			j;
	std::locale	loc;

	i = 0;
	if (argc >= 2)
	{
		while (++i < argc)
		{
			j = -1;
			while (argv[i][++j])
				std::cout << std::toupper(argv[i][j], loc);
		}

		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
