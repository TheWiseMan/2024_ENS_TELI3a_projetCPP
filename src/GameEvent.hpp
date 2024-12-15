#pragma once
#include "GameManager.hpp"
/**
 * An event that updates the GameManager (ie, any action,
 * player related or not).
 */
class GameEvent
{
public:
    virtual void fire(GameManager *gm, object config) = 0;
};

class ChangeSceneEvent : public GameEvent
{
public:
    void fire(GameManager *gm, object config);
};

class AttackEnemyEvent : public GameEvent {
public:
    void fire(GameManager *gm, object config);
};

class EndGameEvent : public GameEvent
{
public:
    void fire(GameManager *gm, object config);
};