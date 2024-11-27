#include "Entity.hpp"
#include "Utils.hpp"

EntityBuilder::EntityBuilder(EntityBuilder& other, object config)
{
    if (config.count("maxHP")) this->maxHP = stoi(config.at("maxHP"));
    if (config.count("atk")) this->atk = stoi(config.at("atk"));
    if (config.count("def")) this->def = stoi(config.at("def"));
}

Entity EntityBuilder::create(map<string, string> instconfig)
{
    Entity e = Entity();
    e.maxHP = this->maxHP;
    e.atk = this->atk;
    e.def = this->def;
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
    EntityBuilder copy(this->registry.at(config.at("type")), config);
    this->registry[config.at("name")] = copy;
}

Entity EntityLibrary::create(string entitytype, map<string, string> instconfig = {})
{
    return this->registry.at(entitytype).create(instconfig);
}
Entity EntityLibrary::create(string entitytype)
{
    return this->registry.at(entitytype).create();
}

void EntityLibrary::debug() {
    for (auto &&i : this->registry)
    {
        cout << i.first << endl;
    }
    
}