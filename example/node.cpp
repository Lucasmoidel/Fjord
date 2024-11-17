#include <iostream>
#include "../lib/Fjord.h"

using namespace Utilities;

class Node1 : public Node {
    public:

        Vector2 direction = Vector2::ZERO; // Create a direction Vector
        using Node::Node;
        void Update() override; // Main loop for Node
        void Input() override;
};

void Start(){
    createWindow(500, 500, "example");
    Node1* node = new Node1(100,200); // Create a new node
    engine.crateNode(node);

    Vector2 vecTest = Vector2::ZERO;

    std::cout << vecTest << std::endl;

    //engine.nodes.push_back(node);
    //engine.nodes.push_back(node_two);

}

void Node1::Update() {
    transform.position += direction * speed * Time::deltaTime;
    transform.position.x = ClampF(transform.position.x,0,300);
    transform.position.y = ClampF(transform.position.y,0,300);
    //std::cout << ClampI(transform.position.x,0,300) << std::endl;
}

void Node1::Input(){
    if (input.isDown("Up")){
		direction.y = -1;
	} else if (input.isDown("Down")){
		direction.y = 1;
	} else {
        direction.y = 0;
    }
    if (input.isDown("Left")){
		direction.x = -1;
	} else if (input.isDown("Right")){
		direction.x = 1;
	} else {
        direction.x = 0;
    }
    if (input.isDown("Run")){
        speed = 500;
    } else{
        speed = 250;
    }
}