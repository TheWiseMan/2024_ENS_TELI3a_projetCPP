#pragma once

class GameManager;
class UserInterface;

#include "GameConfig.hpp"
#include "Entity.hpp"
#include "UserInterface.hpp"

class GameManager
{
public:
    GameConfig config = GameConfig();
    EntityLibrary *entityLibrary;
    UserInterface *interface;
    void load();
    /**Careful !! Blocking function */
    void start();
    void end();
    // void gameStart();
};