#include "Fjord.h"

// Create an SDL window with OpenGL
// NOTE: Please add error handling later!

bool Engine::create_window(std::string title, Vector2 size){
    printf("Starting SDL...\n");

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("init sdl failed\n");
        return false;
    }

    printf("Configuring SDL...\n");
    
    // Set OpenGL attributes for SDL 3
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    printf("Setting up window...\n");

    window = SDL_CreateWindow(title.c_str(), size.x, size.y, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    
    if (!window) {
        printf ("failed to create window\n");
        return false;
    }

    printf("Creating OpenGL context...\n");
    // Create the OpenGL context
    glContext = SDL_GL_CreateContext(window);


    if (!glContext) {
        printf ("failed to create glContext\n");
        return false;
    }


	glewExperimental = GL_TRUE;
	GLenum glewError = glewInit();
    if (glewInit() != GLEW_OK) {
		std::cout << "Error initializing GLEW = " << glewGetErrorString(glewError) << std::endl;
		return false;
	}
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glViewport(0, 0, size.x, size.y);
    screen_size = size;

    SDL_GL_SetSwapInterval(1);

    printf("Finished seeting up SDL\n");

    printf("Starting Shader Compilation...\n");

    Shader vertexShader("../lib/shaders/vertex_shader.glsl",GL_VERTEX_SHADER);
    Shader fragmentShader("../lib/shaders/fragment_shader.glsl",GL_FRAGMENT_SHADER);
    shaderProgram = shaderManager.LinkShaders({vertexShader,fragmentShader});

    printf("Finished Compiling Shaders!\n");

    updateWindowSize();

    return true;
}

void Engine::updateWindowSize() {
    // Update viewport
    glViewport(0, 0, screen_size.x, screen_size.y);

    // Calculate orthographic projection matrix
    float aspectRatio = (float)screen_size.x / (float)screen_size.y;
    float orthoSize = 1.0f; // Base size of view
    float width = orthoSize * std::max(aspectRatio, 1.0f);
    float height = orthoSize * std::max(1.0f / aspectRatio, 1.0f);

    projection = glm::ortho(-width, width, -height, height, -1.0f, 1.0f);
}

void Engine::destroy_window(){
    SDL_GL_DestroyContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
}