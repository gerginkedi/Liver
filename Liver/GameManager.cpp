#include "GameManager.h"
#include <iostream>

void GameManager::Battle(Liver& player, Liver& enemy) {
    std::cout << "\n--- BATTLE STARTED ---" << std::endl;
    std::cout << "A wild " << enemy.name << " appears!" << std::endl;

    while (player.hitPoints > 0 && enemy.hitPoints > 0) {
        std::cout << "\nPlayer HP: " << player.hitPoints << " | " << enemy.name << " HP: " << enemy.hitPoints << std::endl;
        std::cout << "Your turn! Press Enter to roll D20 and attack...";
        std::cin.ignore();
        std::cin.get();

        int playerRoll = player.RollD20();
        std::cout << "You rolled a " << playerRoll << "!" << std::endl;

        if (playerRoll < 3) {
            std::cout << "Oof! A terrible strike. You barely hit anything." << std::endl;
        } else if (playerRoll > 18) {
            std::cout << "Incredible! A devastating critical blow!" << std::endl;
        }

        int playerDamage = playerRoll + player.weapon.AttackPoints;
        std::cout << "You deal " << playerDamage << " damage to " << enemy.name << "!" << std::endl;
        enemy.hitPoints -= playerDamage;

        if (enemy.hitPoints <= 0) {
            std::cout << "\n>>> You defeated the " << enemy.name << "! <<<" << std::endl;

            // Experience Point Gain
            int xpGained = 25; // Örnek olarak 25 exp veriyoruz
            player.exp += xpGained;
            std::cout << "You gained " << xpGained << " EXP! (Total EXP: " << player.exp << ")" << std::endl;

            // ÇOK BASİT LEVEL UP MEKANİĞİ
            if (player.exp >= player.level * 100) {
                player.level++;
                std::cout << "========================================" << std::endl;
                std::cout << "LEVEL UP! You are now Level " << player.level << "!" << std::endl;
                std::cout << "========================================" << std::endl;
            }
            break;
        }

        std::cout << "\n" << enemy.name << "'s turn!" << std::endl;
        int enemyRoll = enemy.RollD20();
        std::cout << enemy.name << " rolled a " << enemyRoll << "!" << std::endl;

        int enemyDamage = enemyRoll - player.armor.DefensePoints;
        if (enemyDamage < 0) enemyDamage = 0; // negatif hasar 0 a dönüşüyo

        std::cout << enemy.name << " deals " << enemyDamage << " damage to you!" << std::endl;
        player.hitPoints -= enemyDamage;

        if (player.hitPoints <= 0) {
            std::cout << "You were defeated by the " << enemy.name << "..." << std::endl;
            std::cout << "GAME OVER!" << std::endl;
            break;
        }
    }
}

void GameManager::startGame() {
	Liver player;
	std::cout << "Enter character name:";
	std::cin >> player.name;
 
	player = Liver::MakeLiverReadyToPlay(player);

	std::cout << "Your character " << player.name << " has been created with the following stats:" << std::endl;
	std::cout << "Will: " << player.stats.will << std::endl;
	std::cout << "Strength: " << player.stats.strength << std::endl;
	std::cout << "Dexterity: " << player.stats.dexterity << std::endl;
	std::cout << "Constitution: " << player.stats.constitution << std::endl;
	std::cout << "Charisma: " << player.stats.charisma << std::endl;

	// player starting values
	player.hitPoints = 30 + player.stats.constitution * 2; // hp calc 
	player.weapon.Name = "Iron Sword";
	player.weapon.AttackPoints = 3 + (player.stats.strength + player.stats.dexterity)/7;
	player.armor.Name = "Leather Armor";
    player.armor.DefensePoints = 3 + player.stats.strength/10;

	
	Liver enemy;
	enemy.name = "Goblin";
	enemy.hitPoints = 30;
	enemy.weapon.AttackPoints = 5;

	// Hikaye kısmı
	std::cout << "\n--------------------------------------------------" << std::endl;
	std::cout << "After preparing your gear, you step out into the dark forest." << std::endl;
	std::cout << "The trees are thick, and the air is cold. You hear rustling in the bushes..." << std::endl;
	std::cout << "Suddenly, a vicious creature jumps right out of the shadows!" << std::endl;
	std::cout << "It's a " << enemy.name << " blocking your path!" << std::endl;
	std::cout << "--------------------------------------------------\n" << std::endl;

	// Start Battle
	Battle(player, enemy);
}
