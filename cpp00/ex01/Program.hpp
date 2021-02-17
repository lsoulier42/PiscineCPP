/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Program.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:22:18 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/26 14:22:38 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_HPP
# define PROGRAM_HPP
# include "Calepin.hpp"
# include <iostream>
# include <string>

typedef enum	e_commands
{
	EXIT,
	ADD,
	SEARCH,
	HELP,
	TOTAL_COMMANDS
}				t_commands;

class Program {
public:
	Program();
	~Program();

	void	exit(Calepin *phonebook);
	void	add(Calepin *phonebook);
	void	search(Calepin *phonebook);
	void	help(Calepin *phonebook);
	int 	getRun() const;
	bool	isNumber(const std::string &str) const;

private:
	int 		_run;
	int 		_nbContacts;
};

#endif
