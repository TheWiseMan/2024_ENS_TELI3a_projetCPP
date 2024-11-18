#include <map>
#include <iostream>
#include <list>

class GoldReader
{
public:
    static std::list<std::map<std::string, std::string>> parseList(std::string textToParse);
    static std::map<std::string, std::string> parseObject(std::string textToParse);
};