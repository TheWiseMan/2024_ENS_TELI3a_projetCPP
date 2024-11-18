#include "Utils.h"

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
};
