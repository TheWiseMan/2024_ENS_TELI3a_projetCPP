#include <vector>
#include <ncurses.h>

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
    int currentWindow = 0;
    vector<InterfaceWindow> windows = {};
    void refresh();
};

class InterfaceWindow
{
public:
    int top = 0;
    int left = 0;
    int width = 64;
    int height = 32;
    InterfaceWindow(UserInterface interface, int _width, int _height);
    WINDOW *win;
};

#define WIDTH 50
#define HEIGHT 10