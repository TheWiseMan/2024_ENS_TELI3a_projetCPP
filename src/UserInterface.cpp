#include "UserInterface.hpp"

void CursesInterface::init()
{
    setlocale(LC_ALL, "");
    this->screen = initscr();
    clear();
    noecho();
    cbreak();
    curs_set(FALSE);
    getmaxyx(stdscr, this->height, this->width);
    this->win = newwin(this->height, this->width, 0, 0);
    keypad(win, TRUE);
    box(win, 0, 0);
}

void CursesInterface::destroy()
{
    delwin(this->win);
    clrtoeol();
    endwin();
}

void CursesInterface::refresh(GameManager *gm)
{
    string scene_type = gm->currentScene->config.at("type");
    if (!this->windows.count(scene_type))
    {
        cerr << "No renderer found for scene type : '" << scene_type << "'" << endl;
    }
    this->windows.at(scene_type)->refresh(gm, this);
}

void printLeftAlignedText(WINDOW *win, int yoffset, int xoffset, string text)
{

    stringstream ss(text);
    string to;

    int y = yoffset;
    while (std::getline(ss, to, '\n'))
    {
        mvwprintw(win, y++, xoffset, "%s", to.c_str());
    }
}

/*void CombatWindow::refresh(GameManager mgr, CursesInterface *interface)
{
    box(interface->win, 0, 0);
    // mvwprintw(win, 0, 2, "Salut les jeunes");
    int maxHP = 20;
    int hp = 3;
    int mp = 4;
    int maxMP = 10;

    mvwprintw(interface->win, 1, 1, "HP ");
    for (int i = 0; i < maxHP; i++)
    {
        if (i < hp)
        {
            wprintw(interface->win, "▰");
        }
        else
        {
            wprintw(interface->win, "▱");
        }
    }
    mvwprintw(interface->win, 2, 1, "MP ");
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
            wattron(interface->win, A_REVERSE);
            mvwprintw(interface->win, 4 + i, 1, "\t%-20s ", choices[i].c_str());
            wattroff(interface->win, A_REVERSE);
            continue;
        }
        mvwprintw(interface->win, 4 + i, 1, "\t%-20s ", choices[i].c_str());
    }

    printLeftAlignedText(interface->win, 2, interface->width / 2, "                           .oMc\n                        .MMMMMP\n                      .MM888MM\n....                .MM88888MP\nMMMMMMMMb.         d8MM8tt8MM\n MM88888MMMMc `:' dMME8ttt8MM\n  MM88tt888EMMc:dMM8E88tt88MP\n   MM8ttt888EEM8MMEEE8E888MC\n   `MM888t8EEEM8MMEEE8t8888Mb\n    \"MM88888tEM8\"MME88ttt88MM\n     dM88ttt8EM8\"MMM888ttt8MM\n     MM8ttt88MM\" \" \"MMNICKMM\"\n     3M88888MM\"      \"MMMP\"\n      \"MNICKM\"\n");

    printLeftAlignedText(interface->win, interface->width / 2, 2, "Salut à tous\nComment ça va ?");

    // whline(this->win, '─', 4);

    // int c = wgetch(win);
    mvwprintw(interface->win, interface->height - 5, 1, " (▲/▼):\tChoose Option");
    mvwprintw(interface->win, interface->height - 4, 1, " (Enter):\tSelect option");
    mvwprintw(interface->win, interface->height - 3, 1, " (E):\t\tInventory");
    mvwprintw(interface->win, interface->height - 2, 1, " (S):\t\tCharacter sheet");
    int c = wgetch(interface->win);
    if (c == KEY_UP)
    {
        this->choice--;
    }
    if (c == KEY_DOWN)
    {
        this->choice++;
    }
    this->choice = (this->choice + nChoices) % nChoices;
    mvwprintw(interface->win, interface->height / 2, interface->width / 2, "%3d (%c)  ", c, c);
    if (c == 10)
    {
        mvwprintw(interface->win, interface->height / 2, interface->width / 2, "%s", choices[this->choice].c_str());
    }
}*/

