#include "c_gameobject.h"
#include <iostream>

GameObject::GameObject()
    : Position(0.0f, 0.0f, 0.0f), Size(1.0f, 1.0f, 1.0f), Rotation(0.0f), Texture(), IsSolid(false)
{
}

GameObject::GameObject(glm::vec3 pos, glm::vec3 size, Texture2D texture, bool solid)
    : Position(pos), Size(size), Texture(texture), IsSolid(solid)
{
}

GameObject::~GameObject()
{
    std::cout << "game object deleted" << std::endl;
}

void GameObject::Draw(SimpleRender &renderer)
{
    renderer.Draw3D(Cube, this->Position, this->Size, this->Texture);
}
