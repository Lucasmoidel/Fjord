#include <iostream> 
#include <string> 
#include <vector> 
#include <stdexcept>
#include "Fjord.h"
Engine engine; // makes the engine object available globaly part2
float Time::deltaTime = 0;
int Time::last_frame_time = 0;
int main(){

    Start();
    while(engine.gameRuning){
        SDL_Event events = engine.processInput(); // proccess key presses
        engine.update(events); // update the engine every tick

        engine.render();// render objects and stuff
    }
    engine.destroyWindow();// destroy window
    return 0;// exit program
}

void createWindow(int x, int y, std::string winName){
    if (engine.initWin(x, y, winName)){engine.gameRuning = true;}// check if everything initilizing ojects and SDL2 succeded and store that in gameRunning
}