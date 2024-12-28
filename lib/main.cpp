#include "Fjord.h"

Engine engine; // makes the engine object available globaly part2
Input input;

float Time::deltaTime = 0;

int main(){
    engine.Initialize();
    input.initKeyMap();
    Start();
    while(engine.gameRuning){
        
        engine.processInput(); // proccess key presses
        engine.update(); // update the engine every tick

        engine.render(engine.rendererGL.get());// render objects and stuff
    }
    engine.destroyWindow();// destroy window
    return 0;// exit program
}

void createWindow(int x, int y, std::string winName){
    if (engine.initWin(x, y, winName)){engine.gameRuning = true;}// check if everything initilizing ojects and SDL2 succeded and store that in gameRunning
}