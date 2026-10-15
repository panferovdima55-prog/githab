#include <iostream> 
#include<vector>
#include<algorithm>
#include<memory>
#include "wizard.h"
#include "Spell.h"
#include "NPC.h"
#include "NPC.cpp"

using namespace std;

struct Weapon
{
	string name{ "weapon" };
	unsigned int damage{ 1 };
};
