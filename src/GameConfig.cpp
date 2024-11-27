#include "GameConfig.hpp"

void GameConfig::read()
{
    this->entitiesconfig = ConfigReader::readEntitiesConfig("characters.gold");
}