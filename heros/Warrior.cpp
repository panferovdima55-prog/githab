#include "Warrior.h"
#include <string>
using namespace std;

Warrior::Warrior()
{
    damage = 20;
    health = 30;
    armor = 15;
}

Warrior::Warrior(string name, unsigned int lvl)
{
    this->name = name;

    damage = 20;
    health = 30;
    armor = 15;

    for (unsigned int i = 0; i < lvl; i++)
    {
        LvlUp();
    }
}

void Warrior::Create()
{
    cout << "¬ведите им€ воина: ";
    cin >> name;

    GetInfo();
    GetWeapon();
}

void Warrior::GetInfo()
{
    NPC::GetInfo();
    cout << "—ила: " << strength << endl;
}

void Warrior::GetWeapon()
{
    Weapon weapon;

    weapon.name = " улаки";
    weapon.damage = 1;

    weapons.push_back(weapon);
}

void Warrior::Recalculate()
{
    NPC::Recalculate();

    damage += strength / 10;
    health += strength / 5;
}

Warrior::~Warrior()
{
    cout << name << " пал смертью храбрых" << endl;
}