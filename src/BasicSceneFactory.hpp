#include "GameScene.hpp"

class DialogSceneFactory : public SceneFactory
{
public:
    Scene *create(objectlist config, GameManager *gm) const;
};