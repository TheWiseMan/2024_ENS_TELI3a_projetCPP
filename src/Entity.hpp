#pragma once
#include <iostream>
#include <map>
#include <string>
#include <list>

typedef std::list<std::map<std::string, std::string>> objectlist;
typedef std::map<std::string, std::string> object;

using namespace std;

/**A class used to pass data representing damage (can be later extended to account for damage types, ...) */
class DamageDescriptor
{
public:
    int dmg;
};

/**The General Entity class, containing data related to living beings. Used for characters and monsters */
class Entity
{
public:
    int maxHP = 1;
    int atk = 0;
    int def = 0;
    int hp = 1;
    /** Calculates the amount of damage dealt to entity other, takes into account advantage rolls and critical, but not the defenses of the enemy
     * Dirrctly invokes `takeDamage` on other, but also returns the damage descriptor.
     * @return The DamageDescriptor passed to enemy
    */
    DamageDescriptor dealDamage(Entity *other);
    void takeDamage(DamageDescriptor dd);
};

/**A factory class to instantiate entities by name, should only be used through the class `EntityLibrary`
 */
class EntityBuilder
{
public:
    int maxHP = 1;
    int atk = 0;
    int def = 0;
    int hp = 1;
    EntityBuilder() {};
    EntityBuilder(EntityBuilder *other, object config);
    Entity *create(map<string, string> instconfig = {});
};

const map<string, EntityBuilder*> DEFAULT_SCENE_TYPE = {
    {"simpleEntity", new EntityBuilder()}};

/**
 * A class used to instantiate entities via their names.
 */
class EntityLibrary
{
public:
    void add(object config);
    Entity *create(string entitytype, map<string, string> instconfig);
    Entity *create(string entitytype);
    void debug();

private:
    map<string, EntityBuilder*> registry = DEFAULT_SCENE_TYPE;
};
