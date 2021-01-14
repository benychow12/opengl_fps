#include <iostream>

#include "c_game.h"
#include "c_resmanager.h"
#include "c_3drender.h"
#include "c_camera.h"

#include "glm/gtx/string_cast.hpp"

// Game-related state data
SimpleRender *Renderer;

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
}

void Game::ProcessInput(float dt)
{
    if (this->State == GAME_ACTIVE)
    {
        if (this->Keys[GLFW_KEY_W])
        {
            // std:: cout << "W pressed..." << std::endl;
            PlayerCamera.ProcessKeyboardCamera(FORWARD, dt);            
        }
        if (this->Keys[GLFW_KEY_S])
        {
            // std::cout << "S pressed..." << std::endl;
            PlayerCamera.ProcessKeyboardCamera(BACKWARD, dt);            
        }
        if (this->Keys[GLFW_KEY_A])
        {
            // std::cout << "A pressed..." << std::endl;
            PlayerCamera.ProcessKeyboardCamera(LEFT, dt);            
        }
        if (this->Keys[GLFW_KEY_D])
        {
            // std::cout << "D pressed..." << std::endl;
            PlayerCamera.ProcessKeyboardCamera(RIGHT, dt);            
        }

        PlayerCamera.ProcessMouseMovementCamera(cam_xoffset, cam_yoffset);
        // reset the offsets to avoid drifting
        cam_xoffset = 0.0f;
        cam_yoffset = 0.0f;

        // debug
        glm::vec3 PlayerPos = PlayerCamera.GetPosition();
        std::cout << "Player Position..." << std::endl;
        std::cout << PlayerPos.x << std::endl;
        std::cout << PlayerPos.y << std::endl;
        std::cout << PlayerPos.z << std::endl;

    }

}

void Game::Update(float dt)
{

}

void Game::Render(float dt)
{
    // test draw
    glm::mat4 view = PlayerCamera.GetViewMatrix();
    Renderer->Draw3D(glm::vec3(0.0f, 0.0f, 0.0f), view);
    Renderer->Draw3D(glm::vec3(5.0f, 0.0f, 0.0f), view);
}
