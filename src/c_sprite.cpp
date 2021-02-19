#include "c_sprite.h"

SpriteRenderer::SpriteRenderer(Shader &shader)
{
    // Shader shader = &shader
    this->shader = shader;
    this->initRenderData();
}

SpriteRenderer::~SpriteRenderer()
{
    // delete 1 vao (our vao, quadvao)
    glDeleteVertexArrays(1, &this->quadVAO);
}

void SpriteRenderer::DrawSprite(Texture2D &texture, glm::vec2 position, glm::vec2 size, float rotate, glm::vec3 color)
{
    // prepare the transforms
    this->shader.Use();
    glm::mat4 model = glm::mat4(1.0f);

    // Matrix multiplication are reverse order:
    // 1. scale, 2. rotate, 3. translate
    model = glm::translate(model, glm::vec3(position, 0.0f));
    // move origin of rotation to center of quad?
    // model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
    // model = glm::rotate(model, glm::radians(rotate), glm::vec3(0.0f, 0.0f, 1.0f));
    // model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));
    model = glm::scale(model, glm::vec3(size, 1.0f));

    // set the shader vertex shader
    this->shader.SetMatrix4("model", model);

    // render textured quad
    this->shader.SetVector3f("spriteColor", color);

    glActiveTexture(GL_TEXTURE0);
    texture.Bind();

    glBindVertexArray(this->quadVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void SpriteRenderer::initRenderData()
{
    // configure VAO/VBO
    unsigned int VBO;

    // quad verticies
    float vertices[] = {
        //pos       // tex
        0.0f, 1.0f, 1.0f, 0.0f,
        1.0f, 0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 1.0f, 1.0f, 0.0f,
        1.0f, 1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f, 1.0f
    };

    glGenVertexArrays(1, &this->quadVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(this->quadVAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    // Unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
