#pragma once
#include <map>
#include <string>
#include <vector>
#include "GameManager.hpp"
#include "Entity.hpp"
using namespace std;
typedef map<string, string> object;

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