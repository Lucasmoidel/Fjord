#ifndef RENDERER_H
#define RENDERER_H

#include "Fjord.h"

// The struct that contains all of the proerties for the render calls
struct RenderCall {
    // Used to allow for different logic depending on what is being rendered.
    enum RenderType { POLYGON, TEXT};
    RenderType type;

    //Transform transform;
    std::vector<float>* vertices;

    TTF_Font* font;
    std::string text;
};

class Renderer {
    public:
        GLuint compileShaders();
        void render(std::vector<RenderCall> &renderCalls);
};

#endif