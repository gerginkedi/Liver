#include "SaveManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

// ============================================================
//  KAYDET
// ============================================================
void SaveManager::SavePlayer(const Liver& player, const std::string& filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cout << "Error: Could not open file for saving." << std::endl;
        return;
    }

    file << "name=" << player.name << "\n";
    file << "id=" << player.id << "\n";
    file << "level=" << player.level << "\n";
    file << "exp=" << player.exp << "\n";
    file << "hitPoints=" << player.hitPoints << "\n";
    file << "will=" << player.getWill() << "\n";
    file << "strength=" << player.getStrength() << "\n";
    file << "dexterity=" << player.getDexterity() << "\n";
    file << "constitution=" << player.getConstitution() << "\n";
    file << "charisma=" << player.getCharisma() << "\n";
    file << "weaponName=" << player.weapon.Name << "\n";
    file << "weaponAttack=" << player.weapon.AttackPoints << "\n";
    file << "armorName=" << player.armor.Name << "\n";
    file << "armorDefense=" << player.armor.DefensePoints << "\n";

    file.close();
    std::cout << "Game saved successfully." << std::endl;
}

// ============================================================
//  YUKLE
// ============================================================
bool SaveManager::LoadPlayer(Liver& player, const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "No save file found." << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        // Her satiri "key=value" olarak ayir
        std::istringstream ss(line);
        std::string key;
        std::string value;

        if (!std::getline(ss, key, '=')) continue;
        if (!std::getline(ss, value))    continue;

        if (key == "name")         player.name = value;
        else if (key == "id")           player.id = std::stoi(value);
        else if (key == "level")        player.level = std::stoi(value);
        else if (key == "exp")          player.exp = std::stoi(value);
        else if (key == "hitPoints")    player.hitPoints = std::stoi(value);
        else if (key == "will")         player.setWill(std::stoi(value));
        else if (key == "strength")     player.setStrength(std::stoi(value));
        else if (key == "dexterity")    player.setDexterity(std::stoi(value));
        else if (key == "constitution") player.setConstitution(std::stoi(value));
        else if (key == "charisma")     player.setCharisma(std::stoi(value));
        else if (key == "weaponName")   player.weapon.Name = value;
        else if (key == "weaponAttack") player.weapon.AttackPoints = std::stoi(value);
        else if (key == "armorName")    player.armor.Name = value;
        else if (key == "armorDefense") player.armor.DefensePoints = std::stoi(value);
    }

    file.close();
    std::cout << "Game loaded successfully. Welcome back, " << player.name << "!" << std::endl;
    return true;
}