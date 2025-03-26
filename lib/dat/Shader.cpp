#include "../Fjord.h"

std::string Shader::GetShaderSource(std::string filePath){
    std::ifstream file(filePath);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

GLuint Shader::CompileShader(std::string filePath, GLenum type){
    GLuint shader = glCreateShader(type);
    const char* shaderCode = GetShaderSource(filePath).c_str();
    glShaderSource(shader,1,&shaderCode,nullptr);
    glCompileShader(shader);
    GLint success;
    glGetShaderiv(shader,GL_COMPILE_STATUS,&success);
    if (!success){
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "Error: " << infoLog << std::endl;
    }
    GLuint shaderProgram = glCreateProgram();
    
}