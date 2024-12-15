#pragma once
#include <map>
#include <string>
#include <vector>
#include <list>
#include "GameManager.hpp"
using namespace std;
typedef map<string, string> object;
typedef std::list<std::map<std::string, std::string>> objectlist;

class Scene
{
public:
    static Scene *fromObjectList(objectlist config, GameManager *gm);
    virtual ~Scene() = 0;
    object config;
    vector<object> options;
};

class SceneFactory
{
public:
    virtual Scene *create(objectlist config, GameManager *gm) const = 0;
};