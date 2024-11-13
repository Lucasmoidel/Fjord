#include <iostream> 
#include <string> 
#include <vector> 
#include "../Fjord.h"
Engine engine;
void Engine::createObject(){
    Node node;
    engine.nodes.push_back(node);
}


int main(){
    engine.gameRuning = engine.initObjs();
    while(engine.gameRuning){
        engine.gameLoop();
    }
    return 0;
}



void Engine::gameLoop(){
    for (int i = 0; i < (int)engine.nodes.size(); i++){
        engine.nodes[i].update();
    }
}