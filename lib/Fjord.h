#ifndef Fjord_H
#define Fjord_H

#ifdef LINUX_UBUNTU
#include "jsoncpp/json/json.h"
#elif defined(LINUX_ARCH)
#include "json/json.h"
#else
#include "jsoncpp/json/json.h"
#endif

#include <iostream> 
#include <vector>
#include <array>
#include <SDL2/SDL.h>
#include "dat/Input.h"
#include "dat/Vector2.h"
#include "dat/Transform.h"
#include "node/Node.h"



class Engine{ // game engine that will provide functions    
    public:
        std::vector<Node*> nodes;
        void update(SDL_Event events);
        void crateNode(Node* node);
        bool gameRuning = false; // keeps tract of weather the game is running
        bool initWin(int Win_width, int Win_height, std::string name); //intitilize sdl2 window with the width, height, and name of window
        SDL_Event processInput(); // proccess user input
        void render(); // render objects
        void destroyWindow(); // destroy window when game exits

        int TARGET_FPS = 120;
        int FRAME_TARGET_TIME = 1000 / TARGET_FPS;



    private:

        SDL_Window* window = NULL; // SDL window object
        SDL_Renderer* renderer = NULL; //SDL renderer object

};
namespace Time{
    extern float deltaTime;
    extern int last_frame_time;
}
extern Engine engine; // makes the engine object available globaly part1 see main.cpp for part 2
extern Input input;

void Start();
void createWindow(int x, int y, std::string winName);

#endif // MYHEADER_H