#include "./Fjord.h"

GLuint Renderer::compileShaders(){
    
}

void Renderer::render(std::vector<RenderCall> *renderCalls){
    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    
    

    // Swap buffers
    SDL_GL_SwapWindow(engine.window);
}