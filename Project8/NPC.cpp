#include <iostream> 
#include<vector>
#include<algorithm>
#include<memory>
#include "NPC.h"


using namespace std;
class NPC
{
protected:
	string name{ "npc" };
	unsigned int damage{ 2 };
	unsigned int health{ 5 };
	short lvl = 1;
	unsigned int armor = 2;

public:
	NPC() {
		cout << "вы созадли нпс ";
		name = "npc";
		damage = 2;
		health = 5;
		lvl = 1;
		armor = 2;

	}
	~NPC()
	{
		cout << " NPC уничтожен  "; // применение (объяснения) стек 
	}
private:
	bool isEnemy = true;

public:
	unsigned int GetDamage() { return damage; };
	unsigned int GetHealth() { return health; }; // геттер 
	void SetHealth(unsigned int  health) { this->health = health; }; // сеттер

	void GetInfo()
	{
		cout << "имя: " << name << endl;
		cout << "здоровье: " << health << endl;
		cout << "урон: " << damage << endl;
		cout << "уровень: " << lvl << endl;
		cout << "броня: " << armor << endl;
	};
	// создать NPC  нельзя, поэтому он виртуальный 
	virtual void Create() {}; // хотя бы 1 метод виртуальный, значит весь класс виртуальный  

	friend void TakeDamage(unique_ptr<NPC> npc, unsigned int damage);
	virtual ~NPC() = default;

	void LvlUp()
	{
		cout << name << " получил новый уровень" << endl;
		lvl;
		Relaculate();
	}
	void Relaculate() //кастомизировать для война и волшебника зависимости от инт/силы
	{
		damage += (1 + lvl * 0.1);
		health += (1 + lvl * 0.1);
		armor += (1 + lvl * 0.1);
	}
};