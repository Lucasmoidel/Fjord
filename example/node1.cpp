#include <iostream> 

#include "../lib/Fjord.h"

class Node1 : public Node{ // Base Class of Every Node
    public:
        Node1(int xPos, int yPos, int width, int height, int zIndex);// add constructor with vars for rendering
        void update(); // update function
        Vector2 position = Vector2(0, 0);
        Vector2 scale = Vector2(50, 50);
        int zIndex; // create vars that go in rect
        SDL_Rect rect; // sdl rect for rendering
};

bool Engine::initObjs(){// define initObjs
    engine.createObject();
    return true;
}

void Node1::update(){ // update stuff
    position.x += 1;
}

