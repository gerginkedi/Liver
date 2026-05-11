#include "GameManager.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

GameManager::GameManager() {
    srand(static_cast<unsigned int>(time(nullptr)));
    InitEnemies();
}

// ============================================================
//  DÜŞMAN VERİLERİ
//  { name, minLevel, maxLevel, baseHP, baseAttack, baseDefense }
//
//  Gerçek değerler:
//    HP     = baseHP + (playerLevel * 2)
//    Attack = baseAttack + playerLevel
// ============================================================
void GameManager::InitEnemies() {

    // --- Mağara Düşmanları ---
    caveEnemies = {
        // Erken oyun
        { "Bat",          1, 3,  15,  3, 0 },
        { "Skeleton",     1, 5,  25,  5, 2 },
        // Orta oyun — zehir benzeri yüksek saldırı, düşük savunma
        { "Giant Spider", 2, 6,  35,  7, 1 },
        // Geç orta oyun — aldatıcı, yüksek HP ve savunma
        { "Mimic",        4, 8,  45,  9, 3 },
        // Geç oyun — düşük HP ama hasar çok yüksek
        { "Dark Mage",    6, 10, 40, 12, 2 },
    };

    // --- Orman Düşmanları ---
    forestEnemies = {
        // Erken oyun
        { "Goblin",        1, 4,  20,  4, 1 },
        { "Wolf",          1, 5,  30,  6, 0 },
        // Orta oyun — tank, çok yüksek HP ve savunma, orta saldırı
        { "Troll",         3, 7,  60,  8, 4 },
        // Geç oyun — kırılgan ama çok saldırgan
        { "Forest Witch",  5, 9,  35, 11, 1 },
    };
}

// ============================================================
//  DÜŞMAN ÜRET
// ============================================================
Liver GameManager::SpawnEnemy(int playerLevel, Area area) {
    std::vector<EnemyTemplate>* pool = nullptr;

    if (area == Area::CAVE)   pool = &caveEnemies;
    if (area == Area::FOREST) pool = &forestEnemies;

    std::vector<EnemyTemplate> eligible;
    for (const auto& tmpl : *pool) {
        if (playerLevel >= tmpl.minLevel && playerLevel <= tmpl.maxLevel)
            eligible.push_back(tmpl);
    }

    EnemyTemplate chosen = eligible.empty() ? (*pool)[0]
                                            : eligible[rand() % eligible.size()];
    Liver enemy;
    enemy.name                 = chosen.name;
    enemy.hitPoints            = chosen.baseHP + (playerLevel * 2);
    enemy.weapon.AttackPoints  = chosen.baseAttack + playerLevel;
    enemy.armor.DefensePoints  = chosen.baseDefense;

    return enemy;
}

// ============================================================
//  OYUN BAŞLANGICI
// ============================================================
void GameManager::startGame() {
    std::string choice;

    while (true) {
        std::cout << "\n========================================" << std::endl;
        std::cout << "          WELCOME TO THE GAME           " << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "1. New Game"                              << std::endl;
        std::cout << "2. Continue (Load Save)"                  << std::endl;
        std::cout << "3. Quit"                                  << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "Choice --> ";
        std::cin >> choice;

        while (choice != "1" && choice != "2" && choice != "3") {
            std::cout << "Invalid input. Enter 1-3 --> ";
            std::cin >> choice;
        }

        if      (choice == "1") { NewGame(); break; }
        else if (choice == "2") { LoadGame(); break; }
        else if (choice == "3") { std::cout << "Goodbye!" << std::endl; break; }
    }
}

// ============================================================
//  YENİ OYUN
// ============================================================
void GameManager::NewGame() {
    Liver player;

    std::cout << "\nEnter character name: ";
    std::cin >> player.name;

    player = Liver::MakeLiverReadyToPlay(player);

    player.hitPoints           = 30 + player.getConstitution() * 2;
    player.weapon.Name         = "Iron Sword";
    player.weapon.AttackPoints = 3 + (player.getStrength() + player.getDexterity()) / 7;
    player.armor.Name          = "Leather Armor";
    player.armor.DefensePoints = 3 + player.getStrength() / 10;

    std::cout << "\nWelcome, " << player.name << "! Your adventure begins..." << std::endl;

    MainMenu(player);
}

// ============================================================
//  KAYITTAN DEVAM
// ============================================================
void GameManager::LoadGame() {
    Liver player;

    if (!saveManager.LoadPlayer(player, "save.txt")) {
        std::cout << "Returning to main menu..." << std::endl;
        startGame();
        return;
    }

    MainMenu(player);
}

// ============================================================
//  ANA MENÜ
// ============================================================
void GameManager::MainMenu(Liver& player) {
    std::string choice;

    while (true) {
        std::cout << "\n========== MAIN MENU ==========" << std::endl;
        std::cout << "[ " << player.name << " ]"
                  << "  Level: " << player.level
                  << "  HP: "    << player.hitPoints
                  << "  EXP: "   << player.exp         << std::endl;
        std::cout << "--------------------------------" << std::endl;
        std::cout << "1. Village"        << std::endl;
        std::cout << "2. Cave"           << std::endl;
        std::cout << "3. Forest"         << std::endl;
        std::cout << "4. Save"           << std::endl;
        std::cout << "5. Quit to Title"  << std::endl;
        std::cout << "================================" << std::endl;
        std::cout << "Choice --> ";
        std::cin >> choice;

        while (choice != "1" && choice != "2" && choice != "3" &&
               choice != "4" && choice != "5") {
            std::cout << "Invalid input. Enter 1-5 --> ";
            std::cin >> choice;
        }

        if      (choice == "1") Village(player);
        else if (choice == "2") Cave(player);
        else if (choice == "3") Forest(player);
        else if (choice == "4") saveManager.SavePlayer(player, "save.txt");
        else if (choice == "5") {
            std::cout << "Returning to title..." << std::endl;
            startGame();
            break;
        }
    }
}

