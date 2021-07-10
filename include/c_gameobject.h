#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <c_texture.h>
#include <c_3drender.h>

// game object entity
class GameObject
{
public:
    // object state information
    glm::vec3 Position, Size;
    float Rotation;
    bool IsSolid;

    glm::mat4 model_view_matrix = glm::mat4(1.0f);

    GameObject();
    GameObject(glm::vec3 pos, glm::vec3 size, Texture2D texture, bool solid);
    ~GameObject();

    Texture2D Texture;

    // draw object in 3d
    // virtual func to override in any derived class (should we need it)
    virtual void UpdateModelMatrix(glm::mat4 model_matrix);

    virtual void Draw(SimpleRender &renderer);
    
};

#endif
