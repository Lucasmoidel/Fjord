#ifndef Fjord_H
#define Fjord_H

#include <nlohmann/json.hpp>

#include <iostream> 
#include <vector>
#include <array>
#include <fstream>
#include <stdexcept>
#include <sstream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <yaml-cpp/yaml.h>

#include <box2d/box2d.h>

#include "utilities.h"
#include "dat/Input.h"
#include "dat/Vector2.h"
#include "dat/Transform.h"
#include "node/Node.h"
#include "node/physics/collision_object.h"
#include "node/physics/static_body.h"



class Engine{ // game engine that will provide functions    
    public:
        Node root;

        std::vector<Node*> nodes;
        void update();

        //void crateNode(Node* node);
        bool gameRuning = false; // keeps tract of weather the game is running
        b2WorldId worldId;

        void Initialize();

        bool initWin(int Win_width, int Win_height, std::string name); //intitilize sdl2 window with the width, height, and name of window
        void processInput(); // proccess user input
        void render(); // render objects
        void destroyWindow(); // destroy window when game exits

        std::vector<Node*> getRectColisions(std::string name);

        int TARGET_FPS = 120;
        int FRAME_TARGET_TIME = 1000 / TARGET_FPS;

    private:

        int timeToWait;
        SDL_Window* window = NULL; // SDL window object
        SDL_Renderer* renderer = NULL; //SDL renderer object

        int last_frame_time = 0;

};
namespace Time {
    extern float deltaTime;
}
extern Engine engine; // makes the engine object available globaly part1 see main.cpp for part 2
extern Input input;

void Start();
void createWindow(int x, int y, std::string winName);

#endif // MYHEADER_H