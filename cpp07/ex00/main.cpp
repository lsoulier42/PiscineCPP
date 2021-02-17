/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:15:09 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/12 18:51:47 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

void test_swap() {

    //test int
    int a = 1;
    int b = 2;

    std::cout << "Test with int: " << std::endl;
    display_original<int>(a, b);
    swap<int>(a, b);
    display_swap<int>(a, b);

    //test float
    float fa = 42.789f;
    float fb = 21.987f;

    std::cout << "Test with float: " << std::endl;
    display_original<float>(fa, fb);
    swap<float>(fa, fb);
    display_swap<float>(fa, fb);

    //test string
    std::string sa = "Batman";
    std::string sb = "Robin";

    std::cout << "Test with string: " << std::endl;
    display_original<std::string>(sa, sb);
    swap<>(sa, sb);
    display_swap<std::string>(sa, sb);
}

void test_min() {
    //test int
    int a = 123456;
    int b = 234567;

    std::cout << "Test with int: " << std::endl;
    display_original<int>(a, b);
    std::cout << "The min value is : " << min<int>(a, b) << std::endl;

    //test double
    double da = 789.456;
    double db = 789.457;

    std::cout << "Test with double: " << std::endl;
    display_original<double>(da, db);
    std::cout << "The min value is : " << min<double>(da, db) << std::endl;

    //test char*
    char s1[] = "Dracofeu";
    char s2[] = "Salameche";

    std::cout << "Test with char*: " << std::endl;
    display_original<char*>(s1, s2);
    std::cout << "The min value is : " << min<char*>(s1, s2) << std::endl;


}

void test_max() {
    //test int
    int a = 42;
    int b = 21;

    std::cout << "Test with int: " << std::endl;
    display_original<int>(a, b);
    std::cout << "The max value is : " << max<int>(a, b) << std::endl;

    //test char
    char ca = 'a';
    char cb = 'z';

    std::cout << "Test with char: " << std::endl;
    display_original<char>(ca, cb);
    std::cout << "The max value is : " << max(ca, cb) << std::endl;

    //test foo
    Foo fa = Foo(15);
    Foo fb = Foo(19);

    std::cout << "Test with Foo instance: " << std::endl;
    display_original<Foo>(fa, fb);
    std::cout << "The max value is : " << max<Foo>(fa, fb) << std::endl;
}

int main() {

    std::cout << "Test of template function `swap<>' : " << std::endl;
    test_swap();

    std::cout << std::endl;
    std::cout << "Test of template function `min<>' : " << std::endl;
    test_min();

    std::cout << std::endl;
    std::cout << "Test of template function `max': " << std::endl;
    test_max();
	
    return (0);
}
