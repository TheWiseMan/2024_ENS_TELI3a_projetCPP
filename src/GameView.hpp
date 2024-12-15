#pragma once
#include "GameManager.hpp"

class GameView
{
public:
    virtual void init() = 0;
    virtual void refresh(GameManager *gm) = 0;
    virtual void destroy() = 0;
};