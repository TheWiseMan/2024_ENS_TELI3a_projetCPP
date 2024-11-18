#include <map>
#include <iostream>
#include <list>

class GoldReader
{
public:
    static std::list<std::map<std::string, std::string>> parse(std::string textToParse);
};