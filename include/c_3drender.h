#ifndef TD_RENDERER_H
#define TD_RENDERER_H

#include <glad/glad.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "c_shader.h"

class SimpleRender
{
public:
    SimpleRender(Shader &shader);
    ~SimpleRender();

    // Renders a defined 3d object
    void Draw3D(glm::vec3 position, glm::mat4 playerview);
private:
    // Render state
    Shader shader;
    unsigned int quadVAO;

    // Init and config quad's buffer and vertex attrib
    void initRenderData();
};

#endif
