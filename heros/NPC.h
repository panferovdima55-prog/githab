#pragma once
#include <iostream>
#include <string>

class NPC
{
protected:
    std::string name{ "npc" };
    unsigned int damage{ 2 };
    unsigned int health{ 5 };
    short lvl{ 1 };
    unsigned int armor{ 2 };

private:
    bool isEnemy{ true };

public:
    NPC();
    virtual ~NPC();

    unsigned int GetDamage() const;
    unsigned int GetHealth() const;

    void SetHealth(unsigned int health);

    virtual void GetInfo();
    virtual void Create() = 0;

    void LvlUp();
    virtual void Recalculate();

    friend void TakeDamage(NPC* npc, unsigned int damage);
};

void TakeDamage(NPC* npc, unsigned int damage);