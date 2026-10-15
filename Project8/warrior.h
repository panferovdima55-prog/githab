#pragma once

#include <iostream> 
#include<vector>
#include<algorithm>
#include<memory>
#include "NPC.h"
#include "NPC.cpp"
using namespace std;


class Warrior : virtual public NPC
{
protected:
	short strength{ 21 };
	vector<Weapon> weapons;
public:
	//конструктор по умолчанию
	Warrior()
	{
		//cout << "конструктор война" << endl;

		damage = 20;
		health = 30;
		armor = 15;
		Create();
	}
	//кастомный конструктор
	Warrior(string name, unsigned int lvl)
	{
		damage = 20;
		health = 30;
		armor = 15;
		this->name = name; //такой способ задания поля уместен только для сеттер
		for (size_t i = 0; i < lvl; i++)
		{
			LvlUp();
		}
		//this->lvl = lvl; //this - указывает на конкретный экземпляр класса
	}
	void Create() override
	{
		cout << "Вы создали война\nЗадайте имя игрока\n";
		cin >> name;

		GetInfo();
		GetWeapon();
	};
	void GetInfo()
	{
		NPC::GetInfo();
		cout << "сила: " << strength << endl;
	};
	void GetWeapon()
	{
		Weapon weapon;
		weapon.damage = 1;
		weapon.name = "кулаки";
		weapons.push_back(weapon);

		cout << name << " взял в руки оружие " << weapons[0].name << endl;
		cout << " добавка к урону = " << weapons[0].damage << endl;
	};

	void Relaculate() {
		NPC::Relaculate();
		damage += strength / 10;
		health += strength / 5;
	}
	~Warrior() //деструктор (вызывается сам в момент высвобождения памяти экземпляра)
	{
		cout << name << " пал смертью храбрых" << endl;
	}
};