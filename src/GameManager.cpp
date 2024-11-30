#include "GameManager.hpp"

void GameManager::load()
{
    cout << "Loading game assets..." << endl;
    this->config.read();
    this->entityLibrary = new EntityLibrary();
    for (auto &&entitydef : this->config.entitiesconfig)
    {
        this->entityLibrary->add(entitydef);
    }
    cout << "Game loaded !" << endl;
    this->interface = new UserInterface();
}

void GameManager::start()
{
    MainWindow w2 = MainWindow(*this->interface);

    this->interface->windows.push_back(&w2);
    while (1)
    {
        this->interface->refresh(*this);
    }
}

void GameManager::end() {
    this->interface->destroy();
}