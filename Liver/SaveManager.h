#pragma once

#include <string>
#include "Characters.h"

class SaveManager {
public:
    // Oyuncuyu dosyaya yazar
    void SavePlayer(const Liver& player, const std::string& filename);

    // Dosyadan oyuncuyu okur, başarılıysa true döner
    bool LoadPlayer(Liver& player, const std::string& filename);
};