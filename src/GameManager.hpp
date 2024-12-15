#pragma once

class GameManager;
class Scene;
class SceneFactory;
class GameEvent;
class GameView;
class Entity;
class EntityFactory;

#include "GameView.hpp"
#include "GameScene.hpp"
#include "GameConfig.hpp"
#include "Entity.hpp"
#include "GameEvent.hpp"

class GameManager
{
public:
    GameConfig config;
    map<string, SceneFactory *> sceneFactories;
    map<string, EntityFactory *> entityFactories;
    Scene *currentScene;
    GameView *interface;
    map<string, GameEvent *> events;
    Entity *playerEntity;
    Entity *currentEnemy;
    bool running = false;
    void fireEvent(object event);
    void load();
    /**Careful !! Blocking function */
    void start();
    void end();
    // void gameStart();
};