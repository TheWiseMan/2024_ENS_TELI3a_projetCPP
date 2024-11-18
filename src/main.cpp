#include <iostream>
#include <filesystem>
#include <fstream>

#define version "0.0.2"

#include "Utils.h"
#include "GameManager.h"

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
    gm.entityLibrary.debug();
    

    // std::cout << "Current path is " << std::filesystem::current_path().string() << std::endl;
    return 0;
}
