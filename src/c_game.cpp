#include <iostream>

#include "c_game.h"
#include "c_resmanager.h"
#include "c_3drender.h"

#include "glm/gtx/string_cast.hpp"

// Game-related state data
SimpleRender *Renderer;

Game::Game(unsigned int width, unsigned int height)
    : State(GAME_ACTIVE), Width(width), Height(height)
{

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

}

void Game::Update(float dt)
{

}

void Game::Render(float dt)
{
    // debug
    std::cout << "Render()" << std::endl;

    // test draw
    Renderer->Draw3D(glm::vec3(glfwGetTime() * 10, 0.0f, 0.0f));
}
