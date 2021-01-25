#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <c_3drender.h>

// game object entity
class GameObject
{
public:
    // object state information
    glm::vec3 Position, Size;
    float Rotation;
    bool IsSolid;

    GameObject();
    GameObject(glm::vec3 pos, glm::vec3 size, bool solid);

    // draw object in 3d
    // virtual func to override in any derived class (should we need it)
    virtual void Draw(SimpleRender &renderer);
    
};

#endif
