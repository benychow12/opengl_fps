#include "c_3drender.h"

float cube_vertices[] = {
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

float triangle_vertices[] = {
    // bottom
    -0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, -0.5f, 
    0.5f, -0.5f, 0.5f,
    0.5f, -0.5f, 0.5f,
    -0.5f, -0.5f, 0.5f,
    -0.5f, -0.5f, -0.5f,

    //side /|
    -0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, -0.5f,
    -0.5f, 0.5f, -0.5f,

    // side /|
    -0.5f, -0.5f, 0.5f,
    0.5f, -0.5f, 0.5f,
    -0.5f, 0.5f, 0.5f,

    // back
    -0.5f, -0.5f, -0.5f,
    -0.5f, 0.5f, -0.5f,
    -0.5f, 0.5f, 0.5f,
    -0.5f, 0.5f, 0.5f,
    -0.5f, -0.5f, 0.5f,
    -0.5f, -0.5f, -0.5f,

    // Front slant
    -0.5f, 0.5f, -0.5f, 
    -0.5f, 0.5f, 0.5f,
    0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, 0.5f,
    -0.5f, 0.5f, 0.5f
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

void SimpleRender::Draw3D(Shape shape, glm::vec3 position, glm::vec3 size)
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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    // prepare the transforms
    this->shader.Use();
    glm::mat4 model = glm::mat4(1.0f);

    // Matrix multiplication are in reverse order:
    // 1. scale, 2. rotate, 3. translate
    model = glm::scale(model, size);
    model = glm::translate(model, glm::vec3(position.x, position.y, position.z));
    // model = glm::scale(model, size);
    // model = glm::rotate(model, glm::radians(position.x), glm::vec3(1.0f, 0.3f, 0.5f));

    // 3d projection stuff
    this->shader.SetMatrix4("model", model);
    this->shader.SetMatrix4("view", this->render_view);
    this->shader.SetMatrix4("projection", this->render_projection);

    // render textured quad
    this->shader.SetVector3f("ourColor", glm::vec3(0.5f, 0.5f, 0.5f));

    glBindVertexArray(this->quadVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    // unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void SimpleRender::initRenderData()
{
}
