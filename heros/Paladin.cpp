#include "Paladin.h"

using namespace std;

Paladin::Paladin()
{
    intellect = 25;
    strength = 19;
}

void Paladin::Recalculate()
{
    NPC::Recalculate();

    damage += strength / 10;
    damage += intellect / 10;
    health += strength / 5;
}

void Paladin::Create()
{
    cout << "Введите имя паладина: ";
    cin >> name;

    GetInfo();

    GetWeapon();
    LearnSpell();
}

void Paladin::GetInfo()
{
    Warrior::GetInfo();

    cout << "Интеллект: "
        << intellect
        << endl;
}

Paladin::~Paladin()
{
    cout << name
        << " отправляется к праотцам"
        << endl;
}