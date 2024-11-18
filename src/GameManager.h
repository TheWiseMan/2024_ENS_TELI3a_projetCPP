#pragma once

#include "GameConfig.h"
#include "Entity.h"

class GameManager
{
public:
    GameConfig config = GameConfig();
    EntityLibrary entityLibrary;
    void load();
    // void gameStart();
};