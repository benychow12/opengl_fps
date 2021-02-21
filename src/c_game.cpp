#include <iostream>

#include "c_game.h"
#include "c_resmanager.h"
#include "c_3drender.h"
#include "c_camera.h"
#include "c_gameobject.h"
#include "c_playerobject.h"
#include "c_enemyobject.h"
#include "c_colmanager.h"
#include "c_sprite.h"

#include "glm/gtx/string_cast.hpp"

// debug
#include <vector>

// Game-related state data
SimpleRender *Renderer;
SpriteRenderer* TwoDRenderer;
PlayerObject *Player;

// debug object
std::vector<GameObject*> bloobloo;
std::vector<EnemyObject*> EnemyObjs;
GameObject *bloo;
GameObject *bloo2;

Camera PlayerCamera(glm::vec3(5.0f, 0.5f, 5.0f));

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
    delete TwoDRenderer;
}

void Game::Init()
{
    std::cout << "Game init" << std::endl;

    // load the shaders
    ResourceManager::LoadShader("shaders/s_vertex.vs", "shaders/s_fragment.fs", nullptr, "shader_main");
    ResourceManager::GetShader("shader_main").Use();

    ResourceManager::LoadShader("shaders/s_sprite.vs", "shaders/s_sprite.fs", nullptr, "shader_sprite");
    ResourceManager::GetShader("shader_sprite").Use();

    // configure the shaders
    glm::mat4 td_projection = glm::ortho(0.0f, static_cast<float>(this->Width), static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("shader_sprite").SetMatrix4("projection", td_projection);

    glEnable(GL_DEPTH_TEST);
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    // set render-specific controls
    Renderer = new SimpleRender(ResourceManager::GetShader("shader_main"));

    TwoDRenderer = new SpriteRenderer(ResourceManager::GetShader("shader_sprite"));

    // DEBUG - should probably offload this a bit more
    // load textures
    ResourceManager::LoadTexture("assets/source.png", true, "def_placeholder");
    ResourceManager::LoadTexture("assets/tile066.png", true, "floor_tile");
    ResourceManager::LoadTexture("assets/shotgun.png", true, "player_shotgun");
    ResourceManager::LoadTexture("assets/enemy_1.png", true, "enemy_1");

    // Configure game objects
    Player = new PlayerObject(PlayerCamera.GetPosition(), glm::vec3(0.2f, 0.2f, 0.2f), PlayerCamera.GetFront());
    bloo = new  GameObject(glm::vec3(5.0f, 0.5f, 1.0f), glm::vec3(1.0f), ResourceManager::GetTexture("def_placeholder"), true);
    bloo2 = new GameObject(glm::vec3(0.0f, -0.5f, 0.0f), glm::vec3(100.0f, 0.5f, 100.0f), ResourceManager::GetTexture("floor_tile"), true);
    EnemyObject *enemy_1 = new EnemyObject(glm::vec3(1.0f, 0.5, -1.0f), glm::vec3(1.0f), glm::vec3(1.0f), 100, ResourceManager::GetTexture("enemy_1"));
    EnemyObject *enemy_2 = new EnemyObject(glm::vec3(2.0f, 0.5, -1.0f), glm::vec3(1.0f), glm::vec3(1.0f), 100, ResourceManager::GetTexture("enemy_1"));
    EnemyObject *enemy_3 = new EnemyObject(glm::vec3(4.0f, 0.5, -1.0f), glm::vec3(1.0f), glm::vec3(1.0f), 100, ResourceManager::GetTexture("enemy_1"));
    // DEBUG
    bloobloo.push_back(bloo);
    bloobloo.push_back(bloo2);
    EnemyObjs.push_back(enemy_1);
    EnemyObjs.push_back(enemy_2);
    EnemyObjs.push_back(enemy_3);
}

void Game::ProcessInput(float dt)
{
    if (this->State == GAME_ACTIVE)
    {
        if (this->Keys[GLFW_KEY_W])
        {
            PlayerCamera.ProcessKeyboardCamera(CAM_FORWARD, dt);            
        }
        if (this->Keys[GLFW_KEY_S])
        {
            PlayerCamera.ProcessKeyboardCamera(CAM_BACKWARD, dt);            
        }
        if (this->Keys[GLFW_KEY_A])
        {
            PlayerCamera.ProcessKeyboardCamera(CAM_LEFT, dt);            
        }
        if (this->Keys[GLFW_KEY_D])
        {
            PlayerCamera.ProcessKeyboardCamera(CAM_RIGHT, dt);            
        }
        if (this->Keys[GLFW_KEY_V])
        {
            // Debug
            std::cout << glfwGetTime() <<  "Toggling no clip" << std::endl;

            PlayerCamera.no_clip_toggle();
            Player->IsSolid = !Player->IsSolid;

            // To fix registering multiple events
            this->Keys[GLFW_KEY_V] = false;
        }

        if (this->Mouse[GLFW_MOUSE_BUTTON_LEFT])
        {
            std::cout << "left click" << std::endl;
            this->Mouse[GLFW_MOUSE_BUTTON_LEFT] = false;
            Player->player_action_shoot();

            // prob want some smaller vector of only objects near player
            for (int i = 0; i < EnemyObjs.size(); ++i)
            {
                bool hit = CollisionManager::CheckRaycastObject(PlayerCamera.GetPosition(), PlayerCamera.GetFront(), 1000, *EnemyObjs[i]);
                if (hit)
                {
                    EnemyObjs[i]->UpdateHealth(100);
                    if (EnemyObjs[i]->State == ENEMY_DEAD)
                    {
                        std::cout << "deleting object" << std::endl;
                        delete EnemyObjs[i];
                        EnemyObjs.erase(EnemyObjs.begin() + i);
                    }
                }


            }
        }
        if (this->Mouse[GLFW_MOUSE_BUTTON_RIGHT])
        {
            std::cout << "right click" << std::endl;
            this->Mouse[GLFW_MOUSE_BUTTON_RIGHT] = false;
        }


        PlayerCamera.ProcessMouseMovementCamera(cam_xoffset, cam_yoffset, true);
        // reset the offsets to avoid drifting
        cam_xoffset = 0.0f;
        cam_yoffset = 0.0f;
    }

}

void Game::Update(float dt)
{
    // Debug
  //   std::cout << "PlayerPosition: " << glm::to_string(PlayerCamera.GetPosition()) << std::endl;
  //   std::cout << "PlayerFront: " <<  glm::to_string(PlayerCamera.GetFront()) << std::endl;

    // if the player has moved then update the collisions?
    glm::vec3 CurrentPos = Player->Position;
    Player->Position = PlayerCamera.Position;
    for (auto &object : bloobloo)
    {
        if (CollisionManager::CheckAABB(*Player, *object))
        {
            PlayerCamera.Position = CurrentPos;
            Player->Position = CurrentPos;
        }
    }
}

void Game::Render(float dt)
{
    // stuff about updating the view and perspective to pass into render class
    // test draw
    glm::mat4 view = PlayerCamera.GetViewMatrix();
    Renderer->render_view = view;

    // // debug for game object
    // bloo->Draw(*Renderer);
    // bloo2->Draw(*Renderer);

    for (auto &object : bloobloo)
    {
        object->Draw(*Renderer);
    }
    for (auto &object : EnemyObjs)
    {
        object->Draw(*Renderer);
    }
    // Renderer->Draw3D(Triangle, glm::vec3(2.0f, 0.5f, 2.0f), glm::vec3(1.0f), ResourceManager::GetTexture("def_placeholder"));
    int texWidth = ResourceManager::GetTexture("player_shotgun").Width;
    int texHeight = ResourceManager::GetTexture("player_shotgun").Height;
    TwoDRenderer->DrawSprite(ResourceManager::GetTexture("player_shotgun"), glm::vec2((this->Width / 2) - 75, (this->Height - texHeight) - 20), glm::vec2(150.0f), 0.0f);
}
