#include <iostream> 
#include<vector>

using namespace std;
//ключевые понятия (принципы) ООП:
//1) наследование
//2) полиморфизм
//3) абстракция
//4) инкапсуляция (геттер и сеттер)

//public - публичный (доступнен внутри класса, внутри наследника и в основном потоке программы)
//protected - защищенный (можно изменять в исходном классе и классах наследниках)
//private - приватный  (доступен в исзодном классе)
//private - не наследуется!!!   
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

struct Weapon
{
	string name{ "weapon" };
	unsigned int damage{ 1 };
};

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

struct Spell
{
	string name{ "spell" };
	unsigned int damage{ 1 };
};

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

class Evil : public

	NPC
{
public:
	Evil()
	{
		name = "Злодей";
		health = 10;
		damage = 5;
		armor = 3;
	}
	Evil(string name) : Evil() //делегирование конструктора (то есть вызовется вначале базовый)
	{
		this->name = name;
	}
	Evil(string name, unsigned int damage) : Evil(name)
	{
		this->damage = damage;
	}
	Evil(string name, unsigned int damage, unsigned int health) : Evil(name, damage)
	{
		this->health = health;
	}
	Evil(string name, unsigned int damage, unsigned int health, unsigned int armor) : Evil(name, damage, health)
	{
		this->armor = armor;
	}

	~Evil()
	{
		cout << name << " заточен в темницу" << endl;
	}
	//придумать интересный деструктор для злодеев
};

// множественое наследование 

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

// дружественный класс Хранит или принимает аргумент экзепляр другого класса 
// блягодаря этом может использовать его поля и методы (даже защищеные)
// могут внутри себя хранить ссылку на другой класс
class Player
{

private:
	unique_ptr<NPC> currenCharacter{ nullptr };  // умный указатель указыватет на что то общее
public:
	void Create(unique_ptr<NPC> character)
	{
		currenCharacter = move(character);
		currenCharacter->Create();
	}
	unique_ptr<NPC> GetCharecter()
	{
		return move(currenCharacter);
	}


};

//Дужественные функции   дает доступ к полям даже , если они privste 
// обязателен прототипс кплючевым словом friend внутри самого класа
// не является частью самого класса 
void TakeDamage(unique_ptr<NPC> npc, unsigned int damage)
{
	npc->health -= damage;
	cout << "вы получили " << damage << "едениц урона";
	cout << "текущее здровье = " << npc->health;
}

int main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "Rus");

	/* Warrior* warrior = new Warrior("друг война", 5); //как только создал новый экземпляр, для него вызвался конструктор
	 warrior->GetInfo(); //стрелка с указателем

	 cout << "метод публичный, вот значение - " << warrior->GetHealth();

	 delete warrior;
	 warrior = nullptr;*/

	Player player;

	cout << "здарова емае как дела, кто таков ?" << endl;
	cout << "\t 1 - вион\n\t2 - волшебник \n\t3 - паладин " << endl;
	short choise = 0;
	cin >> choise;
	// валидация выбора через while - сунуть в функцию
	switch (choise)
	{
	case 1:
		player.Create(make_unique<Warrior>());
		break;
	case 2:
		player.Create(make_unique<Wizard>());
		break;
	case 3:
		player.Create(make_unique<Paladin>());
		break;
	default:
		cout << "таких героев еще не было тут, возварщайся потом ";
		break;
	}

	TakeDamage(player.GetCharecter(), 5);

	// превратить злодеев в вектор (указателей, умных)
   /* vector <unique_ptr <Evil>> evils;

	evils.push_back(make_unique<Evil>());
	evils.push_back(make_unique<Evil>("Кабанчик"));
	evils.push_back(make_unique<Evil>("Гнолл", 12));
	evils.push_back(make_unique<Evil>("Гнолл Дробитель", 15, 20));
	evils.push_back(make_unique<Evil>("Дракон", 50, 100, 200));

	for (auto& evil : evils)
	 evil->GetInfo();*/

	return 0;
}