#include "Fjord.h"

void Engine::processInput(){ // process keyboard inputs
    SDL_Event event;
    SDL_PollEvent(&event);
    std::cout << "check\n";
    if (event.type == SDL_QUIT){
        gameRuning = false;
    }
}

void Engine::update(){
    int timeToWait = engine.TARGET_FPS - (SDL_GetTicks() - Time::last_frame_time);
    if (timeToWait > 0 && timeToWait <= engine.TARGET_FPS){SDL_Delay(timeToWait);}
    for (int i = 0; i < engine.nodes.size(); i++){
        nodes[i]->Update();
    }
    Time::deltaTime =  (SDL_GetTicks() - Time::last_frame_time) / 1000.0f;
    Time::last_frame_time = SDL_GetTicks();
}

void Engine::render(){ // render objects
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //sets background color
    SDL_RenderClear(renderer); // clear screen
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // sets object color
    for (int i = 0; i < engine.nodes.size(); i++){
        nodes[i]->rect = {(int)nodes[i]->transform.position.x, (int)nodes[i]->transform.position.y, 200, 200};
        SDL_RenderDrawRect(renderer, &nodes[i]->rect);
    }
    SDL_RenderPresent(renderer); // shows render changes
}


void Engine::destroyWindow(){ // destroy window when game exits
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
}