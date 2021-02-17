/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:08:00 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/29 17:08:07 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

int manage_files(std::string filename, std::string s1, std::string s2)
{
	std::ifstream fd(filename.c_str());

	if(!fd) {
		std::cerr << "Error : File couldn't be opened." << std::endl;
		return (0);
	}

	std::string newFile = filename + ".replace";
	std::ofstream out(newFile.c_str());
	size_t position;
	std::string buffer;

	if (!out) {
		fd.close();
		std::cerr << "Error : The new file couldn't be created." << std::endl;
		return (0);
	}

	while (fd) {
		std::getline(fd, buffer);
		while((position = buffer.find(s1)) != std::string::npos)
			buffer.replace(position, s1.size(), s2);
		out << buffer << std::endl;
	}
	out.close();
	fd.close();
	return (1);
}

int check_errors(std::string filename, std::string s1, std::string s2)
{
	if (filename.empty()) {
		std::cerr << "Error : The filename can't be empty." << std::endl;
		return (0);
	}
	if (s1.empty()) {
		std::cerr << "Error : The first string can't be empty." << std::endl;
		return (0);
	}
	if (s2.empty()) {
		std::cerr << "Error : The second string can't be empty." << std::endl;
		return (0);
	}
	return (1);
}

int manage_argv(char **argv)
{
	std::string filename(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);

	if (!check_errors(filename, s1, s2))
		return (0);
	if (!manage_files(filename, s1, s2))
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cerr << "Error : Invalid number of arguments" << std::endl;
		return (1);
	}
	if (!manage_argv(argv))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
