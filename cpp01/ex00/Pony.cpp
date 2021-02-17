/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:44:44 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/28 13:44:58 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony() {
	std::cout << "A new pony has been created." << std::endl;
}

Pony::Pony(std::string name, std::string hair_color, std::string mane_color, std::string race, std::string nationality,
		   int height, int weight, int *characteristics) : _name(name), _hair_color(hair_color), _mane_color(mane_color),
		   _race(race), _nationality(nationality), _height(height), _weight(weight) {
	for (int i = 0; i < TOTAL_CHARACTERISTICS; i++)
		this->_characteristics[i] = characteristics[i];
	std::cout << "A new pony, named " << this->_name << " has been created." << std::endl;
	if (this->_characteristics[IS_UNICORN]) {
		std::cout << "\n"
					 "                                                    /\n"
					 "                                                  .7\n"
					 "                                       \\       , //\n"
					 "                                       |\\.--._/|//\n"
					 "                                      /\\ ) ) ).'/\n"
					 "                                     /(  \\  // /\n"
					 "                                    /(   J`((_/ \\\n"
					 "                                   / ) | _\\     /\n"
					 "                                  /|)  \\  eJ    L\n"
					 "                                 |  \\ L \\   L   L\n"
					 "                                /  \\  J  `. J   L\n"
					 "                                |  )   L   \\/   \\\n"
					 "                               /  \\    J   (\\   /\n"
					 "             _....___         |  \\      \\   \\```\n"
					 "      ,.._.-'        '''--...-||\\     -. \\   \\\n"
					 "    .'.=.'                    `         `.\\ [ Y\n"
					 "   /   /                                  \\]  J\n"
					 "  Y / Y                                    Y   L\n"
					 "  | | |          \\                         |   L\n"
					 "  | | |           Y                        A  J\n"
					 "  |   I           |                       /I\\ /\n"
					 "  |    \\          I             \\        ( |]/|\n"
					 "  J     \\         /._           /        -tI/ |\n"
					 "   L     )       /   /'-------'J           `'-:.\n"
					 "   J   .'      ,'  ,' ,     \\   `'-.__          \\\n"
					 "    \\ T      ,'  ,'   )\\    /|        ';'---7   /\n"
					 "     \\|    ,'L  Y...-' / _.' /         \\   /   /\n"
					 "      J   Y  |  J    .'-'   /         ,--.(   /\n"
					 "       L  |  J   L -'     .'         /  |    /\\\n"
					 "       |  J.  L  J     .-;.-/       |    \\ .' /\n"
					 "       J   L`-J   L____,.-'`        |  _.-'   |\n"
					 "        L  J   L  J                  ``  J    |\n"
					 "        J   L  |   L                     J    |\n"
					 "         L  J  L    \\                    L    \\\n"
					 "         |   L  ) _.'\\                    ) _.'\\\n"
					 "         L    \\('`    \\                  ('`    \\\n"
					 "          ) _.'\\`-....'                   `-....'\n"
					 "         ('`    \\\n"
					 "          `-.___/" << std::endl;
	}
	else
	{
		std::cout << "      ,;;*;;;;,\n"
					 "     .-'``;-');;.\n"
					 "    /'  .-.  /*;;\n"
					 "  .'    \\d    \\;;               .;;;,\n"
					 " / o      `    \\;    ,__.     ,;*;;;*;,\n"
					 " \\__, _.__,'   \\_.-') __)--.;;;;;*;;;;,\n"
					 "  `\"\"`;;;\\       /-')_) __)  `\\' ';;;;;;\n"
					 "     ;*;;;        -') `)_)  |\\ |  ;;;;*;\n"
					 "     ;;;;|        `---`    O | | ;;*;;;\n"
					 "     *;*;\\|                 O  / ;;;;;*\n"
					 "    ;;;;;/|    .-------\\      / ;*;;;;;\n"
					 "   ;;;*;/ \\    |        '.   (`. ;;;*;;;\n"
					 "   ;;;;;'. ;   |          )   \\ | ;;;;;;\n"
					 "   ,;*;;;;\\/   |.        /   /` | ';;;*;\n"
					 "    ;;;;;;/    |/       /   /__/   ';;;\n"
					 "    '\"*\"'/     |       /    |      ;*;\n"
					 "         `\"\"\"\"`        `\"\"\"\"`     ;'" << std::endl;
	}
}

Pony::~Pony() {
	std::cout << "A pony ";
	if (!this->_name.empty())
		std::cout << "which name was " << this->_name << " ";
	std::cout << "went back to the moon." << std::endl;
}

