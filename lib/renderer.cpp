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
            int x,y = 0;
            // Render the text to an SDL_Surface
            SDL_Surface* surface = TTF_RenderText_Solid(rc.font, rc.text.c_str(), rc.text.length(), {255, 255, 255, 255});
            if (!surface) {
                SDL_Log("Unable to render text to surface: %s", SDL_GetError());
                return;
            }
        
            // Retrieve pixel format details
            const SDL_PixelFormatDetails* format_details = SDL_GetPixelFormatDetails(surface->format);
            if (!format_details) {
                SDL_Log("Unable to get pixel format details: %s", SDL_GetError());
                SDL_DestroySurface(surface);
                return;
            }
        
            // Determine texture format based on the pixel format
            GLenum texture_format = (format_details->bytes_per_pixel == 4) ? GL_RGBA : GL_RGB;
        
            // Generate an OpenGL texture from the surface
            GLuint texture;
            glGenTextures(1, &texture);
            glBindTexture(GL_TEXTURE_2D, texture);
        
            glTexImage2D(GL_TEXTURE_2D, 0, texture_format, surface->w, surface->h, 0,
                         texture_format, GL_UNSIGNED_BYTE, surface->pixels);
        
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
            // Enable blending for transparency
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        
            // Render the texture
            glBegin(GL_QUADS);
                glTexCoord2f(0.0f, 0.0f); glVertex2f(x, y);
                glTexCoord2f(1.0f, 0.0f); glVertex2f(x + surface->w, y);
                glTexCoord2f(1.0f, 1.0f); glVertex2f(x + surface->w, y + surface->h);
                glTexCoord2f(0.0f, 1.0f); glVertex2f(x, y + surface->h);
            glEnd();
        
            // Clean up
            glDisable(GL_BLEND);
            glDeleteTextures(1, &texture);
            SDL_DestroySurface(surface);
            std::cout << glGetError() << "\n";

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
