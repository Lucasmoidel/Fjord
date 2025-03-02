#pragma once
#include "Fjord.h"


class RendererGL
{
public:
	RendererGL(SDL_Window* setWindow);
	~RendererGL();
	void setDrawColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
	void fillRect(const SDL_Rect* rect);
	void fillOval(const SDL_Rect* rect);


private:
	void loadShader();
	bool checkShaderForCompileErrors(GLuint shader, std::string shaderType);
	bool checkShaderProgramForCompileErrors(GLuint shaderProgram);
	void loadBuffers();
	void fillShape(const SDL_Rect* rect, int shapeType);


	SDL_Window* window = nullptr;
	GLuint shaderProgramID = 0, VAO = 0, VBO = 0, EBO = 0;

	static const char* vertexShaderSource;
	static const char* fragmentShaderSource;
};