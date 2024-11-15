#include <iostream>
#include "Fjord.h"

bool Engine::initWin(int Win_width, int Win_height, std::string name) { // initilize all SDL2 componets and makes sure that it succedes
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0 ) {
        printf("init sdl failed\n");
        return false;
    }


    window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Win_width, Win_height, 0);
    

    if (!window) {
        printf ("failed to create window\n");
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (!renderer) {
        printf ("failed to create renderer\n");
        return false;
    }
    SDL_SetWindowResizable(window, SDL_TRUE);
    return true;
}