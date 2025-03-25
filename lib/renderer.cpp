#include "./Fjord.h"

void Renderer::render(){
    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Swap buffers
    SDL_GL_SwapWindow(engine.window);
}