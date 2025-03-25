#include "Fjord.h"

Engine engine; // makes the engine object available globaly part2
Input input;

float Time::deltaTime = 0;

int main(){
    engine.create_window("Simple Game",Vector2(800,600));
    input.initKeyMap();
    Start();
    while(engine.gameRunning){
        
        engine.processInput(); // proccess key presses
        engine.update(); // update the engine every tick

        //engine.render(engine.renderer.get());// render objects and stuff
    }
    engine.destroyWindow();// destroy window
    return 0;// exit program
}