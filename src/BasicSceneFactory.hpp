#include "GameScene.hpp"

class DialogSceneFactory : public SceneFactory
{
public:
    Scene *create(objectlist config, GameManager *gm) const;
};

class CombatSceneFactory : public SceneFactory
{
public:
    Scene *create(objectlist config, GameManager *gm) const;
};

class characterSelectionSceneFactory : public SceneFactory
{
public:
    Scene *create(objectlist config, GameManager *gm) const;
};