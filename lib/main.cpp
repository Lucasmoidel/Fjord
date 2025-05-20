#include "Fjord.h"

Engine engine; // makes the engine object available globaly part2
Input input;

float Time::deltaTime = 0;

int main(){
    engine.create_window("Simple Game",Vector2(720,720));
    input.initKeyMap();
    Start();

    Uint64 previousTime = SDL_GetTicks();
    Uint64 currentTime;

    while(engine.gameRunning){

        currentTime = SDL_GetTicks();
        Time::deltaTime = (currentTime - previousTime) / 1000.0f; // Convert to seconds
        previousTime = currentTime;

        //engine.processInput(); // proccess key presses
        engine.timeToWait = engine.TARGET_FPS - (SDL_GetTicks() - engine.last_frame_time);

        if (engine.timeToWait > 0 && engine.timeToWait <= engine.FRAME_TARGET_TIME){
            SDL_Delay(engine.timeToWait);
        }

        engine.last_frame_time = SDL_GetTicks();
        Utilities::engineUpdate();
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