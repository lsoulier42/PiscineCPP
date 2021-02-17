/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:59:35 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/09 13:59:36 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::string input(argv[1]);
		try {
			Convert program(input);
			program.displayChar();
			program.displayInt();
			program.displayFloat();
			program.displayDouble();
		}
		catch(Convert::InvalidArgumentException & e) {
			std::cout << e.what() << std::endl;
		}
	}
	else
		std::cout << "Bad number of arguments.\nUsage: ./convert [number or a unique printable char]" << std::endl;
	return (0);
}
