#include "Fjord.h"

void Engine::Initialize(){
    YAML::Node physics_defaults = YAML::LoadFile("../lib/def/physics-defaults.yaml"); // Load the defaults

    b2WorldDef worldDef = b2DefaultWorldDef(); // Create new box2d world

    worldDef.gravity = (b2Vec2){0.0f, physics_defaults["gravity"].as<float>()}; // Set the gravity to default gravity

    worldId = b2CreateWorld(&worldDef); // Create the box2d world and set to world id defined in fjord.h
}

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
    for (size_t i = 0; i < nodes.size(); i++){
        nodes[i]->Input();
        nodes[i]->Update(Time::deltaTime);
        nodes[i]->rect = {(int)nodes[i]->transform.position.x, (int)nodes[i]->transform.position.y, 200, 200};
    }
}


void Engine::render(){ // render objects
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //sets background color
    SDL_RenderClear(renderer); // clear screen
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // sets object color
    for (size_t i = 0; i < nodes.size(); i++){
        nodes[i]->Render(renderer);
        //SDL_RenderDrawLine(renderer, 0, 0, nodes[i]->rect.x, nodes[i]->rect.y);
        //SDL_RenderDrawLine(renderer, 500, 0, nodes[i]->rect.x+200, nodes[i]->rect.y);
        //SDL_RenderDrawLine(renderer, 500, 500, nodes[i]->rect.x+200, nodes[i]->rect.y+200);
        //SDL_RenderDrawLine(renderer, 0, 500, nodes[i]->rect.x, nodes[i]->rect.y+200);
    }
    SDL_RenderPresent(renderer); // shows render changes
}

std::vector<Node*> Engine::getRectColisions(std::string name){
    std::vector<Node*> intersecting;
    int index = -999;
    for (int i = 0; i < nodes.size(); i++){
        if (nodes[i]->ID == name){
            index = i;
        }
    }
    for (int i = 0; i < nodes.size(); i++){
        if (i == index)i++;
        if (SDL_HasIntersection(&nodes[index]->rect, &nodes[i]->rect)){
            intersecting.push_back(nodes[i]);
        }
    }
    return intersecting;
}

void Engine::destroyWindow(){ // destroy window when game exits
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
}