#include <iostream> 
#include<vector>
#include<algorithm>
#include<memory>


using namespace std;


class NPC
{
protected:
	string name{ "npc" };
	unsigned int damage{ 2 };
	unsigned int health{ 5 };
	short lvl = 1;
	unsigned int armor = 2;


private:
	bool isEnemy = true;

public:
	unsigned int GetDamage() { return damage; };
	unsigned int GetHealth() { return health; }; // геттер 
	void SetHealth(unsigned int  health) { this->health = health; }; // сеттер


	// создать NPC  нельзя, поэтому он виртуальный 
	virtual void Create() {}; // хотя бы 1 метод виртуальный, значит весь класс виртуальный  

	friend void TakeDamage(unique_ptr<NPC> npc, unsigned int damage);
	virtual ~NPC() = default;

};