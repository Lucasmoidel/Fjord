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

// Lua Libs
#include <sol/sol.hpp>

//SDL libs
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <SDL3/SDL.h>
#include <SDL3/SDL_opengl.h>
//#include <SDL3/SDL_ttf.h>

#include "lua/lua_bindings.h"

#include "dat/Script.h" // Safe to include early
#include "dat/Color.h"
#include "dat/Input.h"
#include "dat/Vector2.h"
#include "dat/Transform.h"
#include "dat/Shader.h"
#include "ShaderManager.h"
#include "node/Node.h"
#include "dat/Shape.h"
#include "node/Polygon.h"

#include "utilities.h"
#include "renderer.h"

class Engine {
    public:
        //Engine();
        sol::state lua; // The lua state. All scripts will use this

        Node root = Node(0,0,1,1,"root");

        std::vector<RenderCall> front_buffer;
        std::vector<RenderCall> back_buffer;

        SDL_Window* window = NULL;
        Renderer renderer;
        ShaderManager shaderManager;

        bool create_window(std::string title, Vector2 size);
        void destroy_window();

        bool gameRunning = true;

        GLuint shaderProgram;
        Vector2 screen_size;

        void updateWindowSize();

        glm::mat4 projection;

    private:
    
        SDL_GLContext glContext;
};

// Make deltaTime available everywhere. Used in main.cpp
namespace Time {
    extern float deltaTime;
}

extern Engine engine;

void Start();

#endif // MYHEADER_H