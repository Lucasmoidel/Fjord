#ifndef SHADER_H
#define SHADER_H

#include "../Fjord.h"

class Shader {
    public:
        GLuint shaderId;
        GLenum shaderType;
        
        Shader(std::string filePath, GLenum type) : shaderType(type) {
            shaderId = CompileShader(filePath, type);
            printf("GLuint value: %u\n", shaderId);
        }


        ~Shader() {
            // Clean up shader resources
            glDeleteShader(shaderId);
        }

        std::string GetShaderSource(std::string filePath);
        GLuint CompileShader(std::string filePath, GLenum type);
};

#endif