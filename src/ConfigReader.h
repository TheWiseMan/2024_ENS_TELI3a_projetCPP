#pragma once
#include <fstream>
#include <filesystem>
#include <string>

using namespace std;

#include "GoldReader.h"

class ConfigReader {
    public:
    static objectlist readEntitiesConfig(string filename);
};