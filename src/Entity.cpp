#include "Entity.hpp"

EntityBuilder::EntityBuilder(EntityBuilder *other, object config)
{
    this->maxHP = other->maxHP;
    this->hp = other->hp;
    this->def = other->def;
    this->atk = other->atk;
    if (config.count("maxHP"))
        this->maxHP = stoi(config.at("maxHP"));
    this->hp = this->maxHP;
    if (config.count("atk"))
        this->atk = stoi(config.at("atk"));
    if (config.count("def"))
        this->def = stoi(config.at("def"));
}

Entity *EntityBuilder::create(map<string, string> instconfig)
{
    Entity *e = new Entity();
    e->maxHP = this->maxHP;
    e->hp = this->hp;
    e->atk = this->atk;
    e->def = this->def;
    return e;
}

void EntityLibrary::add(object config)
{
    if (!config.count("type"))
    {
        cerr << "An entity must have a type" << endl;
    }
    if (!config.count("name"))
    {
        cerr << "An entity must have a name" << endl;
    }
    EntityBuilder *copy = new EntityBuilder(this->registry.at(config.at("type")), config);
    this->registry[config.at("name")] = copy;
}

Entity *EntityLibrary::create(string entitytype, map<string, string> instconfig = {})
{
    if (!this->registry.count(entitytype))
    {
        cerr << "Entity not found '" << entitytype << "'" << endl;
    }
    return this->registry.at(entitytype)->create(instconfig);
}
Entity *EntityLibrary::create(string entitytype)
{
    if (!this->registry.count(entitytype))
    {
        cerr << "Entity not found '" << entitytype << "'" << endl;
    }
    return this->registry.at(entitytype)->create();
}

void EntityLibrary::debug()
{
    for (auto &&i : this->registry)
    {
        cout << i.first << endl;
    }
}

DamageDescriptor Entity::dealDamage(Entity *other)
{
    DamageDescriptor dd;
    dd.dmg = this->atk;
    other->takeDamage(dd);
    return dd;
}

void Entity::takeDamage(DamageDescriptor dd)
{
    this->hp -= dd.dmg;
}