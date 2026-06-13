#ifndef SHADER_MANAGER_H
#define SHADER_MANAGER_H

#include "Fjord.h"

class ShaderManager {
    public:
        GLuint LinkShaders(std::vector<Shader> shaders);
};

#endif