void CombatWindow::refresh(GameManager *mgr, CursesInterface *interface)
{
    wclear(interface->win);
    box(interface->win, 0, 0);
    object scene_conf = mgr->currentScene->config;
    vector<object> outcomes = mgr->currentScene->options;
    auto actions = mgr->playerEntity->actions;
    int nChoices = actions->size();
    interface->choice = (interface->choice + nChoices) % nChoices;
    printLeftAlignedText(interface->win, 0, 5, scene_conf.at("displayname"));
    mvwprintw(interface->win, 2, 1, "HP ");
    for (int i = 0; i < mgr->playerEntity->maxHP; i++)
    {
        if (i < mgr->playerEntity->hp)
        {
            wprintw(interface->win, "▰");
        }
        else
        {
            wprintw(interface->win, "▱");
        }
    }
    mvwprintw(interface->win, 3, 1, "MP ");
    for (int i = 0; i < mgr->playerEntity->maxMP; i++)
    {
        if (i < mgr->playerEntity->mp)
        {
            wprintw(interface->win, "▰");
        }
        else
        {
            wprintw(interface->win, "▱");
        }
    }

    mvwprintw(interface->win, 2, interface->width / 2, "HP ");
    for (int i = 0; i < mgr->currentEnemy->maxHP; i++)
    {
        if (i < mgr->currentEnemy->hp)
        {
            wprintw(interface->win, "▰");
        }
        else
        {
            wprintw(interface->win, "▱");
        }
    }
    mvwprintw(interface->win, 3, interface->width / 2, "MP ");
    for (int i = 0; i < mgr->currentEnemy->maxMP; i++)
    {
        if (i < mgr->currentEnemy->mp)
        {
            wprintw(interface->win, "▰");
        }
        else
        {
            wprintw(interface->win, "▱");
        }
    }

    int i = 0;
    for (const auto &a : *actions)
    {
        if (i == interface->choice)
        {
            wattron(interface->win, A_REVERSE);
            mvwprintw(interface->win, 4 + i, 1, "\t%-20s ", a->getName().c_str());
            wattroff(interface->win, A_REVERSE);
            i++;
            continue;
        }
        mvwprintw(interface->win, 4 + i, 1, "\t%-20s ", a->getName().c_str());
        i++;
    }

    wattron(interface->win, A_BOLD);
    printLeftAlignedText(interface->win, 1, 1, mgr->playerEntity->name);
    wattroff(interface->win, A_BOLD);
    wattron(interface->win, A_BOLD);
    printLeftAlignedText(interface->win, 1, interface->width / 2, mgr->currentEnemy->name);
    wattroff(interface->win, A_BOLD);
    printLeftAlignedText(interface->win, interface->height / 2, 1, scene_conf.at("text"));

    mvwprintw(interface->win, interface->height - 5, 1, " (▲/▼):\tChoose Option");
    mvwprintw(interface->win, interface->height - 4, 1, " (Enter):\tSelect option");
    // mvwprintw(interface->win, interface->height - 3, 1, " (E):\t\tInventory");
    // mvwprintw(interface->win, interface->height - 2, 1, " (S):\t\tCharacter sheet");

    int c = wgetch(interface->win);
    if (c == KEY_UP)
    {
        interface->choice--;
    }
    if (c == KEY_DOWN)
    {
        interface->choice++;
    }
    interface->choice = (interface->choice + nChoices) % nChoices;
    if (c == 10)
    {
        actions->at(interface->choice)->execute(mgr, mgr->playerEntity, {});
        if (!mgr->currentEnemy->isAlive)
        {
            mgr->fireEvent(outcomes[0]);
            return;
        }
        mgr->currentEnemy->actions->at(0)->execute(mgr, mgr->currentEnemy, {});
        if (!mgr->playerEntity->isAlive)
        {
            mgr->fireEvent(outcomes[1]);
            return;
        }
        // mvwprintw(win, this->height / 2, this->width / 2, "%s", choices[this->choice].c_str());
        // mgr->fireEvent(options[interface->choice]);
    }
}

