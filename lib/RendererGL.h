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

	void fillShape(const std::vector<float>* polygon, int shapeType);

	void draw_polygon(const std::vector<float>& points);


private:
	void loadShader();
	bool checkShaderForCompileErrors(GLuint shader, std::string shaderType);
	bool checkShaderProgramForCompileErrors(GLuint shaderProgram);
	void loadBuffers();

	static void vertexCallback(GLvoid *vertex);
	void triangulatePolygon(const std::vector<float>& polygonVertices);

	std::vector<GLfloat> triangles;

	SDL_Window* window = nullptr;
	GLuint shaderProgramID = 0, VAO = 0, VBO = 0, EBO = 0;
	GLuint VAOHex = 0;

	std::vector<unsigned int> generateHexIndices(const std::vector<float>& vertices);

	static const char* vertexShaderSource;
	static const char* fragmentShaderSource;
};