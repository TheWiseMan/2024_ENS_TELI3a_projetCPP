#include <iostream>
#include "GameScene.hpp"
#include "Utils.hpp"

Scene::~Scene() {
    
}

/**
 * Creates a scene from the given config using the global SCENE_FACTORIES
 */
Scene *Scene::fromObjectList(objectlist config, GameManager *gm)
{
    if (config.size() == 0)
    {
        cerr << "Empty scene definition" << endl;
    }
    object s = config.front();
    if (!s.count("type"))
    {
        cerr << "A scene must have a type" << endl;
    }
    if (!gm->sceneFactories.count(s.at("type")))
    {
        cerr << "Scene type '" << s.at("type") << "' not found in scene types" << endl;
    }
    return gm->sceneFactories.at(s.at("type"))->create(config, gm);
}