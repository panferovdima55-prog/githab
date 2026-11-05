#pragma once

#include "NPC.h"
#include "Weapon.h"
#include <vector>
#include <string>

using namespace std;

class Warrior : virtual public NPC
{
protected:
    short strength{ 21 };
    vector<Weapon> weapons;

public:
    Warrior();
    Warrior(string name, unsigned int lvl);

    void Create() override;
    void GetInfo() override;
    void Recalculate() override;

    void GetWeapon();

    virtual ~Warrior();
};