#include <iostream>
#include "Fjord.h"

bool Engine::initWin(int Win_width, int Win_height, std::string name) { // initilize all SDL2 componets and makes sure that it succedes

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0  && TTF_Init() != 0) {
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

void Engine::Initialize(){
    YAML::Node physics_defaults = YAML::LoadFile("../lib/def/physics-defaults.yaml"); // Load the defaults

    b2WorldDef worldDef = b2DefaultWorldDef(); // Create new box2d world

    worldDef.gravity = (b2Vec2){0.0f, physics_defaults["gravity"].as<float>()}; // Set the gravity to default gravity

    worldId = b2CreateWorld(&worldDef); // Create the box2d world and set to world id defined in fjord.h
}