#include "GameEvent.hpp"

void ChangeSceneEvent::fire(GameManager *gm, object config) {
    delete gm->currentScene;
    gm->currentScene = Scene::fromObjectList(GoldReader::parseFile(config.at("scene")), gm);
    gm->interface->refresh(gm);
}

void EndGameEvent::fire(GameManager *gm, object config) {
    gm->running = false;
}