#pragma once

#include <map>
#include <iostream>
#include <list>

typedef std::list<std::map<std::string, std::string>> objectlist;
typedef std::map<std::string, std::string> object;

/** String reader for Group1 Object List Data
 */
class GoldReader
{
public:
    static objectlist parseFile(std::string filepath);
    static objectlist parseList(std::string textToParse);
    static object parseObject(std::string textToParse);
};