/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:29:51 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/11 15:29:53 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void test_int(void) {
    //test avec int
    int size = 10;
    int value= 0;
    Array<int> test_array(size);

    std::cout << "/!\\ test for int /!\\" << std::endl;
    for (int i = 0; i < size; i++) {
        test_array[i] = value++; // test operateur []
        std::cout << "test_array[" << i << "] = " << test_array[i] << std::endl;
    }

    //test size
    std::cout << "The current size of the array is: " << test_array.size() << std::endl;

    //test out of limit
    std::cout << std::endl << "/!\\ test exception : element 56 /!\\" << std::endl;
    try {
        test_array[56];
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
}

void test_string() {
    size_t size = 5;
    Array<std::string> test_array(size);
    std::string source[] = {"blabla", "machin", "truc", "bidule", "superman"};

    std::cout << std::endl << "/!\\ test for std::string /!\\" << std::endl;

    for (unsigned int i = 0; i < test_array.size(); i++)
        test_array[i] = source[i];
    for (unsigned int i = 0; i < test_array.size(); i++)
        std::cout << "test_array[" << i << "] = " << test_array[i] << std::endl;

    //test size
    std::cout << "The current size of the array is: " << test_array.size() << std::endl;
}

int main() {

    test_int();
    test_string();

	//test without parameter
	std::cout << std::endl << "/!\\ test empty array /!\\" << std::endl;
	Array<float> test_array;
	try {
		std::cout << test_array[0] << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

    return (0);
}
