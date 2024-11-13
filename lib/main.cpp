#include <iostream> 
#include <string> 
#include <vector> 
#include <stdexcept>
#include "../Fjord.h"
Engine engine; // makes the engine object available globaly part2

void Engine::createObject(){ // create object from the basic Node class and append it to the nodes array
    Node node(200, 200, 200, 200, 0);
    engine.nodes.push_back(node);
}


int main(){
    if (engine.initWin(500, 500, "test") && engine.initObjs()){engine.gameRuning = true;} // check if everything initilizing ojects and SDL2 succeded and store that in gameRunning
    while(engine.gameRuning){// run the gameLoop while the gameRunning is set to true
        engine.gameLoop();
    }
    engine.destroyWindow();
    return 0;// exit program
}



void Engine::gameLoop(){// main game loop
    for (int i = 0; i < (int)engine.nodes.size(); i++){ // loops throuch the objects int the nodes array and calls there update functions
        engine.nodes[i].update();
    }
    processInput();
    engine.render();
}

void Engine::processInput(){
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

void Engine::render(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int i = 0; i < (int)engine.nodes.size(); i++){ // loops throuch the objects int the nodes array and renders them
        SDL_RenderFillRect(renderer, &nodes[i].rect);
    }
    SDL_RenderPresent(renderer);

}

void Engine::destroyWindow(){
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