// ============================================================
//  KÖY
// ============================================================
void GameManager::Village(Liver& player) {
    std::string choice;
    int maxHP = 30 + player.getConstitution() * 2;

    while (true) {
        std::cout << "\n========== VILLAGE ==========" << std::endl;
        std::cout << "HP: " << player.hitPoints << " / " << maxHP << std::endl;
        std::cout << "-----------------------------" << std::endl;
        std::cout << "1. Rest (restore HP)"         << std::endl;
        std::cout << "2. Shop"                      << std::endl;
        std::cout << "3. Back"                      << std::endl;
        std::cout << "=============================" << std::endl;
        std::cout << "Choice --> ";
        std::cin >> choice;

        while (choice != "1" && choice != "2" && choice != "3") {
            std::cout << "Invalid input. Enter 1-3 --> ";
            std::cin >> choice;
        }

        if (choice == "1") {
            player.hitPoints = maxHP;
            std::cout << "You rested. HP fully restored to " << maxHP << "." << std::endl;
        } else if (choice == "2") {
            std::cout << "The shopkeeper greets you. (Shop coming soon!)" << std::endl;
        } else if (choice == "3") {
            break;
        }
    }
}

// ============================================================
//  MAĞARA
// ============================================================
void GameManager::Cave(Liver& player) {
    std::string choice;

    std::cout << "\nYou enter the dark cave..." << std::endl;

    while (true) {
        if (player.hitPoints <= 0) break;

        Liver enemy = SpawnEnemy(player.level, Area::CAVE);
        Battle(player, enemy);

        if (player.hitPoints <= 0) break;

        std::cout << "\n1. Continue deeper into the cave" << std::endl;
        std::cout << "2. Return to Main Menu"             << std::endl;
        std::cout << "Choice --> ";
        std::cin >> choice;

        while (choice != "1" && choice != "2") {
            std::cout << "Invalid input. Enter 1 or 2 --> ";
            std::cin >> choice;
        }

        if (choice == "2") break;
    }
}

// ============================================================
//  ORMANLIK
// ============================================================
void GameManager::Forest(Liver& player) {
    std::string choice;

    std::cout << "\nYou venture into the dense forest..." << std::endl;

    while (true) {
        if (player.hitPoints <= 0) break;

        Liver enemy = SpawnEnemy(player.level, Area::FOREST);
        Battle(player, enemy);

        if (player.hitPoints <= 0) break;

        std::cout << "\n1. Continue deeper into the forest" << std::endl;
        std::cout << "2. Return to Main Menu"               << std::endl;
        std::cout << "Choice --> ";
        std::cin >> choice;

        while (choice != "1" && choice != "2") {
            std::cout << "Invalid input. Enter 1 or 2 --> ";
            std::cin >> choice;
        }

        if (choice == "2") break;
    }
}

// ============================================================
//  SAVAŞ
// ============================================================
void GameManager::Battle(Liver& player, Liver& enemy) {
    std::cout << "\n--- BATTLE STARTED ---" << std::endl;
    std::cout << "A wild " << enemy.name << " appears!" << std::endl;

    while (player.hitPoints > 0 && enemy.hitPoints > 0) {
        std::cout << "\nPlayer HP: " << player.hitPoints
                  << "  |  " << enemy.name << " HP: " << enemy.hitPoints << std::endl;
        std::cout << "Your turn! Press Enter to attack...";
        std::cin.ignore();
        std::cin.get();

        int playerRoll = player.RollD20();
        std::cout << "You rolled a " << playerRoll << "!" << std::endl;

        if      (playerRoll < 3)  std::cout << "Oof! A terrible strike."     << std::endl;
        else if (playerRoll > 18) std::cout << "Incredible! A critical blow!" << std::endl;

        int playerDamage = playerRoll + player.weapon.AttackPoints;
        std::cout << "You deal " << playerDamage << " damage to " << enemy.name << "!" << std::endl;
        enemy.hitPoints -= playerDamage;

        if (enemy.hitPoints <= 0) {
            std::cout << "\n>>> You defeated the " << enemy.name << "! <<<" << std::endl;

            int xpGained = 25 + (enemy.level * 5);
            player.exp  += xpGained;
            std::cout << "You gained " << xpGained << " EXP! (Total: " << player.exp << ")" << std::endl;

            if (player.exp >= player.level * 100) {
                player.level++;
                std::cout << "========================================" << std::endl;
                std::cout << "LEVEL UP! You are now Level " << player.level << "!" << std::endl;
                std::cout << "========================================" << std::endl;
            }
            break;
        }

        std::cout << "\n" << enemy.name << "'s turn!" << std::endl;
        int enemyRoll   = enemy.RollD20();
        int enemyDamage = enemyRoll - player.armor.DefensePoints;
        if (enemyDamage < 0) enemyDamage = 0;

        std::cout << enemy.name << " rolled " << enemyRoll
                  << " and deals " << enemyDamage << " damage!" << std::endl;
        player.hitPoints -= enemyDamage;

        if (player.hitPoints <= 0) {
            std::cout << "You were defeated by the " << enemy.name << "..." << std::endl;
            std::cout << "GAME OVER!" << std::endl;
        }
    }
}
