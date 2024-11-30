#pragma once
#include <vector>
#include <ncurses.h>
#include "GameManager.hpp"

using namespace std;

class InterfaceWindow;

/**
 * Design : a State machine, where transitions are user inputs and states are self sufficient for displaying
 */

class UserInterface
{
public:
    UserInterface();
    void init();
    void destroy();
    int currentWindow = 0;
    vector<InterfaceWindow *> windows;
    void refresh(GameManager mgr);
};

class InterfaceWindow
{
public:
    int top = 0;
    int left = 0;
    int width = 64;
    int height = 32;
    InterfaceWindow();
    InterfaceWindow(UserInterface interface, int _width, int _height);
    WINDOW *win;
    virtual void refresh(GameManager mgr, UserInterface *interface) = 0;
};

#define WIDTH 50
#define HEIGHT 10

class MainWindow : public InterfaceWindow
{
public:
    int choice = 0;
    MainWindow(UserInterface interface);
    void refresh(GameManager mgr, UserInterface *interface);
};