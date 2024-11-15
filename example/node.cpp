#include <iostream>
#include "../lib/Fjord.h"

class Node1 : public Node {
    public:

        Vector2 direction = Vector2(1,1); // Create a direction Vector
        using Node::Node;
        void Update() override;
        bool stop = false;
};

void Start(){
    createWindow(500, 500, "example");
    Node1* node = new Node1(100,200); // Create a new node
    Node1* node_two = new Node1(200,100);
    engine.crateNode(node);
    engine.crateNode(node_two);
    node_two->direction = Vector2(-1,-1);

    Vector2 vecTest = Vector2::ZERO;

    std::cout << vecTest << std::endl;

    //engine.nodes.push_back(node);
    //engine.nodes.push_back(node_two);

}

void Node1::Update() {
    int speed = 250;
    transform.position += direction * Time::deltaTime * speed; // Add the direction Vector to the position of the node
    if (transform.position.x > 300){ // Check for right edge
        direction.x = -1;
    } else if (transform.position.x < 0){ // Check for left edge
        direction.x = 1;
    } if (transform.position.y > 300){ // Check for bottom edge
        direction.y = -1;
    } else if (transform.position.y < 0){ // Check for top edge
        direction.y = 1;
    }
}