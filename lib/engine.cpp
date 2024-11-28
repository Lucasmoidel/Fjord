#include "Fjord.h"

void Engine::processInput(){ // process keyboard inputs
    SDL_Event event;
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT){
        gameRuning = false;
    }
}

void Engine::update(){
    timeToWait = engine.TARGET_FPS - (SDL_GetTicks() - Engine::last_frame_time);

    if (timeToWait > 0 && timeToWait <= engine.FRAME_TARGET_TIME){
        SDL_Delay(timeToWait);
    }

    Time::deltaTime =  (SDL_GetTicks() - Engine::last_frame_time) / 1000.0f;
    Engine::last_frame_time = SDL_GetTicks();
    for (size_t i = 0; i < engine.nodes.size(); i++){
        nodes[i]->Input();
        nodes[i]->Update();
        nodes[i]->rect = {(int)nodes[i]->transform.position.x, (int)nodes[i]->transform.position.y, 200, 200};
    }
}
template <typename T> T* Engine::crateNode(int xPos, int yPos, int xSize, int ySize){
    T* node = new T(xPos, yPos, xSize, ySize);
    nodes.push_back(node);
    return node;
}

void Engine::render(){ // render objects
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //sets background color
    SDL_RenderClear(renderer); // clear screen
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // sets object color
    for (size_t i = 0; i < engine.nodes.size(); i++){
        //SDL_RenderDrawLine(renderer, 0, 0, nodes[i]->rect.x, nodes[i]->rect.y);
        //SDL_RenderDrawLine(renderer, 500, 0, nodes[i]->rect.x+200, nodes[i]->rect.y);
        //SDL_RenderDrawLine(renderer, 500, 500, nodes[i]->rect.x+200, nodes[i]->rect.y+200);
        //SDL_RenderDrawLine(renderer, 0, 500, nodes[i]->rect.x, nodes[i]->rect.y+200);
        nodes[i]->rect.x = nodes[i]->transform.position.x;
        nodes[i]->rect.y = nodes[i]->transform.position.y;
        nodes[i]->rect.w = nodes[i]->transform.size.x;
        nodes[i]->rect.h = nodes[i]->transform.size.y;
        SDL_RenderDrawRect(renderer, &nodes[i]->rect);
    }
    SDL_RenderPresent(renderer); // shows render changes
}


void Engine::destroyWindow(){ // destroy window when game exits
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
}