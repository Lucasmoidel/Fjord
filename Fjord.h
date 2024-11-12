#ifndef Fjord_H
#define Fjord_H

#include <SDL2/SDL.h>
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
int initSDL(std::string windowname, int Win_width, int Win_height, SDL_Window* window, SDL_Renderer* renderer);

#endif // MYHEADER_H