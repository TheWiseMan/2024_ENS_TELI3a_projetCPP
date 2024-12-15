#include "BasicSceneFactory.hpp"
#include "BasicScene.hpp"

Scene *DialogSceneFactory::create(objectlist config, GameManager *gm) const
{
    object s = config.front();
    config.pop_front();
    if (!s.count("interlocutor"))
    {
        cerr << "A dialog scene needs an interlocutor entity" << endl;
    }
    DialogScene *scene = new DialogScene();
    scene->config = s;
    for (auto const &optionobj : config)
    {
        scene->options.push_back(optionobj);
    }
    return scene;
}

Scene *CombatSceneFactory::create(objectlist config, GameManager *gm) const
{
    object s = config.front();
    config.pop_front();
    CombatScene *scene = new CombatScene();
    scene->config = s;

    object en = config.front();
    config.pop_front();
    gm->currentEnemy = gm->entityFactories.at(en.at("type"))->create(en);

    object winaction = config.front();
    config.pop_front();
    scene->options.push_back(winaction);

    object loseaction = config.front();
    config.pop_front();
    scene->options.push_back(loseaction);
    return scene;
}

Scene *characterSelectionSceneFactory::create(objectlist config, GameManager *gm) const
{
    object s = config.front();
    config.pop_front();
    
    DialogScene *scene = new DialogScene();
    scene->config = s;
    for (auto const &optionobj : config)
    {
        scene->options.push_back(optionobj);
    }
    return scene;
}