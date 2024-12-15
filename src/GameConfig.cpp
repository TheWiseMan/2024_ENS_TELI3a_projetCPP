#include "GameConfig.hpp"
#include <iostream>

using namespace std;

void GameConfig::read()
{
    this->adventureconfig = GoldReader::parseFile("adventure.gold").front();

    if (!this->adventureconfig.count("entities")) {
        cerr << "An adventure must have an entitymap" << endl;
        exit(1);
    }
    if (!this->adventureconfig.count("startingScene")) {
        cerr << "An adventure must have a startingScene" << endl;
        exit(1);
    }
    //cout << this->adventureconfig.at("entities") << endl;
    //this->entitiesconfig = GoldReader::parseFile(this->adventureconfig.at("entities"));
}