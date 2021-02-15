#include "c_playerobject.h"

// Debug
#include <iostream>
#include <glm/gtx/string_cast.hpp>

PlayerObject::PlayerObject()
    : GameObject()
{
    this->Position = glm::vec3(0.0f, 0.0f, 0.0f);
    this->Size = glm::vec3(0.1f, 0.1f, 0.1f);
    this->IsSolid = true;
}

PlayerObject::PlayerObject(glm::vec3 pos, glm::vec3 size, glm::vec3 dir)
    : GameObject()
{
    this->Position = pos;
    this->Size = size;
    this->player_direction = dir;
    this->IsSolid = true;
}

PlayerObject::PlayerObject(glm::vec3 pos, glm::vec3 size, glm::vec3 dir, Texture2D texture)
    : GameObject(), player_direction(dir)
{
    this->Position = pos;
    this->Size = size;
    this->Texture = texture;
}

void PlayerObject::player_action_shoot()
{
    std::cout << "Player is shoot" << std::endl;
    // Given the position and direction of player
    // cast a ray
}
