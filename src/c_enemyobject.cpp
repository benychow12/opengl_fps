#include "c_enemyobject.h"

EnemyObject::EnemyObject(glm::vec3 pos, glm::vec3 size, glm::vec3 dir, int health, Texture2D texture)
    : GameObject(), Direction(dir), Health(health)
{
    this->State = ENEMY_IDLE;
    this->Position = pos;
    this->Size = size;
    this->Texture = texture;
    this->IsSolid = true;
}

void EnemyObject::UpdateHealth(int damage)
{
    std::cout << "current health is..." << this->Health << std::endl;
    this->Health -= damage;
    std::cout << "new health is..." << this->Health << std::endl;

    if (this->Health <= 0)
    {
        std::cout << "ENEMY DOWN" << std::endl;
        this->State = ENEMY_DEAD;
    }

}
