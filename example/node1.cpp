#include <iostream> 

#include "../Fjord.h"

Node::Node(int xPos, int yPos, int width, int height, int zIndex){
    x = xPos;
    y = yPos;
    w = width;
    h = height;
    zIndex = zIndex;
    rect = {x, y, w, h};
    std::cout << "obj created" << std::endl;
}

bool Engine::initObjs(){// define initObjs
    engine.createObject();
    return true;
}

void Node::update(){ // update stuff
    //std::cout << "shdflkjsd" << std::endl;
}

