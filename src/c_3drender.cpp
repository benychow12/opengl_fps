#include "c_3drender.h"

// debug
#include <iostream>
#include <glm/gtx/string_cast.hpp>

float cube_vertices[] = {
    // square face 1 (back)
    -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, // bottom left
    0.5f, -0.5f, -0.5f, 0.0f, 0.0f,// bottom right
    0.5f, 0.5f, -0.5f, 0.0f, 1.0f,// top right
    0.5f, 0.5f, -0.5f, 0.0f, 1.0f,// top right
    -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,// top left
    -0.5f, -0.5f, -0.5f, 1.0f, 0.0f,// bottom left
    // square face 2 (front))
    -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, // bottom left
    0.5f, -0.5f, 0.5f, 1.0f, 0.0f,// bottom right
    0.5f, 0.5f, 0.5f, 1.0f, 1.0f,// top right
    0.5f, 0.5f, 0.5f, 1.0f, 1.0f,// top right
    -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,// top left
    -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,// bottom left

    // Side well technically still a "front"
    -0.5f,  0.5f,  0.5f, 1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f, 0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
    -0.5f, -0.5f,  0.5f, 1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f, 1.0f, 1.0f,

    // side to right
     0.5f,  0.5f,  0.5f, 0.0f, 1.0f,
     0.5f,  0.5f, -0.5f, 1.0f, 1.0f,
     0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
     0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
     0.5f, -0.5f,  0.5f, 0.0f, 0.0f,
     0.5f,  0.5f,  0.5f, 0.0f, 1.0f,

     // bottom
    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
     0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
     0.5f, -0.5f,  0.5f, 1.0f, 0.0f,
     0.5f, -0.5f,  0.5f, 1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f, 0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

    // top
    -0.5f,  0.5f, -0.5f, 0.0f, 1.0f,
     0.5f,  0.5f, -0.5f, 1.0f, 1.0f,
     0.5f,  0.5f,  0.5f, 1.0f, 0.0f,
     0.5f,  0.5f,  0.5f, 1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f, 0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};

float triangle_vertices[] = {
    // bottom
    -0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
    0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 
    0.5f, -0.5f, 0.5f, 0.0f, 1.0f,
    0.5f, -0.5f, 0.5f, 0.0f, 1.0f,
    -0.5f, -0.5f, 0.5f, 1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, 1.0f, 0.0f,

    //side /|
    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
    0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
    -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,

    // side /|
    -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
    0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
    -0.5f, 0.5f, 0.5f, 1.0f, 1.0f,

    // back
    -0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
    -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 
    -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
    -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
    -0.5f, -0.5f, 0.5f, 1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, 1.0f, 0.0f,

    // Front slant
    -0.5f, 0.5f, -0.5f, 1.0f, 0.0f,
    -0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
    0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 
    0.5f, -0.5f, 0.5f, 1.0f, 1.0f,
    -0.5f, 0.5f, 0.5f, 1.0f, 0.0f
};

float plane_vertices[] = {
    // square face 1 (back)
    -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, // bottom left
    0.5f, -0.5f, -0.5f, 0.0f, 0.0f,// bottom right
    0.5f, 0.5f, -0.5f, 0.0f, 1.0f,// top right
    0.5f, 0.5f, -0.5f, 0.0f, 1.0f,// top right
    -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,// top left
    -0.5f, -0.5f, -0.5f, 1.0f, 0.0f,// bottom left
};

SimpleRender::SimpleRender(Shader &shader)
    : render_view(glm::mat4(1.0f)), render_projection(glm::mat4(1.0f))
{
    // Shader shader = &shader
    this->shader = shader;
    this->initRenderData();

    render_projection = glm::perspective(glm::radians(45.0f), (float)1.0, 0.1f, 100.0f);
}

SimpleRender::~SimpleRender()
{
    // delete 1 vao (our vao, quadvao)
    glDeleteVertexArrays(1, &this->quadVAO);
}

void SimpleRender::Draw3D(Shape shape, glm::vec3 position, glm::vec3 direction, glm::vec3 size, Texture2D &texture)
{
    // configure VAO/VBO
    unsigned int VBO;

    float *vertices;
    unsigned int vertices_size;

    if (shape == Cube)
    {
        vertices = cube_vertices;
        vertices_size = sizeof(cube_vertices);
    }
    else if (shape == Triangle)
    {
        vertices = triangle_vertices;
        vertices_size = sizeof(triangle_vertices);
    }

    glGenVertexArrays(1, &this->quadVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices_size, vertices, GL_STATIC_DRAW);

    glBindVertexArray(this->quadVAO);
    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coordinate attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
    // prepare the transforms
    this->shader.Use();
    glm::mat4 model = glm::mat4(1.0f);

    // Matrix multiplication are in reverse order:
    // 1. scale, 2. rotate, 3. translate
    model = glm::translate(model, glm::vec3(position.x, position.y, position.z));
    // model = glm::rotate(model, glm::radians(44.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::scale(model, size);
    // model = glm::scale(model, size);

    // 3d projection stuff
    this->shader.SetMatrix4("model", model);
    this->shader.SetMatrix4("view", this->render_view);
    this->shader.SetMatrix4("projection", this->render_projection);

    // render textured quad
    this->shader.SetVector3f("ourColor", glm::vec3(0.5f, 0.5f, 0.5f));

    // texture stuff
    glActiveTexture(GL_TEXTURE0);
    texture.Bind();

    glBindVertexArray(this->quadVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    // unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void SimpleRender::DrawBillboard(glm::mat4 matrix_model_view, Texture2D &texture)
{
    // configure VAO/VBO
    unsigned int VBO;

    float *vertices;
    unsigned int vertices_size;

    vertices = plane_vertices;
    vertices_size = sizeof(plane_vertices);

    glGenVertexArrays(1, &this->quadVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices_size, vertices, GL_STATIC_DRAW);

    glBindVertexArray(this->quadVAO);
    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coordinate attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
    // prepare the transforms
    this->shader.Use();

    // 3d projection stuff
    this->shader.SetMatrix4("view", this->render_view);
    this->shader.SetMatrix4("projection", this->render_projection);
    this->shader.SetMatrix4("model", matrix_model_view);

    // render textured quad
    this->shader.SetVector3f("ourColor", glm::vec3(0.5f, 0.5f, 0.5f));

    // texture stuff
    glActiveTexture(GL_TEXTURE0);
    texture.Bind();

    glBindVertexArray(this->quadVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    // unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
void SimpleRender::initRenderData()
{
}
