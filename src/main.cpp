#include <iostream>
#include <filesystem>
#include <fstream>

#define version "0.0.2"

#include "GoldReader.h"
#include "Utils.h"
#include "Entity.h"

using namespace std;

int main(int argc, char const *argv[])
{

    fstream characterssheet("./characters.gold");
    stringstream buffer;
    buffer << characterssheet.rdbuf();
    std::list<std::map<std::string, std::string>> result = GoldReader::parseList(buffer.str());
    characterssheet.close();


    for (auto &&item : result)
    {
        Utils::displayMap(item);
    }

    //std::cout << "Current path is " << std::filesystem::current_path().string() << std::endl;
    return 0;
}
