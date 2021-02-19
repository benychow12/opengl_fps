// debug
#include <iostream>

#include "c_colmanager.h"
#include "glm/gtx/string_cast.hpp"

bool CollisionManager::CheckRaycastObject(glm::vec3 origin, glm::vec3 dir, int dist, GameObject &one)
{
    // for some arbitrary unit of travel
    // Having this as an int might bit me in the ass later 
    // TODO
    for(int c = 0; c < dist; c++)
    {
        std::cout << c << std::endl;
        // Point vs AABB collision
        bool collision_detect = (origin.x >= one.Position.x - one.Size.x / 2.0f && origin.x <= one.Position.x + one.Size.x / 2.0f) && (origin.y >= one.Position.y - one.Size.y / 2.0f && origin.y <= one.Position.y + one.Size.y / 2.0f) && (origin.z >= one.Position.z - one.Size.z / 2.0f && origin.z <= one.Position.z + one.Size.z / 2.0f);

        if(collision_detect)
        {
            std::cout << "HIT!" << std::endl;
            return true;
        }
        else // Update ray
        {
            origin += dir;
            std::cout << "Raycasting..." << glm::to_string(origin) << std::endl;
        }
    }
    std::cout << "miss shot" << std::endl;
    return false;
}

bool CollisionManager::CheckAABB(GameObject &one, GameObject &two)
{
    bool collision_detect = true;

    if (one.IsSolid && two.IsSolid)
    {
        // For xyz axis collision check
        for (int i = 0; i < 3; ++i)
        {
            // define top left position
            float one_top_left = one.Position[i] - one.Size[i] / 2.0f;
            float two_top_left = two.Position[i] - two.Size[i] / 2.0f;

            collision_detect &= one_top_left + one.Size[i] >= two_top_left && two_top_left + two.Size[i] >= one_top_left;
        }

        if (collision_detect)
        {
            return true;
        }
    }
    return false;
}
