#include <iostream> 
#include <string> 
#include <vector> 
#include <stdexcept>
#include "Fjord.h"
Engine engine; // makes the engine object available globaly part2

int main(){
    if (engine.initWin(500, 500, "test")){engine.gameRuning = true;} // check if everything initilizing ojects and SDL2 succeded and store that in gameRunning
    while(engine.gameRuning){
        engine.processInput();
        engine.render();
    }
    return 0;// exit program
}

void Engine::processInput(){ // process keyboard inputs
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            gameRuning = false;
            break;
        default:
            break;
    }
}

void Engine::render(){ // render objects
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //sets background color
    SDL_RenderClear(renderer); // clear screen
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // sets object color
    
    SDL_RenderPresent(renderer); // shows render changes
}


void Engine::destroyWindow(){ // destroy window when game exits
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
}

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

    return true;
}