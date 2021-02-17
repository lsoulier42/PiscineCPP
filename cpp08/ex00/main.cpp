/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 20:13:20 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/12 20:13:21 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <vector>
#include <iostream>

void test_list() {
	std::list<int> lst1;
	int test1 = 14, test2 = 25;

	lst1.push_back(14);
	lst1.push_back(17);
	lst1.push_back(24);
	lst1.push_back(26);
	lst1.push_back(42);

	std::cout << "Test with a list<int> with: ";
	for(std::list<int>::iterator it = lst1.begin(); it != lst1.end(); it++)
		std::cout << *it << ",";
	std::cout << std::endl;
	try {
		easyFind(lst1, test1);
		std::cout << "element found in container: " << test1 << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << ": " << test1 << std::endl;
	}

	try {
		easyFind(lst1, test2);
		std::cout << "element found in container: " << test2 << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << ": " << test2 << std::endl;
	}
	std::cout << std::endl;
}

void test_vector() {
	std::vector<int> v1(10, 2);
	int test1 = 2, test2 = 42;

	std::cout << "Test with a vector<int> with: ";
	for(std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		std::cout << *it << ",";
	std::cout << std::endl;try {
		easyFind(v1, test1);
		std::cout << "element found in container: " << test1 << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << ": " << test1 << std::endl;
	}

	try {
		easyFind(v1, test2);
		std::cout << "element found in container: " << test2 << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << ": " << test2 << std::endl;
	}
}

int main() {
	test_list();
	test_vector();
	return (0);
}