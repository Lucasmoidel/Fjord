#include <iostream> 

#include "../lib/Fjord.h"

bool Engine::initObjs(){// define initObjs
    engine.createObject();
    return true;
}

void Node::update(){ // update stuff
    printf("helpmee%d\n", position.x);
    position.x += 1;
}

