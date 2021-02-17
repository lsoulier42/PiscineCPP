/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:20:06 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/28 13:20:35 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP
# include <string>
# include <iostream>

typedef enum	e_characteristics
{
	IS_UNICORN,
	IS_FAMOUS,
	WON_RACES,
	IS_ROYAL,
	IS_LITTLE,
	SPEAKS,
	WEARS_SHOES,
	TOTAL_CHARACTERISTICS
}				t_characteristics;

class Pony {
public:
	Pony();
	Pony(std::string name, std::string hair_color,
	  std::string mane_color, std::string race, std::string nationality,
	  int height, int weight, int *characteristics);
	~Pony();

	void jump() const;
	void eat() const;
	void race() const;
	void whinny() const;
	void poop() const;
	void kick() const;

	std::string getName() const;
	void setName(std::string value);
	void displayName() const;
	std::string getHairColor() const;
	void setHairColor(std::string value);
	void displayHairColor() const;
	std::string getManeColor() const;
	void setManeColor(std::string value);
	void displayManeColor() const;
	std::string getRace() const;
	void setRace(std::string value);
	void displayRace() const;
	std::string getNationality() const;
	void setNationality(std::string value);
	void displayNationality() const;
	int getHeight() const;
	void setHeight(int h);
	void displayHeight() const;
	int getWeigth() const;
	void setWeight(int w);
	void displayWeight() const;
	int *getCharacteristics() const;
	void setCharacteristics(int *characteristics);
	void displayCharacteristics() const;
	int getCharacteristic(int id) const;
	void setCharacteristic(int id, int c);
	void displayCharacteristic(int id) const;
	void displayPony() const;

private:
	std::string _name;
	std::string _hair_color;
	std::string	_mane_color;
	std::string _race;
	std::string _nationality;
	int			_height;
	int			_weight;
	int 		_characteristics[TOTAL_CHARACTERISTICS];
};

#endif
