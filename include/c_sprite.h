#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include <glad/glad.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "c_texture.h"
#include "c_shader.h"

class SpriteRenderer
{
public:
    SpriteRenderer(Shader &shader);
    ~SpriteRenderer();

    // Renders a defined quad textured with given sprite
    void DrawSprite(Texture2D &texture, glm::vec2 position, glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f));
private:
    // Render state
    Shader shader;
    unsigned int quadVAO;

    // Initializes and configs the quad's buffer and vertex attribs
    void initRenderData();
};
#endif
