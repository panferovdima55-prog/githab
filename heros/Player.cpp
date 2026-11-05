#include "Player.h"

void Player::Create(std::unique_ptr<NPC> character)
{
    currentCharacter = std::move(character);

    currentCharacter->Create();
}

NPC* Player::GetCharacter()
{
    return currentCharacter.get();
}