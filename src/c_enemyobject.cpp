#include "c_enemyobject.h"

EnemyObject::EnemyObject(glm::vec3 pos, glm::vec3 size, glm::vec3 dir, int health, Texture2D texture)
    : GameObject(), Direction(dir), Health(health)
{
    this->State = ENEMY_IDLE;
    this->Position = pos;
    this->Size = size;
    this->Texture = texture;
    this->IsSolid = true;

    this->model_view_matrix = glm::mat4(1.0f);
    this->model_view_matrix = glm::translate(this->model_view_matrix, glm::vec3(Position.x, Position.y, Position.z));
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

void EnemyObject::UpdateDir(glm::vec3 direction, float angle, glm::vec3 upVec)
{
    // only if else face if greater than certain angle
    /*
    glm::vec3 obj2cam_p = direction - this->Position;
    glm::vec3 move_vel = 0.01f * obj2cam_p;

    this->model_view_matrix = glm::translate(this->model_view_matrix, glm::vec3(move_vel.x, move_vel.y, move_vel.z));
    this->Position += move_vel;
    */
    
    glm::vec3 obj2cam = direction - this->Position;
    obj2cam[1] = 0.0f;

    obj2cam = glm::normalize(obj2cam);
    glm::vec3 upAux = glm::cross(this->Direction, obj2cam);

    float angleCosine = glm::dot(this->Direction, obj2cam);
    float angleCosine_deg = std::acos(angleCosine) * 180.0f / 3.14f;
    if (angle > 0.1f)
    {
        std::cout << "rotating...." << std::endl;
        this->model_view_matrix = glm::translate(this->model_view_matrix, glm::vec3(0.0f, 0.0f, -0.5f));
        this->model_view_matrix = glm::rotate(this->model_view_matrix, glm::radians(angleCosine_deg), upAux);
        this->model_view_matrix = glm::translate(this->model_view_matrix, glm::vec3(0.0f, 0.0f, 0.5f));
    }
}

void EnemyObject::Draw(SimpleRender &renderer)
{
    renderer.DrawBillboard(this->model_view_matrix, this->Texture);
}
