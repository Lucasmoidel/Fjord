#include "Fjord.h"

// Create an SDL window with OpenGL
bool Engine::create_window(std::string title, Vector2 size){
    SDL_Window* window = SDL_CreateWindow(title.c_str(), size.x, size.y, SDL_WINDOW_OPENGL);

    // Create the OpenGL context
    SDL_GLContext context = SDL_GL_CreateContext(window);

    // Set OpenGL attributes for SDL 3
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
}