#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <c_shader.h>
#include <c_resmanager.h>
#include <c_game.h>

#include <iostream>

// width of game
const unsigned int SCREEN_WIDTH = 640;
const unsigned int SCREEN_HEIGHT = 480;

// Game class
Game Doomu(SCREEN_WIDTH, SCREEN_HEIGHT);

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure viewport matches new window dimensions
    glViewport(0, 0, width, height);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button >= 0 && button < 5)
    {
        if (action == GLFW_PRESS)
        {
            Doomu.Mouse[button] = true;
        }
        else if (action == GLFW_RELEASE)
        {
            Doomu.Mouse[button] = false;
        }
    }
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    // debug
    // close application when esc is pressed
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }

    // register possible keys
    if (key >= 0 && key < 1024)
    {
        if (action == GLFW_PRESS)
        {
            Doomu.Keys[key] = true;
        }
        else if (action == GLFW_RELEASE)
        {
            Doomu.Keys[key] = false;
        }
    }
}

void mouse_callback(GLFWwindow *window, double mouse_xpos, double mouse_ypos)
{
    // debug
    // std::cout << "mouse callback" << std::endl;

    if (Doomu.firstMouse)
    {
        // debug
        std::cout << "First mouse" << std::endl;
        Doomu.cam_lastX = mouse_xpos;
        Doomu.cam_lastY = mouse_ypos;
        Doomu.firstMouse = false;
    }

    Doomu.cam_xoffset = mouse_xpos - Doomu.cam_lastX;
    Doomu.cam_yoffset = Doomu.cam_lastY - mouse_ypos;
    
    Doomu.cam_lastX = mouse_xpos;
    Doomu.cam_lastY = mouse_ypos;
}

int main(int argc, char* argv[])
{
    // initial setup glfw
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, false);

    // create the window
    GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Doomu", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    // glad: load all opengl functional pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Callbacks for viewport and kb
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);

    // OpenGL Configuration
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Init the game
    Doomu.Init();

    // Deltatime variables
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        // calculate delta time
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        glfwPollEvents();

        // manager user input
        Doomu.ProcessInput(1.0f);

        // update game state
        Doomu.Update(1.0f);

        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        Doomu.Render(deltaTime);

        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}
