#pragma once
#include <iostream>
#include <map>
#include <string>
#include <list>
#include <random>
#include "GameManager.hpp"

typedef std::list<std::map<std::string, std::string>> objectlist;
typedef std::map<std::string, std::string> object;

using namespace std;

class Entity;

/**A class used to pass data representing damage (can be later extended to account for damage types, ...) */
class DamageDescriptor
{
public:
    int dmg;
};

class EntityAction
{
public:
    virtual string getName() = 0;
    virtual void execute(GameManager *gm, Entity *self, object args) = 0;
};

/**The General Entity class, containing data related to living beings. Used for characters and monsters */
class Entity
{
public:
    string name;
    vector<EntityAction *> *actions;
    bool isAlive = true;
    int maxHP = 1;
    int atk = 0;
    int def = 0;
    int hp = 1;
    int mp = 5;
    int maxMP = 5;
    float critRate = 0.0;
    float critMult = 1;
    float agility = 0.0;
    /** Calculates the amount of damage dealt to entity other, takes into account advantage rolls and critical, but not the defenses of the enemy
     * Dirrctly invokes `takeDamage` on other, but also returns the damage descriptor.
     * @return The DamageDescriptor passed to enemy
     */
    virtual DamageDescriptor dealDamage(Entity *other) = 0;
    virtual void takeDamage(DamageDescriptor dd) = 0;
};

/**A factory class to instantiate entities by name, should only be used through the class `EntityLibrary`
 */
class EntityFactory
{
public:
    virtual Entity *create(map<string, string> instconfig = {}) = 0;
};

class EntityActionAttackPlayer : public EntityAction
{
    string getName() { return "Attack player"; };
    void execute(GameManager *gm, Entity *self, object args);
};

class EntityActionAttackEnemy : public EntityAction
{
    string getName() { return "Attack"; };
    void execute(GameManager *gm, Entity *self, object args);
};

class EntityActionHealSelf : public EntityAction
{
    string getName() { return "Heal self"; };
    void execute(GameManager *gm, Entity *self, object args);
};

class SimpleEntity : public Entity
{
public:
    DamageDescriptor dealDamage(Entity *other);
    void takeDamage(DamageDescriptor dd);
};

class SimpleEntityFactory : public EntityFactory
{
    int maxHP = 5;
    int atk = 0;
    int def = 0;
    int hp = 1;
    int mp = 5;
    int maxMP = 5;
    float critRate = 0.0;
    float critMult = 1.5;
    float agility = 0.0;

public:
    vector<EntityAction *> actions = {new EntityActionAttackPlayer()};
    Entity *create(map<string, string> instconfig = {});
};

class PlayerEntityFactory : public SimpleEntityFactory
{
    int maxHP = 10;
    int atk = 1;
    int def = 0;
    int hp = 1;
    int mp = 5;
    int maxMP = 5;
    float critRate = 0.0;
    float critMult = 1.5;
    float agility = 0.0;
    vector<EntityAction *> actions = {new EntityActionAttackEnemy()};
    Entity *create(map<string, string> instconfig = {});
};

class HealerPlayerEntityFactory : public SimpleEntityFactory
{
    int maxHP = 10;
    int atk = 0;
    int def = 0;
    int hp = 1;
    int mp = 5;
    int maxMP = 5;
    float critRate = 0.0;
    float critMult = 1.5;
    float agility = 0.0;
    vector<EntityAction *> actions = {new EntityActionAttackEnemy(), new EntityActionHealSelf()};
    Entity *create(map<string, string> instconfig = {});
};