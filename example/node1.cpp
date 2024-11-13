#include <iostream> 

#include "../lib/Fjord.h"

Node square = engine.createObject();

bool Engine::initObjs(){// define initObjs
    engine.createObject();
    return true;
}

int direction = 1;

void Node::update(){ // update stuff
    if (engine.nodes[0].position.x > 500){
        direction = -1;
    }
    engine.nodes[0].position.x += direction;
}

