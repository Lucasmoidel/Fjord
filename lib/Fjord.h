#ifndef Fjord_H
#define Fjord_H

#include <iostream> 
#include <SDL2/SDL.h>

#include "dat/Vector2.h"

class Engine{ // game engine that will provide functions    
    public:
        bool gameRuning = false;
        bool initWin(int Win_width, int Win_height, std::string name); //intitilize sdl2 window with the width, height, and name of window
        void processInput();
        void render();
       
        void destroyWindow(); // destroy window when game exits

        SDL_Window* window = NULL; // SDL window object
        SDL_Renderer* renderer = NULL; //SDL renderer object

};

extern Engine engine; // makes the engine object available globaly part1 see main.cpp for part 2

void thing();


#endif // MYHEADER_H