void Pony::jump() const {
	this->displayName();
	std::cout << " makes a beautiful jump in the air." << std::endl;
}

void Pony::eat() const {
	this->displayName();
	std::cout << " is eating a sandwich." << std::endl;
}

void Pony::race() const {
	this->displayName();
	std::cout << " is running as fast as they can to win this race, but ends in the last position." << std::endl;
}

void Pony::whinny() const {
	this->displayName();
	std::cout << " tries to whinny but the sound is ridiculous." << std::endl;
}

void Pony::poop() const {
	this->displayName();
	if (this->_characteristics[IS_UNICORN])
		std::cout << " tries to poop but a beautiful rainbow seems to appear." << std::endl;
	else
		std::cout << " is pooping and it doesn't smell good at all." << std::endl;
}

void Pony::kick() const {
	this->displayName();
	std::cout << " is kicking awsomely" << std::endl;
}

std::string Pony::getName() const {
	return (this->_name);
}

void Pony::setName(std::string value) {
	this->_name = value;
}

void Pony::displayName() const {
	std::cout << this->_name;
}

std::string Pony::getHairColor() const {
	return (this->_hair_color);
}

void Pony::setHairColor(std::string value) {
	this->_hair_color = value;
}

void Pony::displayHairColor() const {
	this->displayName();
	std::cout << " has beautiful " << this->_hair_color << " hair color" << std::endl;
}

std::string Pony::getManeColor() const {
	return (this->_mane_color);
}

void Pony::setManeColor(std::string value) {
	this->_mane_color = value;
}

void Pony::displayManeColor() const {
	std::cout << "The mane color of " << this->_name << " is " << this->_mane_color << std::endl;
}

std::string Pony::getRace() const {
	return (this->_race);
}

void Pony::setRace(std::string value) {
	this->_race = value;
}

void Pony::displayRace() const {
	std::cout << "Their race (this pony, like every pony, is non-binary, and want to use neutral pronouns) is " << this->_race << std::endl;
}

std::string Pony::getNationality() const {
	return (this->_nationality);
}

void Pony::setNationality(std::string value) {
	this->_nationality = value;
}

void Pony::displayNationality() const {
	std::cout << "The nationality is " << this->_nationality << std::endl;
}

int Pony::getHeight() const {
	return (this->_height);
}

void Pony::setHeight(int h) {
	this->_height = h;
}

void Pony::displayHeight() const {
	this->displayName();
	std::cout << " is " << this->_height << "cm tall" << std::endl;
}

int Pony::getWeigth() const {
	return (this->_weight);
}

void Pony::setWeight(int w) {
	this->_weight = w;
}

void Pony::displayWeight() const {
	this->displayName();
	std::cout << " weight " << this->_weight << "kg" << std::endl;
}

int* Pony::getCharacteristics() const {
	return ((int*)this->_characteristics);
}

void Pony::setCharacteristics(int *characteristics) {
	for(int i = 0; i < TOTAL_CHARACTERISTICS; i++)
		this->_characteristics[i] = characteristics[i];
}

void Pony::displayCharacteristics() const {
	for (int i = 0; i < TOTAL_CHARACTERISTICS; i++)
		this->displayCharacteristic(i);
}

int Pony::getCharacteristic(int id) const {
	return (this->_characteristics[id]);
}

void Pony::setCharacteristic(int id, int c) {
	this->_characteristics[id] = c;
}

void Pony::displayCharacteristic(int id) const {
	std::string displayIs[TOTAL_CHARACTERISTICS] = {"is a unicorn", "is famous", "has won a race (one day)",
		"is from the british royal family", "is from my little pony (the show)", "does speak!",	"wears horseshoes"};
	std::string displayNot[TOTAL_CHARACTERISTICS] = {"is not a unicorn (shame on them)", "is absolutely not famous (at all)",
		"has never ever won a race, and will probably ends up in a steak", "is not from any royal family",
		"is not from the show my little pony", "doesn't speak, it's a pony, you idiot!", "has never seen a blacksmith"};

	this->displayName();
	std::cout << " ";
	if (this->_characteristics[id])
		 std::cout << displayIs[id] << std::endl;
	else
		std::cout << displayNot[id] << std::endl;
}

void Pony::displayPony() const {
	std::cout << "Poney description :" << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	this->displayHairColor();
	this->displayManeColor();
	this->displayRace();
	this->displayNationality();
	this->displayHeight();
	this->displayWeight();
	this->displayCharacteristics();
}
