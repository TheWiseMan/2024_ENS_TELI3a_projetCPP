#pragma once

#include <map>
#include <iostream>
#include <list>

/** String reader for Group1 Object List Data
 */
class GoldReader
{
public:
    static std::list<std::map<std::string, std::string>> parseList(std::string textToParse);
    static std::map<std::string, std::string> parseObject(std::string textToParse);
};

typedef std::list<std::map<std::string, std::string>> objectlist;
typedef std::map<std::string, std::string> object;