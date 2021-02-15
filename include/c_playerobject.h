#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H

#include "c_gameobject.h"
class PlayerObject : public GameObject
{
public:
    glm::vec3 player_direction;

    PlayerObject();
    PlayerObject(glm::vec3 pos, glm::vec3 size, glm::vec3 dir);
    PlayerObject(glm::vec3 pos, glm::vec3 size, glm::vec3 dir, Texture2D texture);

    void player_action_shoot();
};
#endif
