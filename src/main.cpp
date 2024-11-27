#define version "0.0.4"

#include <iostream>
#include <filesystem>
#include <fstream>
#include <ncurses.h>

#include "Utils.hpp"
#include "GameManager.hpp"
#include "UserInterface.hpp"

using namespace std;

// string choices[] = {
//     "salut",
//     "les",
//     "jeunes"};

// int n_choices = 3;

// void print_menu(WINDOW *menu_win, int highlight)
// {
//     int x, y, i;

//     x = 2;
//     y = 2;
//     box(menu_win, 0, 0);
//     for (i = 0; i < n_choices; ++i)
//     {
//         if (highlight == i + 1) /* High light the present choice */
//         {
//             wattron(menu_win, A_REVERSE);
//             mvwprintw(menu_win, y, x, "%s", choices[i].c_str());
//             wattroff(menu_win, A_REVERSE);
//         }
//         else
//             mvwprintw(menu_win, y, x, "%s", choices[i].c_str());
//         ++y;
//     }
//     wrefresh(menu_win);
// }

int main(int argc, char const *argv[])
{
    GameManager gm;
    gm.load();
    Entity t = gm.entityLibrary.create("WiseMan");
    gm.entityLibrary.debug();
    cout << t.def << endl;

    UserInterface i = UserInterface();
    MainWindow w2 = MainWindow(i);

    //WINDOW *menu_win = w2.win;
    i.windows.push_back(&w2);
    // wrefresh(i.windows[i.currentWindow]->win);
    // print_menu(menu_win, highlight);
    // mvwprintw(menu_win, 0, 1, "Use arrow keys to go up and down");
    while (1)
    {
        i.refresh(gm);
    }
    // mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
    clrtoeol();
    refresh();
    endwin();

    std::cout << "Current path is " << std::filesystem::current_path().string() << std::endl;
    return 0;
}
