#include "../Fjord.h"

std::string Shader::GetShaderSource(std::string filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open shader file: " + filePath);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

GLuint Shader::CompileShader(std::string filePath, GLenum type) {
    // Create the shader object
    GLuint shader = glCreateShader(type);
    if (shader == 0) {
        throw std::runtime_error("Failed to create shader");
    }

    std::string shaderSource = GetShaderSource(filePath);
    const char* shaderCode = shaderSource.c_str();
    glShaderSource(shader, 1, &shaderCode, nullptr);
    glCompileShader(shader);

    // Check for compilation errors
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "Shader Compilation Error (File: " << filePath << "): " << infoLog << std::endl;
        glDeleteShader(shader); // Clean up the failed shader
        throw std::runtime_error("Shader compilation failed: " + std::string(infoLog));
    }

    // Debug output
    printf("Successfully compiled Shader (Type %d, File: %s) - ID: %u\n", type, filePath.c_str(), shader);

    return shader; // Return the compiled shader ID
}
