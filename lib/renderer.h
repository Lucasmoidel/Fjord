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
    Color color;

    SDL_Surface* surface;
};

class Renderer {
    public:
        GLuint compileShaders();

        void render(std::vector<RenderCall> &renderCalls);

    private:
        std::vector<float> combinePointsAndColors(std::vector<float>* points, std::vector<std::vector<float>>* colors);
};

#endif