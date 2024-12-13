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

void UserInterface::destroy()
{
    clrtoeol();
    endwin();
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

void printLeftAlignedText(WINDOW *win, int yoffset, int xoffset, string text)
{

    std::stringstream ss(text);
    std::string to;

    int y = yoffset;
    while (std::getline(ss, to, '\n'))
    {
        mvwprintw(win, y++, xoffset, "%s", to.c_str());
    }
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
        "ATTACK",
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

    printLeftAlignedText(win, 2, this->width/2, "                           .oMc\n                        .MMMMMP\n                      .MM888MM\n....                .MM88888MP\nMMMMMMMMb.         d8MM8tt8MM\n MM88888MMMMc `:' dMME8ttt8MM\n  MM88tt888EMMc:dMM8E88tt88MP\n   MM8ttt888EEM8MMEEE8E888MC\n   `MM888t8EEEM8MMEEE8t8888Mb\n    \"MM88888tEM8\"MME88ttt88MM\n     dM88ttt8EM8\"MMM888ttt8MM\n     MM8ttt88MM\" \" \"MMNICKMM\"\n     3M88888MM\"      \"MMMP\"\n      \"MNICKM\"\n");

    printLeftAlignedText(win, this->height / 2, 2, "Salut à tous\nComment ça va ?");

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