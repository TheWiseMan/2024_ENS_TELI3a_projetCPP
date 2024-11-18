#include "./GoldReader.h"

std::list<std::map<std::string, std::string>> GoldReader::parse(std::string textToParse) {
    std::list<std::map<std::string, std::string>> output;
    output.push_back({
        {"a", "45"},
        {"key1", "value1"},
        {"key2", "value2"},
    });
    return output;
}