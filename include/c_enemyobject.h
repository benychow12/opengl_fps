#ifndef ENEMYOBJECT_H
#define ENEMYOBJECT_H

#include "c_gameobject.h"

// Debug
#include <iostream>

enum enemy_state{
    ENEMY_IDLE,
    ENEMY_DEAD
};

class EnemyObject : public GameObject
{
public:
    glm::vec3 Direction;
    int Health;
    enemy_state State;

    EnemyObject(glm::vec3 pos, glm::vec3 size, glm::vec3 dir, int health, Texture2D texture);

    void UpdateHealth(int damage);
};
#endif
