#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Represents current state of the game
enum Gamestate
{
    GAME_ACTIVE
};

// Game class holds all game-related state and functionality
class Game
{
public:
    // game state
    Gamestate State;
    unsigned int Width, Height;

    Game(unsigned int width, unsigned int height);
    ~Game();

    // initialize game state (shaders/texture/levels)
    void Init();

    // game main loop
    void ProcessInput(float dt);
    void Update(float dt);
    void Render(float dt);

    // resets
};

#endif
