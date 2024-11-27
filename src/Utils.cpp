#include "Utils.hpp"

using namespace std;

namespace Utils
{
    void displayMap(map<string, string> map)
    {
        cout << "{" << endl;
        for (auto &&entry : map)
        {
            cout << "\t'" << entry.first + "' : '" + entry.second << "'" << endl;
        }
        cout << "}" << endl;
    }
    void displayMapList(list<map<string, string>> list)
    {
        for (auto &&item : list)
        {
            Utils::displayMap(item);
        }
    }
};
