#include "Fjord.h"

// Create an SDL window with OpenGL
// NOTE: Please add error handling later!
bool Engine::create_window(std::string title, Vector2 size){
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(title.c_str(), size.x, size.y, SDL_WINDOW_OPENGL);

    // Create the OpenGL context
    glContext = SDL_GL_CreateContext(window);

    // Set OpenGL attributes for SDL 3
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_SetWindowResizable(window, true);

    glewExperimental = GL_TRUE; // Ensure modern OpenGL extensions are loaded
    GLenum err = glewInit();

    return 1;
}

bool Engine::destroy_window(){
    SDL_GL_DestroyContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
}