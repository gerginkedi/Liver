#pragma once

#include <string>
#include "Weapon.h"
#include "Armor.h"
#include <iostream>
#include <cstdlib>

struct Stats
{
	int will = 8;
	int strength = 8;
	int dexterity = 8;
	int constitution = 8;
	int charisma = 8;
};


class Liver {
public:
	static Liver MakeLiverReadyToPlay(Liver notReadyLiver) {
		int buyPoints = 27;
		std::string input;
		std::string input2;

		while (buyPoints >= 0)
		{

			std::cout << "You have " << buyPoints << " points to spend on your stats." << std::endl;
			std::cout << "1. Will: " << notReadyLiver.stats.will << std::endl;
			std::cout << "2. Strength: " << notReadyLiver.stats.strength << std::endl;
			std::cout << "3. Dexterity: " << notReadyLiver.stats.dexterity << std::endl;
			std::cout << "4. Constitution: " << notReadyLiver.stats.constitution << std::endl;
			std::cout << "5. Charisma: " << notReadyLiver.stats.charisma << std::endl;
			std::cout << "6. Confirm and Finish" << std::endl;
			std::cout << "------------------------------------------------" << std::endl;
			std::cout << "select a stat to increase --> ";
			std::cin >> input;

			while (input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6") {
				std::cout << "invalid input" << std::endl;
				std::cout << "You have " << buyPoints << " points to spend on your stats." << std::endl;
				std::cout << "1. Will: " << notReadyLiver.stats.will << std::endl;
				std::cout << "2. Strength: " << notReadyLiver.stats.strength << std::endl;
				std::cout << "3. Dexterity: " << notReadyLiver.stats.dexterity << std::endl;
				std::cout << "4. Constitution: " << notReadyLiver.stats.constitution << std::endl;
				std::cout << "5. Charisma: " << notReadyLiver.stats.charisma << std::endl;
				std::cout << "6. Confirm and Finish" << std::endl;
				std::cout << "------------------------------------------------" << std::endl;
				std::cout << "select a stat to increase --> ";
				std::cin >> input;
			}
			if (input == "6") {
				std::cout << "Character creation finished! Your stats have been confirmed." << std::endl;
				break;
			}
			else if (input == "1") {
				std::cout << "will selected, current will: " << notReadyLiver.stats.will << std::endl;
				std::cout << "type 1 to increase +1 type 2 to decrease -1. to quit 3 --> ";
				std::cin >> input2;
				while (input2 != "1" && input2 != "2" && input2 != "3")
				{
					std::cout << "invalid input,type 1 to increase +1 type 2 to decrease -1 to quit 3 --> ";
					std::cin >> input2;
				}
				while (input2 != "3")
				{
					if (input2 == "1") {
						if (buyPoints > 0) {
							notReadyLiver.stats.will++;
							buyPoints--;
							std::cout << "will increased to: " << notReadyLiver.stats.will << std::endl;
						}
						else {
							std::cout << "Not enough buyPoints to increase this stat." << std::endl;
						}
					}

					if (input2 == "2") {
						if (notReadyLiver.stats.will > 0) {
							notReadyLiver.stats.will--;
							buyPoints++;
							std::cout << "will decreased to: " << notReadyLiver.stats.will << std::endl;
						}
						else {
							std::cout << "This stat cannot be decreased any further." << std::endl;
						}
					}
					std::cout << "Remaining buyPoints: " << buyPoints << std::endl;
					std::cout << "type 1 to increase +1 type 2 to decrease -1. to quit 3 --> ";
					std::cin >> input2;
				}
			}
			else if (input == "2") {
				std::cout << "strength selected, current strength: " << notReadyLiver.stats.strength << std::endl;
				std::cout << "type 1 to increase +1 type 2 to decrease -1. to quit 3 --> ";
				std::cin >> input2;
				while (input2 != "1" && input2 != "2" && input2 != "3")
				{
					std::cout << "invalid input,type 1 to increase +1 type 2 to decrease -1 to quit 3 --> ";
					std::cin >> input2;
				}
				while (input2 != "3")
				{
					if (input2 == "1") {
						if (buyPoints > 0) {
							notReadyLiver.stats.strength++;
							buyPoints--;
							std::cout << "strength increased to: " << notReadyLiver.stats.strength << std::endl;
						}
						else {
							std::cout << "Not enough buyPoints to increase this stat." << std::endl;
						}
					}

					if (input2 == "2") {
						if (notReadyLiver.stats.strength > 0) {
							notReadyLiver.stats.strength--;
							buyPoints++;
							std::cout << "strength decreased to: " << notReadyLiver.stats.strength << std::endl;
						}
						else {
							std::cout << "This stat cannot be decreased any further." << std::endl;
						}
					}
					std::cout << "Remaining buyPoints: " << buyPoints << std::endl;
					std::cout << "type 1 to increase +1 type 2 to decrease -1. to quit 3 --> ";
					std::cin >> input2;
				}
			}
			else if (input == "3") {
				std::cout << "dexterity selected, current dexterity: " << notReadyLiver.stats.dexterity << std::endl;
				std::cout << "type 1 to increase +1 type 2 to decrease -1. to quit 3 --> ";
				std::cin >> input2;
				while (input2 != "1" && input2 != "2" && input2 != "3")
				{
					std::cout << "invalid input,type 1 to increase +1 type 2 to decrease -1 to quit 3 --> ";
					std::cin >> input2;
				}
				while (input2 != "3")
				{
					if (input2 == "1") {
						if (buyPoints > 0) {
							notReadyLiver.stats.dexterity++;
							buyPoints--;
							std::cout << "dexterity increased to: " << notReadyLiver.stats.dexterity << std::endl;
						}
						else {
							std::cout << "Not enough buyPoints to increase this stat." << std::endl;
						}
					}

					if (input2 == "2") {
						if (notReadyLiver.stats.dexterity > 0) {
							notReadyLiver.stats.dexterity--;
							buyPoints++;
							std::cout << "dexterity decreased to: " << notReadyLiver.stats.dexterity << std::endl;
						}
						else {
							std::cout << "This stat cannot be decreased any further." << std::endl;
						}
					}
					std::cout << "Remaining buyPoints: " << buyPoints << std::endl;
					std::cout << "type 1 to increase +1 type 2 to decrease -1. to quit 3 --> ";
					std::cin >> input2;
				}
			}
			else if (input == "4") {
				std::cout << "constitution selected, current constitution: " << notReadyLiver.stats.constitution << std::endl;
				std::cout << "type 1 to increase +1 type 2 to decrease -1. to quit 3 --> ";
				std::cin >> input2;
				while (input2 != "1" && input2 != "2" && input2 != "3")
				{
					std::cout << "invalid input,type 1 to increase +1 type 2 to decrease -1 to quit 3 --> ";
					std::cin >> input2;
				}
				while (input2 != "3")
				{
					if (input2 == "1") {
						if (buyPoints > 0) {
							notReadyLiver.stats.constitution++;
							buyPoints--;
							std::cout << "constitution increased to: " << notReadyLiver.stats.constitution << std::endl;
						}
						else {
							std::cout << "Not enough buyPoints to increase this stat." << std::endl;
						}
					}

					if (input2 == "2") {
						if (notReadyLiver.stats.constitution > 0) {
							notReadyLiver.stats.constitution--;
							buyPoints++;
							std::cout << "constitution decreased to: " << notReadyLiver.stats.constitution << std::endl;
						}
						else {
							std::cout << "This stat cannot be decreased any further." << std::endl;
						}
					}
					std::cout << "Remaining buyPoints: " << buyPoints << std::endl;
					std::cout << "type 1 to increase +1 type 2 to decrease -1. to quit 3 --> ";
					std::cin >> input2;
				}
			}
			else if (input == "5") {
				std::cout << "charisma selected, current charisma: " << notReadyLiver.stats.charisma << std::endl;
				std::cout << "type 1 to increase +1 type 2 to decrease -1. to quit 3 --> ";
				std::cin >> input2;
				while (input2 != "1" && input2 != "2" && input2 != "3")
				{
					std::cout << "invalid input,type 1 to increase +1 type 2 to decrease -1 to quit 3 --> ";
					std::cin >> input2;
				}
				while (input2 != "3")
				{
					if (input2 == "1") {
						if (buyPoints > 0) {
							notReadyLiver.stats.charisma++;
							buyPoints--;
							std::cout << "charisma increased to: " << notReadyLiver.stats.charisma << std::endl;
						}
						else {
							std::cout << "Not enough buyPoints to increase this stat." << std::endl;
						}
					}

					if (input2 == "2") {
						if (notReadyLiver.stats.charisma > 0) {
							notReadyLiver.stats.charisma--;
							buyPoints++;
							std::cout << "charisma decreased to: " << notReadyLiver.stats.charisma << std::endl;
						}
						else {
							std::cout << "This stat cannot be decreased any further." << std::endl;
						}
					}
					std::cout << "Remaining buyPoints: " << buyPoints << std::endl;
					std::cout << "type 1 to increase +1 type 2 to decrease -1. to quit 3 --> ";
					std::cin >> input2;
				}
			}
		}
		return notReadyLiver;

	};
	Liver() = default;
	int hitPoints;
	int RollD20() {
		return rand() % 20 + 1;

	};

	int id;
	int level;
	std::string race;
	std::string name;

	Stats stats;
	Weapons weapon;
	Armor armor;
public:
	virtual ~Liver() {};
};

