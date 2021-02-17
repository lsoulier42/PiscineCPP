/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:06:29 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/11 14:06:31 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void print_tab(int const & n) {
    static int i = 0;
    std::cout << "tab["<< i++ << "] = " << n << std::endl;
}

void is_unique_word(std::string const & str) {
    std::cout << "|" << str << "| is: ";
    if (str.find(" ") != std::string::npos)
        std::cout << "not a unique word" << std::endl;
    else
        std::cout << "a unique word" << std::endl;
}

int main() {
    std::cout << "Array of int: " << std::endl;
    int array[10] = {4, 8, 15, 16, 23, 42, 5, 7, 8, 10};
    iter<int>(array, 10, print_tab);

    std::cout << std::endl;
    std::cout << "Array of str: " << std::endl;
    std::string str_array[5] = {"abcde", "Batman et Robin", "Melofee", "Covid", "La mere Michelle"};
    iter<std::string>(str_array, 5, is_unique_word);

    std::cout << std::endl;
    std::cout << "Instantiated function template: " << std::endl;
    iter<int>(array, 10, add2<int>);
    return (0);
}