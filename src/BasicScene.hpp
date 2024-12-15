#include "GameScene.hpp"
#include "UserInterface.hpp"

class DialogScene : public Scene
{
public:
    void activate(GameManager *gm);
};

class CombatScene : public Scene
{
    void activate(GameManager *gm);
};