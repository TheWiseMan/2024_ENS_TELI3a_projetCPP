#pragma once
#include <vector>
#include <ncurses.h>
#include <sstream>
#include "GameView.hpp"

using namespace std;

/**
 * Design : a State machine, where transitions are user inputs and states are self sufficient for displaying
 */
class CursesInterface;

class CursesInterfaceSceneWindow
{
public:
    virtual void refresh(GameManager *mgr, CursesInterface *interface) = 0;
};

class CursesInterface : public GameView
{
public:
    void init();
    void destroy();
    void refresh(GameManager *gm);
    map<string, CursesInterfaceSceneWindow *> windows;
    WINDOW *win;
    int height = 32;
    int width = 64;
    int choice = 0;

private:
    WINDOW *screen;
};

/*class CombatWindow : public CursesInterfaceSceneWindow
{
public:
    CombatWindow(CursesInterface *interface);
    void refresh(GameManager *mgr, CursesInterface *interface);
};*/

class DialogWindow : public CursesInterfaceSceneWindow
{
public:
    DialogWindow();
    void refresh(GameManager *mgr, CursesInterface *interface);
};