#include <iostream> 
#include<vector>
#include<algorithm>
#include<memory>
#include "wizard.h"
#include "Spell.h"
#include "NPC.h"
#include "NPC.cpp"
using namespace std;

class Wizard : virtual public NPC
{
protected:
	short intellect{ 21 };
	vector<Spell> spells;
public:
	Wizard()//конструктор вызывается в момент создания экземпляра
	{
		//cout << "конструктор волшебник" << endl;
		damage = 27;
		health = 21;
		armor = 10;
		for (size_t i = 0; i < lvl; i++)
		{
			LvlUp();
		}
		//this->lvl = lvl; //this - указывает на конкретный экземпляр класса
		Create();
	}
	void Create() override
	{
		cout << "Вы создали волшебник\nЗадайте имя игрока\n";
		cin >> name;

		GetInfo();
		LearnSpell();

	};
	void GetInfo()
	{
		NPC::GetInfo();
		cout << "интеллект: " << intellect << endl;
	};
	void LearnSpell()
	{
		Spell spell;
		spell.damage = 2;
		spell.name = "вспышка";
		spells.push_back(spell);

		cout << name << " изучил заклинание " << spells[0].name << endl;
		cout << " добавка к урону = " << spells[0].damage << endl;
	};
	void Relaculate() {
		NPC::Relaculate();
		damage += intellect / 10;

	}
	~Wizard()
	{
		cout


			<< name << " испускает дух" << endl;
	}
};