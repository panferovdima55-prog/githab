#include "NPC.h"

using namespace std;

NPC::NPC()
{
    cout << "Вы создали NPC" << endl;
}

NPC::~NPC()
{
    cout << "NPC уничтожен" << endl;
}

unsigned int NPC::GetDamage() const
{
    return damage;
}

unsigned int NPC::GetHealth() const
{
    return health;
}

void NPC::SetHealth(unsigned int health)
{
    this->health = health;
}

void NPC::GetInfo()
{
    cout << "Имя: " << name << endl;
    cout << "Здоровье: " << health << endl;
    cout << "Урон: " << damage << endl;
    cout << "Уровень: " << lvl << endl;
    cout << "Броня: " << armor << endl;
}

void NPC::LvlUp()
{
    lvl++;
    Recalculate();
}

void NPC::Recalculate()
{
    damage += 1;
    health += 1;
    armor += 1;
}

void TakeDamage(NPC* npc, unsigned int damage)
{
    if (!npc)
        return;

    if (damage >= npc->health)
        npc->health = 0;
    else
        npc->health -= damage;

    cout << "Получено урона: "
        << damage
        << endl;

    cout << "Текущее здоровье: "
        << npc->health
        << endl;
}