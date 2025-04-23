#include "./Fjord.h"

GLuint Renderer::compileShaders(){
    
}

void Renderer::render(std::vector<RenderCall> &renderCalls) {

    glUseProgram(engine.shaderProgram);
    // Clear the screen
    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    GLuint VBO, VAO;
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    //printf("Render:\r \n",*renderCalls);

    const std::vector<RenderCall> rcs = renderCalls;

    for (const RenderCall& rc : rcs) {
        switch (rc.type)
        {
        case RenderCall::POLYGON:
            if (rc.vertices->size() > 0) {
                //printf("RenderTime");
                // Upload vertex data to the GPU
                glVertexAttrib4f(1, 1.0f, 1.0f, 1.0f, 1.0f); // Set color to white (RGBA)
                glBufferData(GL_ARRAY_BUFFER, rc.vertices->size() * sizeof(float), rc.vertices->data(), GL_STATIC_DRAW);
                // Enable vertex attribute array
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
                glEnableVertexAttribArray(0);

                // Draw the convex polygon using GL_TRIANGLE_FAN
                glDrawArrays(GL_TRIANGLE_FAN, 0, rc.vertices->size() / 2);

                // Disable attribute array after use (optional cleanup)
                glDisableVertexAttribArray(0);
            }
            break;
        case RenderCall::TEXT:
            SDL_Surface* textSurface = TTF_RenderText_Blended(rc.font, rc.text.c_str(), rc.text.length(), (SDL_Color){255, 255, 255, 255});

            GLuint textTexture;
            glGenTextures(1, &textTexture);
            glBindTexture(GL_TEXTURE_2D, textTexture);
            
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textSurface->w, textSurface->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, textSurface->pixels);
            
            // Set texture parameters
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            int width = textSurface->w;
            int height = textSurface->h;
            SDL_DestroySurface(textSurface);
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, textTexture);

            // Draw quad
            glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex2f(0, 0);
            glTexCoord2f(1, 0); glVertex2f(0 + width, 0);
            glTexCoord2f(1, 1); glVertex2f(0 + width, 0 + height);
            glTexCoord2f(0, 1); glVertex2f(0, 0 + height);
            glEnd();
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(0, 800, 800, 0, -1, 1);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glDeleteTextures(1, &textTexture);
            std::cout << SDL_GetError() << glGetError() << "\n";
            break;
        }
    }

    // Clean up
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);

    // Swap the buffers to present the rendered frame
    SDL_GL_SwapWindow(engine.window);
}
