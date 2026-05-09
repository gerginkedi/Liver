#include "Characters.h"
#include <iostream>
#include "GameManager.h"
#include <ctime> // time icin gerekli
#include <cstdlib> // srand icin gerekli

int main()
{
    // Rastgele sayı üretecinin başlangıç noktasını (seed) o anki saate göre ayarla
    srand(static_cast<unsigned int>(time(0)));

    GameManager game;

    game.startGame();

    return 0;
}