#pragma once

#include <string>
#include <vector>
#include "Characters.h"
#include "SaveManager.h"

enum class Area {
    VILLAGE,
    CAVE,
    FOREST
};

struct EnemyTemplate {
    std::string name;
    int minLevel;
    int maxLevel;
    int baseHP;
    int baseAttack;
    int baseDefense;
};

class GameManager {
public:
    GameManager();

    // Başlangıç ekranı — Yeni Oyun / Devam / Çıkış
    void startGame();

private:
    SaveManager saveManager;

    // --- Başlangıç ---
    void NewGame();
    void LoadGame();

    // --- Bölge Yönetimi ---
    void MainMenu(Liver& player);
    void Village(Liver& player);
    void Cave(Liver& player);
    void Forest(Liver& player);

    // --- Savaş ---
    void Battle(Liver& player, Liver& enemy);

    // --- Düşman ---
    Liver SpawnEnemy(int playerLevel, Area area);
    void  InitEnemies();

    std::vector<EnemyTemplate> caveEnemies;
    std::vector<EnemyTemplate> forestEnemies;
};