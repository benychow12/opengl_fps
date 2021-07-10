#ifndef TD_RENDERER_H
#define TD_RENDERER_H

#include <glad/glad.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "c_shader.h"
#include "c_texture.h"

enum Shape
{
    Cube, 
    Triangle
};

class SimpleRender
{
public:
    SimpleRender(Shader &shader);
    ~SimpleRender();

    // mat4 for view for render
    glm::mat4 render_view;
    glm::mat4 render_projection;
    // Renders a defined 3d object
    void Draw3D(Shape shape, glm::vec3 position, glm::vec3 direction, glm::vec3 size, Texture2D &texture);

    void DrawBillboard(glm::mat4 matrix_model_view, Texture2D &texture);

private:
    // Render state
    Shader shader;
    unsigned int quadVAO;

    // Init and config quad's buffer and vertex attrib
    void initRenderData();
};

#endif
