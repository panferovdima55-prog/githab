#include "Wizard.h"

using namespace std;

Wizard::Wizard()
{
    damage = 27;
    health = 21;
    armor = 10;
}

void Wizard::Create()
{
    cout << "Введите имя волшебника: ";
    cin >> name;

    GetInfo();
    LearnSpell();
}

void Wizard::GetInfo()
{
    NPC::GetInfo();
    cout << "Интеллект: " << intellect << endl;
}

void Wizard::LearnSpell()
{
    Spell spell;

    spell.name = "Вспышка";
    spell.damage = 2;

    spells.push_back(spell);
}

void Wizard::Recalculate()
{
    NPC::Recalculate();

    damage += intellect / 10;
}

Wizard::~Wizard()
{
    cout << name << " испускает дух" << endl;
}