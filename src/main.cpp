#define version "0.0.7"

#include <filesystem>
#include <fstream>

#include "Utils.hpp"
#include "UserInterface.hpp"
#include "GameManager.hpp"

#include "BasicSceneFactory.hpp"
using namespace std;

const map<string, SceneFactory *> SCENE_FACTORIES = {
    {"dialog", new DialogSceneFactory()}};

int main(int argc, char const *argv[])
{
    GameManager gm;
    CursesInterface ihm;
    ihm.windows["dialog"] = new DialogWindow();
    gm.sceneFactories = SCENE_FACTORIES;
    gm.interface = &ihm;
    gm.events["goto"] = new ChangeSceneEvent();
    gm.events["endgame"] = new EndGameEvent();
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
