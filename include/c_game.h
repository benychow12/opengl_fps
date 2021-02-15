#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Represents current state of the game
enum Gamestate
{
    GAME_ACTIVE
};

// Game directions for collision
enum Direction
{
    COL_UP, 
    COL_RIGHT, 
    COL_DOWN,
    COL_LEFT 
};

// Collision typedef that represents collision data
// <collision?, what direction?>
// typedef std::tuple<bool, Direction, glm::vec3> Collision;

// Game class holds all game-related state and functionality
class Game
{
public:
    // game state
    Gamestate State;
    bool Keys[1024];
    bool Mouse[5];
    unsigned int Width, Height;
    // camera
    float cam_lastX, cam_lastY, cam_xoffset, cam_yoffset;
    bool firstMouse;

    Game(unsigned int width, unsigned int height);
    ~Game();

    // initialize game state (shaders/texture/levels)
    void Init();

    // game main loop
    void ProcessInput(float dt);
    void Update(float dt);
    void Render(float dt);

    // Collision
    void DoCollisions();
    // resets
};

#endif
