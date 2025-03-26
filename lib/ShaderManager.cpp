#include "Fjord.h"

GLuint ShaderManager::LinkShaders(std::vector<Shader> shaders){
    GLuint program = glCreateProgram();
    for (const auto& shader : shaders){
        glAttachShader(program,shader.shaderId);
    }
    glLinkProgram(program);

    GLint success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        std::cerr << "Program Linking Error: " << infoLog << std::endl;
    }

    return program;
}