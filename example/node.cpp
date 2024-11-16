#include <iostream>
#include "../lib/Fjord.h"

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
    Node1* node_two = new Node1(200,100);
    engine.crateNode(node);
    engine.crateNode(node_two);

    Vector2 vecTest = Vector2::ZERO;

    std::cout << vecTest << std::endl;

    //engine.nodes.push_back(node);
    //engine.nodes.push_back(node_two);

}

void Node1::Update() {
    //std::cout << Time::deltaTime << std::endl;
    int speed = 250;
    /*if (transform.position.x > 300 || transform.position.x < 0){ // Check for right edge
    direction.x = 0;
    }
    if (transform.position.y > 300 || transform.position.y < 0){ // Check for bottom edge
    direction.y = 0;
    }*/

}

void Node1::Input(){
    int speed = 1000;
    if (input.isDown("Up")){
        
		transform.position -= Vector2(0, 5) * Time::deltaTime * speed;
	}
        if (input.isDown("Down")){
        
		transform.position += Vector2(0, 5) * Time::deltaTime * speed;
	}
        if (input.isDown("Left")){
        
		transform.position -= Vector2(5, 0) * Time::deltaTime * speed;
	}
        if (input.isDown("Right")){
        
		transform.position += Vector2(5, 0) * Time::deltaTime * speed;
	}
}