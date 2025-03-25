#include "Fjord.h"

Engine engine; // makes the engine object available globaly part2
Input input;

float Time::deltaTime = 0;

int main(){
    engine.create_window("Simple Game",Vector2(800,600));
    input.initKeyMap();
    Setup();
    while(engine.gameRunning){
        
        //engine.processInput(); // proccess key presses
        //engine.update(); // update the engine every tick

        //engine.render(engine.renderer.get());// render objects and stuff

        SDL_Event event;
        SDL_PollEvent(&event);
        if (event.type == SDL_EVENT_QUIT){
            engine.gameRunning = false;
        }
    }
    engine.destroy_window();// destroy window
    return 0;// exit program
}