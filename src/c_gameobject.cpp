#include "c_gameobject.h"
#include <iostream>

// debug
#include "glm/gtx/string_cast.hpp"

GameObject::GameObject()
    : Position(0.0f, 0.0f, 0.0f), Size(1.0f, 1.0f, 1.0f), Rotation(0.0f), Texture(), IsSolid(false)
{
    this->model_view_matrix = glm::mat4(1.0f);
}

GameObject::GameObject(glm::vec3 pos, glm::vec3 size, Texture2D texture, bool solid)
    : Position(pos), Size(size), Texture(texture), IsSolid(solid)
{
    this->model_view_matrix = glm::translate(model_view_matrix, this->Position);
}

GameObject::~GameObject()
{
    std::cout << "game object deleted" << std::endl;
}

void GameObject::UpdateModelMatrix(glm::mat4 model_matrix)
{
    this->model_view_matrix = model_matrix;
}

void GameObject::Draw(SimpleRender &renderer)
{
    renderer.Draw3D(Cube, this->Position, glm::vec3(1.0f), this->Size, this->Texture);
}
