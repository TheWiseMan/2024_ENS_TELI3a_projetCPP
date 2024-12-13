#include <iostream>
#include "GameScene.hpp"

Scene SceneFactory::create(object config) const {
    cout << "Hello" <<endl;
    return Scene();
}

Scene StorySceneFactory::create(object config) const {
    cout << "Salut" <<endl;
    return Scene();
}