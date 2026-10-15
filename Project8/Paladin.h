#include <iostream> 
#include<vector>
#include<algorithm>
#include<memory>


#include<wizard.h>
#include <warrior.h>
using namespace std;

class Paladin : public Warrior, public Wizard
{
public:
	Paladin()
	{
		intellect = 25;
		strength = 19;
		health = 25;
		damage = 25;
		Create();
	}
	void Create() override
	{
		// реализуйте это в npc (храниетет название в каком то поле)
		cout << "Вы создали Паладина\nЗадайте имя игрока\n";
		cin >> name;

		GetInfo();
		GetWeapon();
		LearnSpell();

	};
	void GetInfo()
	{
		Warrior::GetInfo();
		cout << "интеллект: " << intellect << endl;
	};
	~Paladin()
	{
		cout << "отправляется к праотцам " << endl;
	}

};
