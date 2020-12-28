#include <iostream>
#include "c_3drender.h"

SimpleRender::SimpleRender(Shader &shader)
{
    // Shader shader = &shader
    this->shader = shader;
    this->initRenderData();
}

SimpleRender::~SimpleRender()
{
    // delete 1 vao (our vao, quadvao)
    glDeleteVertexArrays(1, &this->quadVAO);
}

void SimpleRender::Draw3D(glm::vec3 position)
{
    // prepare the transforms
    this->shader.Use();
    glm::mat4 model = glm::mat4(1.0f);

    // Matrix multiplication are in reverse order:
    // 1. scale, 2. rotate, 3. translate
    // model = glm::translate(model, glm::vec3(position));
    model = glm::rotate(model, glm::radians(position.x), glm::vec3(1.0f, 0.3f, 0.5f));

    // set the shader vertex shader
    this->shader.SetMatrix4("model", model);

    // Debug
    // 3d projection stuff
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(45.0f), (float)1.0, 0.1f, 100.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    this->shader.SetMatrix4("view", view);
    this->shader.SetMatrix4("projection", projection);

    // render textured quad
    this->shader.SetVector3f("ourColor", glm::vec3(0.5f, 0.5f, 0.5f));

    glBindVertexArray(this->quadVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

void SimpleRender::initRenderData()
{
    // debug 
    std::cout << "initRenderData" << std::endl;

    // configure VAO/VBO
    unsigned int VBO;

    // quad (3d square) vertices
    float vertices[] = {
        // square face 1 (back)
        -0.5f, -0.5f, -0.5f, // 0.0f, 0.0f, // bottom left
        0.5f, -0.5f, -0.5f,  // 1.0f, 0.0f,// bottom right
        0.5f, 0.5f, -0.5f,   // 1.0f, 1.0f,// top right
        0.5f, 0.5f, -0.5f,   // 1.0f, 1.0f,// top right
        -0.5f, 0.5f, -0.5f,  // 0.0f, 1.0f,// top left
        -0.5f, -0.5f, -0.5f, // 0.0f, 0.0f,// bottom left
        // square face 2 (front))
        -0.5f, -0.5f, 0.5f, // 0.0f, 0.0f, // bottom left
        0.5f, -0.5f, 0.5f,  // 1.0f, 0.0f,// bottom right
        0.5f, 0.5f, 0.5f,   // 1.0f, 1.0f,// top right
        0.5f, 0.5f, 0.5f,   // 1.0f, 1.0f,// top right
        -0.5f, 0.5f, 0.5f,  // 0.0f, 1.0f,// top left
        -0.5f, -0.5f, 0.5f, // 0.0f, 0.0f,// bottom left

        -0.5f,  0.5f,  0.5f, // 1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, // 1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, // 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, // 0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f, // 0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f, // 1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  //1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  //1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  //0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  //0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  //0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  //1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  //0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  //1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  //1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  //1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  //0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  //0.0f, 1.0f,

        // top
        -0.5f,  0.5f, -0.5f,  //0.0f, 10.0f,
         0.5f,  0.5f, -0.5f,  //10.0f, 10.0f,
         0.5f,  0.5f,  0.5f,  //10.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  //10.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  //0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f  //0.0f, 10.0f
    };
    /*
    float vertices[] = {
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };
    */

    glGenVertexArrays(1, &this->quadVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(this->quadVAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // unbind
    // glBindBuffer(GL_ARRAY_BUFFER, 0);
    // glBindVertexArray(0);
}
