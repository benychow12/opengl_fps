#include "c_gameobject.h"

GameObject::GameObject()
    : Position(0.0f, 0.0f, 0.0f), Size(1.0f, 1.0f, 1.0f), Rotation(0.0f), IsSolid(false)
{
}

GameObject::GameObject(glm::vec3 pos, glm::vec3 size, bool solid)
    : Position(pos), Size(size), IsSolid(solid)
{
}

void GameObject::Draw(SimpleRender &renderer)
{
    renderer.Draw3D(Cube, this->Position, this->Size);
}
