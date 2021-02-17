/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 22:17:30 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/09 22:17:35 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma pack(1)
#include "main.hpp"

void* serialize(void) {
	Data* result = new Data;
	static int add = 42;
	std::string alnum = "abcdefghijklmnopqrstuvwxyz123456789";

	result->s1.resize(STR_SIZE);
	result->s2.resize(STR_SIZE);
	std::srand(std::time(NULL));
	result->randomInt = std::rand();

	for (int i = 0; i < STR_SIZE; i++) {
		result->s1[i] = alnum[(std::rand() + add) % alnum.size()];
		add += 21;
	}

	for (int i = 0; i < STR_SIZE; i++) {
		result->s2[i] = alnum[(std::rand() + add) % alnum.size()];
		add += 21;
	}

	std::cout << "1/Data randomly generate by seralize function in (void*) :" << std::endl;
	std::cout << "first random alnum string: " << result->s1 << std::endl;
	std::cout << "random int: " << result->randomInt << std::endl;
	std::cout << "second random alnum string: " << result->s2 << std::endl;
	return reinterpret_cast<void*>(result);
}

Data*  deserialize(void * raw) {
	return reinterpret_cast<Data*>(raw);
}

int main() {
	void* rawData = serialize();
	Data* concreteData = deserialize(rawData);

	std::cout << std::endl << "2/Same data deserialized in (Data*): " << std::endl;
	std::cout << "s1: " << concreteData->s1 << std::endl;
	std::cout << "int: " << concreteData->randomInt << std::endl;
	std::cout << "s2: " << concreteData->s2 << std::endl;
	std::cout << "On your system: sizeof(std::string) is " << sizeof(std::string);
	std::cout << " bytes and sizeof(int) is " << sizeof(int) << " bytes" << std::endl;
	std::cout << "So the serialize data should size: " << sizeof(std::string);
	std::cout << " + " << sizeof(int) << " + " << sizeof(std::string) << std::endl;
	std::cout << "sizeof rawData: " << sizeof(*concreteData) << std::endl;
	delete concreteData;
}
