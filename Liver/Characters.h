#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include "Weapon.h"
#include "Armor.h"

struct Stats {
    int will = 8;
    int strength = 8;
    int dexterity = 8;
    int constitution = 8;
    int charisma = 8;
};

class Liver {
private:
    Stats stats;

    static const int STAT_MIN = 0;
    static const int STAT_MAX = 16;   // Karakter oluşturma üst sınırı
    static const int BUY_POINTS = 27;

public:
    Liver() = default;
    virtual ~Liver() = default;

    // --- Getters ---
    int getWill()         const { return stats.will; }
    int getStrength()     const { return stats.strength; }
    int getDexterity()    const { return stats.dexterity; }
    int getConstitution() const { return stats.constitution; }
    int getCharisma()     const { return stats.charisma; }

    // --- Setters ---
    void setWill(int v) { if (v >= 0) stats.will = v; }
    void setStrength(int v) { if (v >= 0) stats.strength = v; }
    void setDexterity(int v) { if (v >= 0) stats.dexterity = v; }
    void setConstitution(int v) { if (v >= 0) stats.constitution = v; }
    void setCharisma(int v) { if (v >= 0) stats.charisma = v; }

    int RollD20() { return rand() % 20 + 1; }

    // ============================================================
    //  KARAKTER OLUŞTURMA
    // ============================================================
    static Liver MakeLiverReadyToPlay(Liver liver) {
        int buyPoints = BUY_POINTS;
        std::string input;

        while (true) {
            // --- Menü ---
            std::cout << "\n========== STAT ALLOCATION ==========" << std::endl;
            std::cout << "Buy Points: " << buyPoints
                << "  |  Max per stat: " << STAT_MAX << std::endl;
            std::cout << "--------------------------------------" << std::endl;
            std::cout << "1. Will:         " << liver.getWill() << std::endl;
            std::cout << "2. Strength:     " << liver.getStrength() << std::endl;
            std::cout << "3. Dexterity:    " << liver.getDexterity() << std::endl;
            std::cout << "4. Constitution: " << liver.getConstitution() << std::endl;
            std::cout << "5. Charisma:     " << liver.getCharisma() << std::endl;
            std::cout << "6. Confirm and Finish" << std::endl;
            std::cout << "======================================" << std::endl;
            std::cout << "Select a stat --> ";
            std::cin >> input;

            while (input != "1" && input != "2" && input != "3" &&
                input != "4" && input != "5" && input != "6") {
                std::cout << "Invalid input. Enter 1-6 --> ";
                std::cin >> input;
            }

            if (input == "6") {
                std::cout << "Stats confirmed!" << std::endl;
                break;
            }

            // Seçilen statın mevcut değerini ve adını al
            int         current = 0;
            std::string statName;

            if (input == "1") { current = liver.getWill();         statName = "Will"; }
            else if (input == "2") { current = liver.getStrength();     statName = "Strength"; }
            else if (input == "3") { current = liver.getDexterity();    statName = "Dexterity"; }
            else if (input == "4") { current = liver.getConstitution(); statName = "Constitution"; }
            else if (input == "5") { current = liver.getCharisma();     statName = "Charisma"; }

            // Kullanıcıya mevcut durum ve sınırları göster
            std::cout << "\n" << statName << ": " << current
                << "  (min: " << STAT_MIN
                << "  max: " << STAT_MAX
                << "  buy points: " << buyPoints << ")" << std::endl;
            std::cout << "Enter amount to add/remove (e.g. 3 or -2), 0 to cancel --> ";

            int amount = 0;
            std::cin >> amount;

            if (amount == 0) continue;

            int newValue = current + amount;

            // --- Doğrulama ---
            if (amount > 0) {
                if (amount > buyPoints) {
                    std::cout << "Not enough buy points. You only have "
                        << buyPoints << "." << std::endl;
                    continue;
                }
                if (newValue > STAT_MAX) {
                    std::cout << statName << " cannot exceed " << STAT_MAX
                        << ". Maximum you can add: "
                        << STAT_MAX - current << "." << std::endl;
                    continue;
                }
            }
            else {
                if (newValue < STAT_MIN) {
                    std::cout << statName << " cannot go below " << STAT_MIN
                        << ". Maximum you can remove: "
                        << current - STAT_MIN << "." << std::endl;
                    continue;
                }
            }

            // --- Uygula ---
            if (input == "1") liver.setWill(newValue);
            else if (input == "2") liver.setStrength(newValue);
            else if (input == "3") liver.setDexterity(newValue);
            else if (input == "4") liver.setConstitution(newValue);
            else if (input == "5") liver.setCharisma(newValue);

            buyPoints -= amount;  // negatif amount buyPoints'i iade eder

            std::cout << statName << " set to " << newValue
                << "  |  Buy points remaining: " << buyPoints << std::endl;
        }

        return liver;
    }

    int         id;
    int         level = 1;
    int         exp = 0;
    int         hitPoints = 0;
    std::string name;
    std::string race;
    Weapons     weapon;
    Armor       armor;
};