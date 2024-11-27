#pragma once

#include "GameConfig.hpp"
#include "Entity.hpp"

class GameManager
{
public:
    GameConfig config = GameConfig();
    EntityLibrary entityLibrary;
    void load();
    // void gameStart();
};