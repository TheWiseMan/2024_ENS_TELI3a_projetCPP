#include "GameManager.hpp"
// #include "Utils.hpp"

void GameManager::load()
{
    cout << "Loading game assets..." << endl;
    this->config.read();

    // Utils::displayMap(this->config.adventureconfig);
    cout << "Game loaded !" << endl;
}

void GameManager::start()
{
    this->running = true;
    this->currentScene = Scene::fromObjectList(GoldReader::parseFile(this->config.adventureconfig.at("startingScene")), this);
    this->interface->init();
    while (this->running)
    {
        this->interface->refresh(this);
    }
}

void GameManager::end()
{
    delete this->currentScene;
    this->interface->destroy();
    cout << "Game ended !" << endl;
}

void GameManager::fireEvent(object event)
{
    if (!event.count("action"))
    {
        cerr << "Invalid event" << endl;
    }
    this->events[event.at("action")]->fire(this, event);
}