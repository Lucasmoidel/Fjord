#include "Fjord.h"

void Engine::processInput(){ // process keyboard inputs
    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT){
        gameRuning = false;
    }
}

void Engine::render(){ // render objects
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //sets background color
    SDL_RenderClear(renderer); // clear screen
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // sets object color
    for (int i = 0; i < engine.nodes.size(); i++){
        nodes[i].rect = {(int)nodes[i].transform.position.x, (int)nodes[i].transform.position.y, 200, 200};
        SDL_RenderDrawRect(renderer, &nodes[i].rect);
    }
    SDL_RenderPresent(renderer); // shows render changes
}


void Engine::destroyWindow(){ // destroy window when game exits
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
}