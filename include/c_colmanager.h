#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include "c_gameobject.h"
#include "GLFW/glfw3.h"

class CollisionManager
{
public:
    // Checks Point vs AABB through Raycasting from origin and dir input
    static bool CheckRaycastObject(glm::vec3 origin, glm::vec3 dir, int dist, GameObject &one);

    static bool CheckAABB(GameObject &one, GameObject &two);
};
#endif
