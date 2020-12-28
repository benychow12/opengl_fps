#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <map>
#include <string>

#include <glad/glad.h>

// TODO
// #include "c_texture.h"
#include "c_shader.h"

// A static signleton ResourceManager class that hosts several functions
// to load Textures and Shaders. Each loaded texture and/or shader is also 
// stored for future reference by string handles. All functions and resources
// are static and no public constructor is defined.
class ResourceManager
{
public:
    // resource storage
    static std::map<std::string, Shader>    Shaders;
    // TODO
    // static std::map<std::string, Texture2D> Textures;

    // loads (and generates) a shader program from file loading vertex,
    // fragment (and geometry) shader's source code.
    // If gShaderFile is not nullptr, it also loads a geometry shader.
    static Shader LoadShader(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile, std::string name);
    // TODO
    // static Texture2D LoadTexture(const char* file, bool alpha, std::string name);
    
    // retrieves the stored shader/texture
    static Shader& GetShader(std::string name);
    // TODO
    // static Texture2D& GetTexture(std::string name);

    // De-allocates all loaded resources
    static void Clear();

private:
    // Private constructor because we don't want actual resource manager
    // objects. All member and funcs are publicaly static
    ResourceManager(){}

    // Loads and generates a shader from file
    static Shader loadShaderFromFile(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile = nullptr);

    // Loads a single texture from file
    // TODO
    // static Texture2D loadTextureFromFile(const char* file, bool alpha);
};

#endif
