#include <iostream>
#include "Fjord.h"

class Node1 : public Node {
    public:

        Vector2 direction = Vector2(1,1); // Create a direction Vector

        void Update() override { // Main loop for Node

            transform.position += direction; // Add the direction Vector to the position of the node
            if (transform.position.x > 300){ // Check for right edge
                direction.x = -1;
            } else if (transform.position.x < 0){ // Check for left edge
                direction.x = 1;
            }
            if (transform.position.y > 300){ // Check for bottom edge
                direction.y = -1;
            } else if (transform.position.y < 0){ // Check for top edge
                direction.y = 1;
            }
        }
};

void thing(){
    
    Node1* node = new Node1(); // Create a new node
    Node1* node_two = new Node1();
    node->transform.position = Vector2(200,100); // Offset the position by a little bit
    node_two->transform.position = Vector2(100,200);
    node_two->direction = Vector2(-1,-1);

    engine.nodes.push_back(node);
    engine.nodes.push_back(node_two);

}
