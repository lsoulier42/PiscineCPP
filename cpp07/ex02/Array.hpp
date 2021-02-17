/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:29:38 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/11 15:29:39 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <stdexcept>

template<typename T>
class Array {
public:
    Array() : _nb(0), _elements(NULL) {}

    Array(unsigned int n) : _nb(n), _elements(new T[n]) {}

    Array(const Array<T> & src) { this->_deepCopy(src); }

    Array<T> & operator=(const Array<T> & rhs) {
        if (this != rhs)
            this->_deepCopy();
        return *this;
    }

    virtual ~Array() {
		if (this->_elements)
			delete [] this->_elements;
    }

    unsigned int size() const { return this->_nb; }

    T & operator[](unsigned int idx) const {
        if (!this->_elements || idx >= this->_nb || idx < 0)
            throw Array<T>::OutOfLimitException();
        return this->_elements[idx];
    }

    class OutOfLimitException : public std::exception {
    public:
        const char* what() const throw() {
            return "this element doesn't exist in this Array";
        }
    };

private:
    unsigned int _nb;
    T* _elements;

    void _deepCopy(const Array<T> & src) {
        this->_nb = src.size();
        if (this->_elements)
			delete [] this->_elements;
        this->_elements = new T[src.size()];
        for(unsigned int i = 0; i < src.size(); i++)
            this->_elements[i] = src[i];
    }
};

#endif
