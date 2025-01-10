#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../lib/Fjord.h"

using namespace Utilities;

int Lscore = 0;
int Rscore = 0;
class Box : public Node {
    public:
        using Node::Node;
        int speed = 200;
        Vector2 direction = Vector2(0,0);
        void Update() override;
        void Input() override;
};

void Start(){
    createWindow(800, 600, "Pong");
    Box* box = engine.root.createNode<Box>(300, 300, 300, 300, "Box"); // Create a new node
}

void Box::Update(){
    transform.position.x += speed * direction.x * Time::deltaTime; // Update the position
    transform.position.y += speed * direction.y * Time::deltaTime; // Update the position
    int windowWidth = 0, windowHeight = 0;
	SDL_GetWindowSize(engine.window, &windowWidth, &windowHeight);
    transform.position.x = ClampF(transform.position.x, 0, windowWidth-transform.size.x); // No need to use Utilities::ClampF. Utilities is being used at the top of the file
    transform.position.y = ClampF(transform.position.y, 0, windowHeight-transform.size.y);
}


void Box::Input(){ // Please keep updating the transform out of the input function
    if(input.isDown("Up")){
        direction.y = -1;
    } else if(input.isDown("Down")){
        direction.y = 1;
    } else {
        direction.y = 0;
    }

    if(input.isDown("Left")){
        direction.x = -1;
    } else if(input.isDown("Right")){
        direction.x = 1;
    } else {
        direction.x = 0;
    }
}