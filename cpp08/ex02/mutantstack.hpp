/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 19:15:15 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/14 19:15:16 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <algorithm>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() {}
	MutantStack(const MutantStack<T> & src) { *this = src; }
	MutantStack<T> & operator=(const MutantStack<T> & rhs);
	~MutantStack() {}

	typedef typename std::deque<T, std::allocator<T> >::iterator iterator;
	typedef typename std::deque<T, std::allocator<T> >::const_iterator const_iterator;
	typedef typename std::deque<T, std::allocator<T> >::reverse_iterator reverse_iterator;
	typedef typename std::deque<T, std::allocator<T> >::const_reverse_iterator const_reverse_iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }

	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }
	const_reverse_iterator begin() const { return this->c.rbegin(); }
	const_reverse_iterator end() const { return this->c.rend(); }
};

#endif
