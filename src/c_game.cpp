#include <iostream>

#include "c_game.h"
#include "c_resmanager.h"
#include "c_3drender.h"
#include "c_camera.h"
#include <c_gameobject.h>

#include "glm/gtx/string_cast.hpp"

// debug
#include <vector>

// Game-related state data
SimpleRender *Renderer;
GameObject *Player;

// debug object
std::vector<GameObject*> bloobloo;
GameObject *bloo;
GameObject *bloo2;
bool CheckCollision(GameObject &one, GameObject &two);

Camera PlayerCamera(glm::vec3(0.0f, 0.0f, 3.0f));

Game::Game(unsigned int width, unsigned int height)
    : State(GAME_ACTIVE), Width(width), Height(height)
{
    cam_lastX = width / 2.0f;
    cam_lastY = height / 2.0f;
    firstMouse = true;
}

Game::~Game()
{
    delete Renderer;
    delete Player;

}

void Game::Init()
{
    std::cout << "Game init" << std::endl;

    // load the shaders
    ResourceManager::LoadShader("shaders/s_vertex.vs", "shaders/s_fragment.fs", nullptr, "shader_main");
    ResourceManager::GetShader("shader_main").Use();

    // configure the shaders
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    // set render-specific controls
    Renderer = new SimpleRender(ResourceManager::GetShader("shader_main"));

    // Configure game objects
    Player = new GameObject(PlayerCamera.GetPosition(), glm::vec3(1.0f, 1.0f, 1.0f), true);
    bloo = new  GameObject(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f), true);
    bloo2 = new GameObject(glm::vec3(0.0f, -3.0f, 0.0f), glm::vec3(10.0f, 1.0f, 10.0f), true);
    // DEBUG
    bloobloo.push_back(bloo);
    bloobloo.push_back(bloo2);
    std::cout << "blobllosize...." << bloobloo.size() << std::endl;
}

void Game::ProcessInput(float dt)
{
    if (this->State == GAME_ACTIVE)
    {
        if (this->Keys[GLFW_KEY_W])
        {
            // std:: cout << "W pressed..." << std::endl;
            PlayerCamera.ProcessKeyboardCamera(CAM_FORWARD, dt);            
        }
        if (this->Keys[GLFW_KEY_S])
        {
            // std::cout << "S pressed..." << std::endl;
            PlayerCamera.ProcessKeyboardCamera(CAM_BACKWARD, dt);            
        }
        if (this->Keys[GLFW_KEY_A])
        {
            // std::cout << "A pressed..." << std::endl;
            PlayerCamera.ProcessKeyboardCamera(CAM_LEFT, dt);            
        }
        if (this->Keys[GLFW_KEY_D])
        {
            // std::cout << "D pressed..." << std::endl;
            PlayerCamera.ProcessKeyboardCamera(CAM_RIGHT, dt);            
        }
        if (this->Keys[GLFW_KEY_C])
        {
            PlayerCamera.ProcessKeyboardCamera(CAM_UP, dt);            
        }
        if (this->Keys[GLFW_KEY_V])
        {
            PlayerCamera.ProcessKeyboardCamera(CAM_DOWN, dt);            
        }

        PlayerCamera.ProcessMouseMovementCamera(cam_xoffset, cam_yoffset);
        // reset the offsets to avoid drifting
        cam_xoffset = 0.0f;
        cam_yoffset = 0.0f;
    }

}

void Game::Update(float dt)
{
    // Debug
    std::cout << "Player Position..." << std::endl;
    std::cout << Player->Position.x << std::endl;
    std::cout << Player->Position.y << std::endl;
    std::cout << Player->Position.z << std::endl;

    // Collision in game update
    // this->DoCollisions();
    /*
    if (CheckCollision(*Player, *bloo))
    {
        std::cout << "collision detected" << std::endl;
    }
    */
    glm::vec3 CurrentPos = Player->Position;
    Player->Position = PlayerCamera.Position;
    for (auto &object : bloobloo)
    {
        std::cout << "bloobloo sizes" << std::endl;
        std::cout << object->Size.x << std::endl;
        std::cout << object->Size.y << std::endl;
        std::cout << object->Size.z << std::endl;

        if (CheckCollision(*Player, *object))
        {
            std::cout << "collision detected" << std::endl;
            PlayerCamera.Position = CurrentPos;
            Player->Position = CurrentPos;
        }
        else
        {
            std::cout << "chilling" << std::endl;
            Player->Position = PlayerCamera.Position;
        }
    }
}

void Game::Render(float dt)
{
    // stuff about updating the view and perspective to pass into render class
    // test draw
    glm::mat4 view = PlayerCamera.GetViewMatrix();
    Renderer->render_view = view;

    // debug for game object
    bloo->Draw(*Renderer);
    bloo2->Draw(*Renderer);
    // Renderer->Draw3D(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f));
    // Renderer->Draw3D(glm::vec3(5.0f, 0.0f, 0.0f), glm::vec3(10.0f, 10.0f, 10.0f));
}

// Simple AABB check for collision, return true/false
// Check right side of first object greater than left side of second object
// and if second object right greater than first left
// Since scaling is done uhh from the center it will be size/2
bool CheckCollision(GameObject &one, GameObject &two)
{
    bool collision_detect = true;

    for (int i = 0; i < 3; ++i)
    {
        // define top left position
        float one_top_left = one.Position[i] - one.Size[i] / 2.0f;
        float two_top_left = two.Position[i] - two.Size[i] / 2.0f;

        std::cout << "one two top left is..." << one_top_left << "   " << two_top_left << std::endl;

        collision_detect &= one_top_left + one.Size[i] >= two_top_left && two_top_left + two.Size[i] >= one_top_left;
    }

    if (collision_detect)
    {
        return true;
    }

    return false;
}

void Game::DoCollisions()
{
    // ineffective way to compare each object in gameobject vector
    for (int i = 0; i < bloobloo.size(); ++i)
    {
        for (int j = i + 1; j < bloobloo.size(); ++j)
        {
            if (CheckCollision(*bloobloo[i], *bloobloo[j]))
            {
                std::cout << "collision deteced" << std::endl;
                // i = 0 is the player object for now...
                if (i == 0 && bloobloo[j]->IsSolid)
                {
                    std::cout << "player hitting solid" << std::endl;
                }
            }
            else
            {
                std::cout << "chilling" << std::endl;
            }
        }
    }
}
