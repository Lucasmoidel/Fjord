#include "./Fjord.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
GLuint Renderer::compileShaders(){
    
}

void GLAPIENTRY
MessageCallback( GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLchar* message,
                 const void* userParam )
{
  fprintf( stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
           ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ),
            type, severity, message );
}


void Renderer::render(std::vector<RenderCall> &renderCalls) {

    // During init, enable debug output
    glEnable              ( GL_DEBUG_OUTPUT );
    glDebugMessageCallback( MessageCallback, 0 );

    glUseProgram(engine.shaderProgram);
    // Clear the screen

    GLint projectionLoc = glGetUniformLocation(engine.shaderProgram, "projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(engine.projection));

    GLint texProjectionLoc = glGetUniformLocation(engine.texShaderProgram, "projection");
    glUniformMatrix4fv(texProjectionLoc, 1, GL_FALSE, glm::value_ptr(engine.texProjection));

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

                glUseProgram(engine.texShaderProgram);  
                
                
                //SDL_Surface* surface = TTF_RenderText_Blended(rc.font, rc.text.c_str(), rc.text.length(), {255, 255, 255, 255});


                float vertices[] = {
                    // positions          // colors           // texture coords
                     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
                     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
                    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
                    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
                };
                unsigned int indices[] = {
                    0, 1, 3, // first triangle
                    1, 2, 3  // second triangle
                };
                unsigned int VBO, VAO, EBO;
                glGenVertexArrays(1, &VAO);
                glGenBuffers(1, &VBO);
                glGenBuffers(1, &EBO);
            
                glBindVertexArray(VAO);
            
                glBindBuffer(GL_ARRAY_BUFFER, VBO);
                glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
            
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
            
                // position attribute
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
                glEnableVertexAttribArray(0);
                // color attribute
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
                glEnableVertexAttribArray(1);
                // texture coord attribute
                glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
                glEnableVertexAttribArray(2);


                unsigned int texture;
                glGenTextures(1, &texture);
                glBindTexture(GL_TEXTURE_2D, texture); 
                // set the texture wrapping parameters
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                // // set texture filtering parameters
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                // load image, create texture and generate mipmaps
                //int width, height, nrChannels;

                //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, surface->pixels);
                //glGenerateMipmap(GL_TEXTURE_2D);

                //SDL_DestroySurface(surface);

                stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
                int width, height, nrChannels;
                unsigned char *data = stbi_load("/home/lucas/Documents/Fjord/wall.jpg", &width, &height, &nrChannels, 0);
                if (data)
                {
                    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
                    glGenerateMipmap(GL_TEXTURE_2D);
                }
                else
                {
                    std::cout << "Failed to load texture" << std::endl;
                }
                stbi_image_free(data);

                glUniform1i(glGetUniformLocation(engine.texShaderProgram, "texture1"), 0);

                //glBindTexture(GL_TEXTURE_2D, texture);
                glBindVertexArray(VAO);
                glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

                glUseProgram(engine.shaderProgram);      

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
