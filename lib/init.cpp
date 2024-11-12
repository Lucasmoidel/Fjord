#include <iostream>
#include <SDL2/SDL.h>

int initSDL(std::string windowname, int Win_width, int Win_height, SDL_Window* window, SDL_Renderer* renderer){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0 ) {
        std::cout << "init sdl failed\n";
        return 0;
    }


    window = SDL_CreateWindow(windowname.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Win_width, Win_height, 0);
    

    if (!window) {
        std::cout << "failed to create window\n";
        return 0;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (!renderer) {
        std::cout << "failed to create renderer\n";
        return 0;
    }

    return 1;
}