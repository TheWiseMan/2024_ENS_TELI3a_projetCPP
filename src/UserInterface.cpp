#include "UserInterface.hpp"

InterfaceWindow::InterfaceWindow() {};

InterfaceWindow::InterfaceWindow(UserInterface interface, int _width = 64, int _height = 32)
{
    this->width = _width;
    this->height = _height;
    this->win = newwin(this->height, this->width, this->top, this->left);
    keypad(win, TRUE);
    box(win, 0, 0);
}

UserInterface::UserInterface()
{
    this->init();
}

void UserInterface::init()
{
    setlocale(LC_ALL, "");
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(FALSE);
}

void UserInterface::refresh(GameManager mgr)
{
    this->windows[this->currentWindow]->refresh(mgr, this);
    wrefresh(this->windows[this->currentWindow]->win);
}

MainWindow::MainWindow(UserInterface i)
{
    getmaxyx(stdscr, this->height, this->width);
    this->win = newwin(this->height, this->width, this->top, this->left);
    keypad(win, TRUE);
    box(win, 0, 0);
}

void MainWindow::refresh(GameManager mgr, UserInterface *interface)
{
    box(this->win, 0, 0);
    // mvwprintw(win, 0, 2, "Salut les jeunes");
    int maxHP = 20;
    int hp = 3;
    int mp = 4;
    int maxMP = 10;

    mvwprintw(win, 1, 1, "HP ");
    for (int i = 0; i < maxHP; i++)
    {
        if (i < hp)
        {
            wprintw(win, "▰");
        }
        else
        {
            wprintw(win, "▱");
        }
    }
    mvwprintw(win, 2, 1, "MP ");
    for (int i = 0; i < maxMP; i++)
    {
        if (i < mp)
        {
            wprintw(win, "▰");
        }
        else
        {
            wprintw(win, "▱");
        }
    }

    int nChoices = 3;
    string choices[nChoices] = {
        "FIGHT",
        "SKILL",
        "ITEM"};

    for (int i = 0; i < nChoices; i++)
    {
        if (i == this->choice)
        {
            wattron(this->win, A_REVERSE);
            mvwprintw(win, 4 + i, 1, "\t%-20s ", choices[i].c_str());
            wattroff(this->win, A_REVERSE);
            continue;
        }
        mvwprintw(win, 4 + i, 1, "\t%-20s ", choices[i].c_str());
    }

    mvwprintw(win, this->height / 2, 2, "Salut à tous");

    // whline(this->win, '─', 4);

    // int c = wgetch(win);
    mvwprintw(win, this->height - 5, 1, " (▲/▼):\tChoose Option");
    mvwprintw(win, this->height - 4, 1, " (Enter):\tSelect option");
    mvwprintw(win, this->height - 3, 1, " (E):\t\tInventory");
    mvwprintw(win, this->height - 2, 1, " (S):\t\tCharacter sheet");
    int c = wgetch(win);
    if (c == KEY_UP)
    {
        this->choice--;
    }
    if (c == KEY_DOWN)
    {
        this->choice++;
    }
    this->choice = (this->choice + nChoices) % nChoices;
    mvwprintw(win, this->height / 2, this->width / 2, "%3d (%c)  ", c, c);
}