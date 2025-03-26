#include "Fjord.h"

// Create an SDL window with OpenGL
// NOTE: Please add error handling later!

bool Engine::create_window(std::string title, Vector2 size){
    printf("Starting SDL...");

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("init sdl failed\n");
        return false;
    }

    printf("Configuring SDL...");
    
    // Set OpenGL attributes for SDL 3
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    printf("Setting up window...");

    window = SDL_CreateWindow(title.c_str(), size.x, size.y, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    
    if (!window) {
        printf ("failed to create window\n");
        return false;
    }

    printf("Creating OpenGL context...");
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

    SDL_GL_SetSwapInterval(1);

    printf("Finished seeting up SDL");

    printf("Starting Shader Compilation...");

    Shader vertexShader("../lib/shaders/vertex_shader.glsl",GL_VERTEX_SHADER);
    Shader fragmentShader("../lib/shaders/fragment_shader.glsl",GL_FRAGMENT_SHADER);
    shaderManager.LinkShaders({vertexShader,fragmentShader});

    printf("Finished Compiling Shaders!");

    return true;
}

void Engine::destroy_window(){
    SDL_GL_DestroyContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
}