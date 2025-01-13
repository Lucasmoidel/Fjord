#include "Fjord.h"


const char* RendererGL::vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec2 posIn;\n"
"uniform vec2 posUL;\n"
"uniform vec2 scaleWH;\n"
"out vec2 posFrag;\n"

"void main()\n"
"{\n"
"   gl_Position = vec4(posIn.x * scaleWH.x + posUL.x, posIn.y * scaleWH.y - posUL.y, 0.0, 1.0);\n"
"   posFrag = posIn + vec2(-1.0f, 1.0f);\n"
"}\0";


const char* RendererGL::fragmentShaderSource = "#version 330 core\n"
"in vec2 posFrag;\n"
"uniform float sizePixel;\n"
"uniform vec4 drawColor;\n"
"uniform int shapeType;\n"
"out vec4 FragColor;\n"

//Functions for drawing each shape
"void fillOval() {\n"
"    float distance = 1.0 - sqrt(posFrag.x * posFrag.x + posFrag.y * posFrag.y) + sizePixel / 2.0;\n"
"    float alpha = clamp(distance / sizePixel, 0.0, 1.0);\n"
"    if (alpha < 0.01f)\n"
"        discard;\n"
"    FragColor  = vec4(drawColor.xyz, drawColor.w * alpha);\n"
"}\n"

"void fillRectangle() {\n"
"    FragColor = drawColor;\n"
"}\n"


//Draw the shape, default to rectangle
"void main()\n"
"{\n"
"    switch (shapeType) {\n"
"        case 1:  fillOval();  break;\n"
"        default: fillRectangle();  break;\n"
"    }\n"
"}\n\0";




RendererGL::RendererGL(SDL_Window* setWindow) :
	window(setWindow) {
	loadShader();
	loadBuffers();
	//Set the default color.
	setDrawColor(255, 255, 255, 255);
}


RendererGL::~RendererGL() {
	//Clean up.
	if (shaderProgramID > 0)
		glDeleteProgram(shaderProgramID);

	if (VAO > 0)
		glDeleteVertexArrays(1, &VAO);
	if (VBO > 0)
		glDeleteBuffers(1, &VBO);
	if (EBO > 0)
		glDeleteBuffers(1, &EBO);
}



void RendererGL::loadShader() {
	//Create the vertex shader.
	const GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderID, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShaderID);
	//Check for errors when creating the shader.
	if (!checkShaderForCompileErrors(vertexShaderID, "vertex shader")) {
		glDeleteShader(vertexShaderID);
		return;
	}

	//Create the fragment shader.
	const GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderID, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShaderID);
	//Check for errors when creating the shader.
	if (!checkShaderForCompileErrors(fragmentShaderID, "fragment shader")) {
		glDeleteShader(vertexShaderID);
		glDeleteShader(fragmentShaderID);
		return;
	}

	//Create the shader program.
	shaderProgramID = glCreateProgram();
	glAttachShader(shaderProgramID, vertexShaderID);
	glAttachShader(shaderProgramID, fragmentShaderID);
	glLinkProgram(shaderProgramID);
	//Check for errors when creating the shader program.
	if (!checkShaderProgramForCompileErrors(shaderProgramID)) {
		glDeleteShader(vertexShaderID);
		glDeleteShader(fragmentShaderID);
		glDeleteProgram(shaderProgramID);
		return;
	}

	std::cout << "Shader program created correctly" << std::endl;


	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);

	glUseProgram(shaderProgramID);
}


bool RendererGL::checkShaderForCompileErrors(GLuint shader, std::string shaderType) {
	//Check the shader for errors.
	GLint statusShader;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &statusShader);
	if (statusShader == GL_FALSE) {
		//Get the error message and output it.
		GLint length;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
		std::vector<char> errorMessage(length);
		glGetShaderInfoLog(shader, length, &length, &errorMessage[0]);
		std::cout << "ERROR: problem creating " << shaderType << std::endl << 
			&errorMessage[0] << std::endl;
		return false;
	}
	return true;
}


bool RendererGL::checkShaderProgramForCompileErrors(GLuint shaderProgram) {
	//Check the shader program for errors.
	GLint statusShaderProgram;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &statusShaderProgram);
	if (statusShaderProgram == GL_FALSE) {
		//Get the error message and output it.
		GLint length;
		glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &length);
		std::vector<char> errorMessage(length);
		glGetProgramInfoLog(shaderProgram, length, &length, &errorMessage[0]);
		std::cout << "ERROR: problem creating shader program " << std::endl << 
			&errorMessage[0] << std::endl;
		return false;
	}
	return true;
}


void RendererGL::loadBuffers() {
	float vertices[] = {
		2.0f,  0.0f,	// Right Top
		2.0f, -2.0f,	// Right Bottom
		0.0f, -2.0f,	// Left Bottom
		0.0f,  0.0f		// Left Top
	};

	unsigned int indices[] = {
		0, 1, 3,	//First Triangle
		1, 2, 3		//Second Triangle
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);
}



void RendererGL::setDrawColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
	glUniform4f(glGetUniformLocation(shaderProgramID, "drawColor"),
		(float)(r / 255.0f), (float)(g / 255.0f), (float)(b / 255.0f), (float)(a / 255.0f));
}


void RendererGL::fillRect(const SDL_Rect* rect) {
	//fillShape(rect, 0);
}


void RendererGL::fillOval(const SDL_Rect* rect) {
	//fillShape(rect, 1);
}

std::vector<unsigned int> RendererGL::generateHexIndices(const std::vector<float>& vertices) {
    std::vector<unsigned int> indices;
    int numVertices = vertices.size() / 2; // Assuming each vertex has x and y components
    // Generate indices based on the vertices for hexagon
    for (int i = 0; i < numVertices - 2; ++i) {
        indices.push_back(0);
        indices.push_back(i + 1);
        indices.push_back(i + 2);
    }
    return indices;
}




void RendererGL::fillShape(const std::vector<float>* polygon, int shapeType) {
	// Hexagon vertices and indices

	std::vector<unsigned int> indices = generateHexIndices(*polygon);

	// Loading data into buffers and setting VAO if not already
	glGenVertexArrays(1, &VAOHex);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAOHex);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(polygon), polygon, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0); // Unbind VAO

	// Updating draw call:
	glBindVertexArray(VAOHex);
	glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);

}
