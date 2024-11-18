#include "GameConfig.h"

void GameConfig::read()
{
    this->entitiesconfig = ConfigReader::readEntitiesConfig("characters.gold");
}