void DialogWindow::refresh(GameManager *mgr, CursesInterface *interface)
{
    wclear(interface->win);
    box(interface->win, 0, 0);
    object scene_conf = mgr->currentScene->config;
    vector<object> options = mgr->currentScene->options;
    int nChoices = options.size();
    interface->choice = (interface->choice + nChoices) % nChoices;
    printLeftAlignedText(interface->win, 0, 5, scene_conf.at("displayname"));
    int i = 0;
    for (auto &c : options)
    {
        if (i == interface->choice)
        {
            wattron(interface->win, A_REVERSE);
            mvwprintw(interface->win, interface->height / 2 + i, 1, "\t%-20s ", c.at("name").c_str());
            wattroff(interface->win, A_REVERSE);
            i++;
            continue;
        }
        mvwprintw(interface->win, interface->height / 2 + i, 1, "\t%-20s ", c.at("name").c_str());
        i++;
    }
    wattron(interface->win, A_BOLD);
    printLeftAlignedText(interface->win, 1, 1, scene_conf.at("interlocutor"));
    wattroff(interface->win, A_BOLD);
    printLeftAlignedText(interface->win, 2, 4, scene_conf.at("text"));

    mvwprintw(interface->win, interface->height - 5, 1, " (▲/▼):\tChoose Option");
    mvwprintw(interface->win, interface->height - 4, 1, " (Enter):\tSelect option");
    // mvwprintw(interface->win, interface->height - 3, 1, " (E):\t\tInventory");
    // mvwprintw(interface->win, interface->height - 2, 1, " (S):\t\tCharacter sheet");

    int c = wgetch(interface->win);
    if (c == KEY_UP)
    {
        interface->choice--;
    }
    if (c == KEY_DOWN)
    {
        interface->choice++;
    }
    interface->choice = (interface->choice + nChoices) % nChoices;
    if (c == 10)
    {
        // mvwprintw(win, this->height / 2, this->width / 2, "%s", choices[this->choice].c_str());
        mgr->fireEvent(options[interface->choice]);
    }
}

void CharacterSelectionWindow::refresh(GameManager *mgr, CursesInterface *interface) {

    wclear(interface->win);
    box(interface->win, 0, 0);
    object scene_conf = mgr->currentScene->config;
    vector<object> options = mgr->currentScene->options;
    int nChoices = options.size();
    interface->choice = (interface->choice + nChoices) % nChoices;
    printLeftAlignedText(interface->win, 0, 5, scene_conf.at("displayname"));
    int i = 0;
    for (auto &c : options)
    {
        if (i == interface->choice)
        {
            wattron(interface->win, A_REVERSE);
            mvwprintw(interface->win, interface->height / 2 + i, 1, "\t%-20s ", c.at("name").c_str());
            wattroff(interface->win, A_REVERSE);
            i++;
            continue;
        }
        mvwprintw(interface->win, interface->height / 2 + i, 1, "\t%-20s ", c.at("name").c_str());
        i++;
    }
    wattron(interface->win, A_BOLD);
    printLeftAlignedText(interface->win, 1, 1, scene_conf.at("displayname"));
    wattroff(interface->win, A_BOLD);
    printLeftAlignedText(interface->win, 2, 4, scene_conf.at("text"));
    printLeftAlignedText(interface->win, 2, interface->width/2, options[interface->choice].at("description"));

    mvwprintw(interface->win, interface->height - 5, 1, " (▲/▼):\tChoose Option");
    mvwprintw(interface->win, interface->height - 4, 1, " (Enter):\tSelect option");
    // mvwprintw(interface->win, interface->height - 3, 1, " (E):\t\tInventory");
    // mvwprintw(interface->win, interface->height - 2, 1, " (S):\t\tCharacter sheet");

    int c = wgetch(interface->win);
    if (c == KEY_UP)
    {
        interface->choice--;
    }
    if (c == KEY_DOWN)
    {
        interface->choice++;
    }
    interface->choice = (interface->choice + nChoices) % nChoices;
    if (c == 10)
    {
        // mvwprintw(win, this->height / 2, this->width / 2, "%s", choices[this->choice].c_str());
        mgr->playerEntity = mgr->entityFactories.at(options[interface->choice].at("type"))->create(options[interface->choice]);
        mgr->fireEvent(options[interface->choice]);
    }
}