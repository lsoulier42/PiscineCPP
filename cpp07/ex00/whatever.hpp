/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:15:04 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/11 12:15:05 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>
# include <string>

template<typename T>
void swap(T & a, T & b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T const & min(T const & a, T const & b) {
    return ((a >= b) ? b : a);
}

template<typename T>
T const & max(T const & a, T const & b) {
    return ((a <= b) ? b : a);
}

template<typename T>
void display_original(T const & a, T const & b) {
    std::cout << "Original value of a: " << a << std::endl;
    std::cout << "Original value of b: " << b << std::endl;
}

template<typename T>
void display_swap(T const & a, T const & b) {
    std::cout << "Modified value of a: " << a << std::endl;
    std::cout << "Modified value of b: " << b << std::endl;
}

class Foo {
public:
    Foo(int d);
    Foo(const Foo & src);
    Foo & operator=(const Foo & rhs);
    bool operator<=(const Foo & rhs) const;
    bool operator>=(const Foo &rhs) const;
    ~Foo();
    int getD() const;

private:
    Foo();
    int _d;
};

std::ostream & operator<<(std::ostream & o, Foo const & src);

#endif
