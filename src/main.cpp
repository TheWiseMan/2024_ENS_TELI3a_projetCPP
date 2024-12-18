#define version "0.0.7"

#include <filesystem>
#include <fstream>

#include "Utils.hpp"
#include "UserInterface.hpp"
#include "GameManager.hpp"

#include "BasicSceneFactory.hpp"
using namespace std;

const map<string, SceneFactory *> SCENE_FACTORIES = {
    {"dialog", new DialogSceneFactory()},
    {"combat", new CombatSceneFactory()},
    {"characterSelection", new characterSelectionSceneFactory()}};

const map<string, EntityFactory *> ENTITY_FACTORIES = {
    {"simpleEntity", new SimpleEntityFactory()},
    {"playable", new PlayerEntityFactory()},
    {"healerPlayable", new HealerPlayerEntityFactory()}};

int main(int argc, char const *argv[])
{
    CursesInterface ihm;

    ihm.windows["dialog"] = new DialogWindow();
    ihm.windows["combat"] = new CombatWindow();
    ihm.windows["characterSelection"] = new CharacterSelectionWindow();

    GameManager gm;
    gm.interface = &ihm;
    gm.sceneFactories = SCENE_FACTORIES;
    gm.entityFactories = ENTITY_FACTORIES;

    gm.events["goto"] = new ChangeSceneEvent();
    gm.events["endgame"] = new EndGameEvent();
    gm.events["attack"] = new AttackEnemyEvent();
    gm.events["regen"] = new RegeneratePlaverEvent();
    gm.events["buffatk"] = new BuffAtkEvent();

    try
    {
        gm.load();
        gm.start();
        gm.end();
    }
    catch (const std::exception &e)
    {
        endwin();
        std::cerr << e.what() << '\n';
    }

    return 0;
}
