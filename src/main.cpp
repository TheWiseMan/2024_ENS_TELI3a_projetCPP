#define version "0.0.4"

#include <iostream>
#include <filesystem>
#include <fstream>
#include <ncurses.h>

#include "Utils.h"
#include "GameManager.h"
#include "UserInterface.h"

using namespace std;

int main(int argc, char const *argv[])
{

    /*fstream characterssheet("./characters.gold");
    stringstream buffer;
    buffer << characterssheet.rdbuf();
    objectlist result = GoldReader::parseList(buffer.str());
    characterssheet.close();

    Utils::displayMapList(result);*/

    GameManager gm;
    gm.load();
    Entity t = gm.entityLibrary.create("WiseMan");
    gm.entityLibrary.debug();
    cout << t.def << endl;

    int c;

    UserInterface i = UserInterface();
    InterfaceWindow w2 = InterfaceWindow(i, 60, 20);
    InterfaceWindow w = InterfaceWindow(i, 50, 2);
    cout << w.height << endl;
    mvwprintw(w.win, 0, 2, "Greeter");
    bool out = false;
    while (!out)
    {
        c = wgetch(w.win);
        //wrefresh(w.win);//i.refresh();
        //wrefresh(i.windows[0].win);
        switch (c)
        {
        default:
            mvwprintw(w.win, 0, 0, "%c", c);
            out = true;
            break;
        }
    }
    clrtoeol();
    refresh();
    endwin();
    cout << c << endl;
    // WINDOW *menu_win = i.menu_win;

    // mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
    // refresh();
    // print_menu(menu_win, highlight);
    // while (1)
    // {
    //     c = wgetch(menu_win);
    //     switch (c)
    //     {
    //     case KEY_UP:
    //         if (highlight == 1)
    //             highlight = n_choices;
    //         else
    //             --highlight;
    //         break;
    //     case KEY_DOWN:
    //         if (highlight == n_choices)
    //             highlight = 1;
    //         else
    //             ++highlight;
    //         break;
    //     case 10:
    //         choice = highlight;
    //         break;
    //     default:
    //         mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", c, c);
    //         refresh();
    //         break;
    //     }
    //     print_menu(menu_win, highlight);
    //     if (choice != 0) /* User did a choice come out of the infinite loop */
    //         break;
    // }
    // mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
    // clrtoeol();
    // refresh();
    // endwin();

    // std::cout << "Current path is " << std::filesystem::current_path().string() << std::endl;
    return 0;
}

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
//             mvwprintw(menu_win, y, x, "%s", choices[i]);
//             wattroff(menu_win, A_REVERSE);
//         }
//         else
//             mvwprintw(menu_win, y, x, "%s", choices[i]);
//         ++y;
//     }
//     wrefresh(menu_win);
// }
