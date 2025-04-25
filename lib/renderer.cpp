#include "./Fjord.h"

GLuint Renderer::compileShaders(){
    
}

void Renderer::render(std::vector<RenderCall> &renderCalls) {

    glUseProgram(engine.shaderProgram);
    // Clear the screen

    GLint projectionLoc = glGetUniformLocation(engine.shaderProgram, "projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(engine.projection));

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
                glVertexAttrib4f(1, rc.color.r, rc.color.g, rc.color.b, rc.color.a); // Set color to white (RGBA)
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
