#include "Entity.hpp"
#include "RandomGenerator.hpp"
#include <sstream>
#include <string>

RandomGenerator *RANDOM_GENERATOR = new RandomGenerator();

void EntityActionAttackPlayer::execute(GameManager *gm, Entity *self, object arg)
{
    self->dealDamage(gm->playerEntity);
}

void EntityActionAttackEnemy::execute(GameManager *gm, Entity *self, object arg)
{
    self->dealDamage(gm->currentEnemy);
}
void EntityActionHealSelf::execute(GameManager *gm, Entity *self, object arg)
{
    if (self->mp)
    {
        self->hp += 5;
        self->hp = max(self->hp, self->maxHP);
        self->mp--;
    }
}

Entity *SimpleEntityFactory::create(map<string, string> instconfig)
{
    SimpleEntity *e = new SimpleEntity();
    e->name = instconfig.at("name");
    e->actions = &this->actions;
    e->maxHP = this->maxHP;
    e->hp = this->hp;
    e->atk = this->atk;
    e->def = this->def;
    e->agility = this->agility;
    e->critMult = this->critMult;
    e->critRate = this->critRate;
    if (instconfig.count("maxHP"))
    {
        e->maxHP = stoi(instconfig.at("maxHP"));
        e->hp = e->maxHP;
    }
    if (instconfig.count("atk"))
    {
        e->atk = stoi(instconfig.at("atk"));
    }
    if (instconfig.count("def"))
    {
        e->def = stoi(instconfig.at("def"));
    }
    if (instconfig.count("maxMP"))
    {
        e->maxMP = stoi(instconfig.at("maxMP"));
        e->mp = e->maxMP;
    }
    if (instconfig.count("critRate"))
    {
        stringstream(instconfig.at("critRate")) >> e->critRate;
    }
    if (instconfig.count("critMult"))
    {
        stringstream(instconfig.at("critMult")) >> e->critMult;
    }
    if (instconfig.count("agility"))
    {
        stringstream(instconfig.at("agility")) >> e->agility;
    }

    return e;
}
Entity *PlayerEntityFactory::create(map<string, string> instconfig)
{
    SimpleEntity *e = new SimpleEntity();
    e->name = instconfig.at("name");
    e->actions = &this->actions;
    e->maxHP = this->maxHP;
    e->hp = this->hp;
    e->atk = this->atk;
    e->def = this->def;
    e->agility = this->agility;
    e->critMult = this->critMult;
    e->critRate = this->critRate;
    if (instconfig.count("maxHP"))
    {
        e->maxHP = stoi(instconfig.at("maxHP"));
        e->hp = e->maxHP;
    }
    if (instconfig.count("atk"))
    {
        e->atk = stoi(instconfig.at("atk"));
    }
    if (instconfig.count("def"))
    {
        e->def = stoi(instconfig.at("def"));
    }
    if (instconfig.count("maxMP"))
    {
        e->maxMP = stoi(instconfig.at("maxMP"));
        e->mp = e->maxMP;
    }
    if (instconfig.count("critRate"))
    {
        stringstream(instconfig.at("critRate")) >> e->critRate;
    }
    if (instconfig.count("critMult"))
    {
        stringstream(instconfig.at("critMult")) >> e->critMult;
        //e->critMult = stof(instconfig.at("critMult"));
    }
    if (instconfig.count("agility"))
    {
        stringstream(instconfig.at("agility")) >> e->agility;
    }

    return e;
}

Entity *HealerPlayerEntityFactory::create(map<string, string> instconfig)
{
    SimpleEntity *e = new SimpleEntity();
    e->name = instconfig.at("name");
    e->actions = &this->actions;
    e->maxHP = this->maxHP;
    e->hp = this->hp;
    e->atk = this->atk;
    e->def = this->def;
    e->agility = this->agility;
    e->critMult = this->critMult;
    e->critRate = this->critRate;
    if (instconfig.count("maxHP"))
    {
        e->maxHP = stoi(instconfig.at("maxHP"));
        e->hp = e->maxHP;
    }
    if (instconfig.count("atk"))
    {
        e->atk = stoi(instconfig.at("atk"));
    }
    if (instconfig.count("def"))
    {
        e->def = stoi(instconfig.at("def"));
    }
    if (instconfig.count("maxMP"))
    {
        e->maxMP = stoi(instconfig.at("maxMP"));
        e->mp = e->maxMP;
    }
    if (instconfig.count("critRate"))
    {
        stringstream(instconfig.at("critRate")) >> e->critRate;
    }
    if (instconfig.count("critMult"))
    {
        stringstream(instconfig.at("critMult")) >> e->critMult;
    }
    if (instconfig.count("agility"))
    {
        stringstream(instconfig.at("agility")) >> e->agility;
    }

    return e;
}

DamageDescriptor SimpleEntity::dealDamage(Entity *other)
{
    DamageDescriptor dd;

    if (RANDOM_GENERATOR->getRandom() < this->critRate)
    {
        dd.dmg = floor(this->atk * this->critMult);
    }
    else
    {
        dd.dmg = this->atk;
    }
    other->takeDamage(dd);
    return dd;
}

void SimpleEntity::takeDamage(DamageDescriptor dd)
{
    if (this->agility > RANDOM_GENERATOR->getRandom())
    {
        return;
    }
    this->hp -= dd.dmg;
    if (this->hp <= 0)
    {
        this->isAlive = false;
        this->hp = 0;
    }
}