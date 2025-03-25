#ifndef Fjord_H
#define Fjord_H

#include <nlohmann/json.hpp>

//cpp libs
#include <iostream> 
#include <vector>
#include <array>
#include <fstream>
#include <stdexcept>
#include <sstream>

//SDL libs
#include <GL/glew.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_opengl.h>
//#include <SDL3/SDL_ttf.h>


//Fjord libs
#include "utilities.h"
#include "renderer.h"
#include "dat/Input.h"
#include "dat/Vector2.h"
#include "dat/Transform.h"
#include "node/Node.h"
#include "dat/shape.h"
#include "node/Polygon.h"

class Engine {
    public:
        SDL_Window* window = NULL;
        Renderer renderer;

        bool create_window(std::string title, Vector2 size);
        void destroy_window();

        bool gameRunning = true;

    private:
        SDL_GLContext glContext;
};

// Make deltaTime available everywhere. Used in main.cpp
namespace Time {
    extern float deltaTime;
}

extern Engine engine;

void Setup();

#endif // MYHEADER_H