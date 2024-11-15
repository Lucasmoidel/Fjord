#include <iostream> 
#include <string> 
#include <vector> 
#include <stdexcept>
#include "Fjord.h"
Engine engine; // makes the engine object available globaly part2
float Time::deltaTime = 0;
int Time::last_frame_time = 0;
int main(){
    thing();
    if (engine.initWin(500, 500, "test")){engine.gameRuning = true;} // check if everything initilizing ojects and SDL2 succeded and store that in gameRunning
    while(engine.gameRuning){
        engine.processInput();
        engine.update();

        engine.render();
    }
    engine.destroyWindow();
    return 0;// exit program
}