#include "Fjord.h"

SDL_Event Engine::processInput(){ // process keyboard inputs
    SDL_Event event;
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT){
        gameRuning = false;
    }
    return event;
}

void Engine::update(SDL_Event events){
    int timeToWait = engine.TARGET_FPS - (SDL_GetTicks() - Time::last_frame_time);

    if (timeToWait > 0 && timeToWait <= engine.FRAME_TARGET_TIME){
        SDL_Delay(timeToWait);
    }

    Time::deltaTime =  (SDL_GetTicks() - Time::last_frame_time) / 1000.0f;
    Time::last_frame_time = SDL_GetTicks();
    for (size_t i = 0; i < engine.nodes.size(); i++){
        nodes[i]->Input(events);
        nodes[i]->Update();
        nodes[i]->rect = {(int)nodes[i]->transform.position.x, (int)nodes[i]->transform.position.y, 200, 200};
    }
}
void Engine::crateNode(Node* node){
    nodes.push_back(node);
}

void Engine::render(){ // render objects
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //sets background color
    SDL_RenderClear(renderer); // clear screen
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // sets object color
    for (size_t i = 0; i < engine.nodes.size(); i++){
        SDL_RenderDrawRect(renderer, &nodes[i]->rect);
    }
    SDL_RenderPresent(renderer); // shows render changes
}


void Engine::destroyWindow(){ // destroy window when game exits
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
}