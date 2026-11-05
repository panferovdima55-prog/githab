#pragma once

#include "NPC.h"
#include "Spell.h"

#include <vector>

class Wizard : virtual public NPC
{
protected:
    short intellect{ 21 };
    std::vector<Spell> spells;

public:
    Wizard();

    void Create() override;
    void GetInfo() override;
    void Recalculate() override;

    void LearnSpell();

    virtual ~Wizard();
};
