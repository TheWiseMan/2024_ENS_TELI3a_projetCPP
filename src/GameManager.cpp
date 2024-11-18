#include "GameManager.h"

void GameManager::load()
{
    this->config.read();
    for (auto &&entitydef : this->config.entitiesconfig)
    {
        this->entityLibrary.add(entitydef);
    }
}