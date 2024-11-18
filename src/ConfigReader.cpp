#include "ConfigReader.h"

objectlist ConfigReader::readEntitiesConfig(string filename) {
    fstream characterssheet("./characters.gold");
    stringstream buffer;
    buffer << characterssheet.rdbuf();
    objectlist result = GoldReader::parseList(buffer.str());
    characterssheet.close();
    return result;
}