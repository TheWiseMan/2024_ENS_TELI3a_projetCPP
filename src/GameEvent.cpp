#include "GameEvent.hpp"

void ChangeSceneEvent::fire(GameManager *gm, object config)
{
    delete gm->currentScene;
    gm->currentScene = Scene::fromObjectList(GoldReader::parseFile(config.at("scene")), gm);
    gm->interface->refresh(gm);
}

void AttackEnemyEvent::fire(GameManager *gm, object config)
{
    gm->currentEnemy->takeDamage(gm->playerEntity->dealDamage(gm->currentEnemy));
}

void EndGameEvent::fire(GameManager *gm, object config)
{
    gm->running = false;
}

void RegeneratePlaverEvent::fire(GameManager *gm, object config)
{
    gm->playerEntity->isAlive = true;
    gm->playerEntity->hp = gm->playerEntity->maxHP;
    gm->playerEntity->mp = gm->playerEntity->maxMP;

}