#include "Warrior.h"
#include "Wizard.h"
#include "Paladin.h"
#include "Enums.h"
#include "Player.h"

#include <iostream>
#include <memory>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    Player player;
    int characterChoice;
    int qualityChoice;
    
    while (true) {

        cout << "1 - Воин\n";
        cout << "2 - Волшебник\n";
        cout << "3 - Паладин\n";

        cin >> characterChoice;

        if (characterChoice >= 1 && characterChoice <= 3)
        {
            
           break;
            
        }
        cout << "Ошибка: неверный выбор персонажа!\n";


}


    CharacterType character =
        static_cast<CharacterType>(characterChoice);

    switch (character)
    {
    case CharacterType::Warrior:
        player.Create(make_unique<Warrior>());
        cout << "\nВоин - мастер ближнего боя.\n";
        break;

    case CharacterType::Wizard:
        player.Create(make_unique<Wizard>());
        cout << "\nВолшебник использует мощную магию.\n";
        break;

    case CharacterType::Paladin:
        player.Create(make_unique<Paladin>());
        cout << "\nПаладин сочетает атаку и защиту.\n";
        break;

    default:
        cout << "Ошибка выбора персонажа!\n";
        return 1;
    }

    cout << "\nВыберите качество оружия:\n";
    cout << "1 - Обычное\n";
    cout << "2 - Необычное\n";
    cout << "3 - Редкое\n";
    cout << "4 - Эпическое\n";
    cout << "5 - Легендарное\n";

    cin >> qualityChoice;

    if (qualityChoice < 1 || qualityChoice > 5)
    {
        cout << "Ошибка: неверное качество оружия!\n";
        return 1;
    }

    WeaponQuality quality =
        static_cast<WeaponQuality>(qualityChoice);

    cout << "\nИнформация об оружии:\n";

    switch (quality)
    {
    case WeaponQuality::Common:
        cout << "Обычное оружие.\n";
        break;

    case WeaponQuality::Uncommon:
        cout << "Необычное оружие\n";
        break;

    case WeaponQuality::Rare:
        cout << "Редкое оружие \n";
        break;

    case WeaponQuality::Epic:
        cout << "Эпическое оружие \n";
        break;

    case WeaponQuality::Legendary:
        cout << "Легендарное оружие\n";
        break;

    default:
        cout << "Ошибка выбора качества!\n";
        return 1;
    }

    cout << "\nЧисловое значение персонажа: "
        << static_cast<int>(character);

    cout << "\nЧисловое значение качества оружия: "
        << static_cast<int>(quality)
        << "\n";

    TakeDamage(player.GetCharacter(), 5);

    return 0;
}