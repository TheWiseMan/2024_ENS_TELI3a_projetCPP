#include "GameManager.hpp"
/**
 * An event that updates the GameManager (ie, any action,
 * player related or not).
 */
class GameEvent
{
public:
    virtual int fire(GameManager *gm);
};
