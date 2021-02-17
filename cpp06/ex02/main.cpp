/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:50:08 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/10 18:50:08 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>

int main() {
	Base* random = generate();

	std::cout << std::endl;
	identify_from_pointer(random);
	identify_from_reference(*random);
	delete random;
	return 0;
}