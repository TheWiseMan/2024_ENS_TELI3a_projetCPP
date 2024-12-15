#include "BasicSceneFactory.hpp"
#include "BasicScene.hpp"

Scene *DialogSceneFactory::create(objectlist config, GameManager *gm) const
{
    cout << "Creating new dialog scene" << endl;
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