#include <iostream>
#include <map>
#include <string>
#include <list>

typedef std::list<std::map<std::string, std::string>> objectlist;
typedef std::map<std::string, std::string> object;

using namespace std;
// typedef Entity *(*entityfactory)();

/**The General Entity class, containing data related to living beings. Used for characters and monsters */
class Entity
{
public:
    int maxHP = 1;
    int atk = 0;
    int def = 0;
};

/**A factory class to instantiate entities by name, should only be used through the class `EntityLibrary`
 */
class EntityBuilder
{
public:
    int maxHP = 1;
    int atk = 0;
    int def = 0;
    EntityBuilder() {};
    EntityBuilder(EntityBuilder &other, object config);
    Entity *create(map<string, string> instconfig = {});
};

/*class RandomEntityBuilder
{
public:
    int lowerMaxHP = 100;
    int upperMaxHP = 100;
    int lowerMinAttack = 8;
    int upperMinAttack = 8;
    int lowerMaxAttack = 10;
    int upperMaxAttack = 10;
    int lowerCritChance = 0; // /100
    int upperCritChance = 0; // /100
    int critBonus = 2;
    RandomEntityBuilder(object config);
    void init(object config);
    Entity *create(map<string, string> instconfig);
};*/

const map<string, EntityBuilder> DEFAULT_CHARACTER_TYPES = {
    {"simpleEntity", EntityBuilder()}};

/**
 * A class used to instantiate entities via their names.
 */
class EntityLibrary
{
public:
    void add(object config);
    Entity *create(string entitytype, map<string, string> instconfig);
    void debug();

private:
    map<string, EntityBuilder> registry = DEFAULT_CHARACTER_TYPES;
};
