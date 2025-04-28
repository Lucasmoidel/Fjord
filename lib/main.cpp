#include "Fjord.h"

Engine engine; // makes the engine object available globaly part2
Input input;

float Time::deltaTime = 0;

int main(){
    engine.luaHandler.bindToLuaState(&engine.lua);
    engine.create_window("Simple Game",Vector2(1280,720));
    input.initKeyMap();
    Start();

    Uint64 previousTime = SDL_GetTicks();
    Uint64 currentTime;

    while(engine.gameRunning){

        currentTime = SDL_GetTicks();
        Time::deltaTime = (currentTime - previousTime) / 1000.0f; // Convert to seconds
        previousTime = currentTime;

        //engine.processInput(); // proccess key presses
        engine.root._engine_update_node(); // update the engine every tick

        SDL_Event event;
        SDL_PollEvent(&event);
        if (event.type == SDL_EVENT_QUIT){
            engine.gameRunning = false;
        }
        if (event.type == SDL_EVENT_WINDOW_RESIZED) {
            engine.screen_size.x = event.window.data1;
            engine.screen_size.y = event.window.data2;
            engine.updateWindowSize();
        }
        std::swap(engine.front_buffer,engine.back_buffer); // Swap the buffers
        engine.renderer.render(engine.front_buffer);
        engine.back_buffer.clear(); // Clear the back buffer
    }
    engine.destroy_window();// destroy window
    return 0;// exit program
}