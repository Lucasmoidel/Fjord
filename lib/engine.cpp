#include "Fjord.h"

// Create an SDL window with OpenGL
// NOTE: Please add error handling later!

bool Engine::create_window(std::string title, Vector2 size){
    printf("Starting SDL...\n");

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("init sdl failed\n");
        return false;
    }

    if (!TTF_Init()) {
        printf("init sdl_ttf failed\n");
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
    Shader texVertexShader("../lib/shaders/vertex_shader_texture.glsl",GL_VERTEX_SHADER);
    Shader texFragmentShader("../lib/shaders/fragment_shader_texture.glsl",GL_FRAGMENT_SHADER);
    shaderProgram = shaderManager.LinkShaders({vertexShader,fragmentShader});
    texShaderProgram = shaderManager.LinkShaders({texVertexShader,texFragmentShader});
    printf("Finished Compiling Shaders!\n");

    updateWindowSize();

    return true;
}

void Engine::updateWindowSize() {
    // Update viewport
    glViewport(0, 0, screen_size.x, screen_size.y);

    // Set up orthographic projection for pixel coordinates
    // (0, 0) at top-left, (screen_size.x, screen_size.y) at bottom-right
    projection = glm::ortho(0.0f, (float)screen_size.x, (float)screen_size.y, 0.0f, -1.0f, 1.0f);

    // If you have a shader program, update the projection matrix uniform
    // Example: Assuming you have a shader program and uniform location
    glUseProgram(shaderProgram); // Replace with your shader program ID
    GLint projMatrixLocation = glGetUniformLocation(shaderProgram, "projection");
    glUniformMatrix4fv(projMatrixLocation, 1, GL_FALSE, glm::value_ptr(projection));
}

void Engine::destroy_window(){
    SDL_GL_DestroyContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
}