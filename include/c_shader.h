#ifndef SHADER_H
#define SHADER_H

#include <string>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

// General purpose shader object. 
// Compiles from file, generates compile/link-time error messags and hosts
// utility funcs

class Shader
{
public:
    // state?
    unsigned int ID;

    // constructor
    Shader(){}

    // sets the current shader as active
    Shader& Use();

    // compile the shader from given source
    void Compile(const char* vertexSource, const char* fragmentSource, const char* geometrySource = nullptr);

    // utility funcs...
    void SetFloat(const char* name, float value, bool useShader = false);
    void SetInteger(const char* name, int value, bool useShader = false);
    // from scalars
    void SetVector2f(const char* name, float x, float y, bool useShader = false);
    // from vec2
    void SetVector2f(const char* name, const glm::vec2 &value, bool userShader = false);
    // from scalars
    void SetVector3f(const char* name, float x, float y, float z, bool useShader = false);
    // from vec3
    void SetVector3f(const char* name, const glm::vec3 &value, bool useShader = false);
    // from scalars
    void SetVector4f(const char* name, float x, float y, float z, float w, bool useShader = false);
    // from vec4
    void SetVector4f(const char* name, const glm::vec4 &value, bool useShader = false);
    void SetMatrix4(const char* name, const glm::mat4 &matrix, bool useShader = false);

private:
    // compilation check
    void checkCompileErrors(unsigned int object, std::string type);
};

#endif
