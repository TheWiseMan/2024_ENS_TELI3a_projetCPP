#include "UserInterface.h"

InterfaceWindow::InterfaceWindow(UserInterface interface, int _width = 64, int _height = 32)
{
    this->width = _width;
    this->height = _height;
    this->win = newwin(this->height, this->width, this->top, this->left);
    keypad(win, TRUE);
    interface.windows.push_back(*this);
    box(win, 0, 0);
}

UserInterface::UserInterface()
{
    this->init();
}

void UserInterface::init()
{
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(FALSE);
}

void UserInterface::refresh() {
    wrefresh(this->windows[this->currentWindow].win);
}