#include "GameManager.hpp"

void GameManager::load()
{
    cout << "Loading game assets..." << endl;
    this->config.read();
    for (auto &&entitydef : this->config.entitiesconfig)
    {
        this->entityLibrary.add(entitydef);
    }
    cout << "Game loaded !" << endl;
}