#define version "0.0.7"

#include <filesystem>

#include "Utils.hpp"
#include "GameManager.hpp"
#include "GameScene.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    GameManager gm;
    gm.load();
    //gm.start();
    gm.end();

    const map<string, string> c = {};

    SCENE_FACTORIES.at("story")->create(c);

    //std::cout << "Current path is " << std::filesystem::current_path().string() << std::endl;
    return 0;
}
