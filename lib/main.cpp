#include "Fjord.h"

Engine engine; // makes the engine object available globaly part2
Input input;

float Time::deltaTime = 0;

int main(){
    engine.create_window("Simple Game",Vector2(800,800));
    input.initKeyMap();
    Start();
    while(engine.gameRunning){

        //engine.processInput(); // proccess key presses
        engine.root.engine_update_node(); // update the engine every tick

        SDL_Event event;
        SDL_PollEvent(&event);
        if (event.type == SDL_EVENT_QUIT){
            engine.gameRunning = false;
        }
        std::swap(engine.front_buffer,engine.back_buffer); // Swap the buffers
        engine.renderer.render(engine.front_buffer);
        engine.back_buffer.clear(); // Clear the back buffer
    }
    engine.destroy_window();// destroy window
    return 0;// exit program
}