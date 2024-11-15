#include <iostream>
#include "Fjord.h"

class Node1 : public Node {
    public:

        Vector2 direction = Vector2(1,1); // Create a direction Vector

        void Update() override { // Main loop for Node
            //std::cout << Time::deltaTime << std::endl;
            int speed = 1;
            transform.position += direction; // Add the direction Vector to the position of the node
            if (transform.position.x > 300){ // Check for right edge
                direction.x = -1 * Time::deltaTime * speed;
            } else if (transform.position.x < 0){ // Check for left edge
                direction.x = 1 * Time::deltaTime * speed;
            }
            if (transform.position.y > 300){ // Check for bottom edge
                direction.y = -1 * Time::deltaTime * speed;
            } else if (transform.position.y < 0){ // Check for top edge
                direction.y = 1 * Time::deltaTime * speed;
            }
        }
};

void thing(){
    Node1* node = new Node1(); // Create a new node
    Node1* node_two = new Node1();
    node->transform.position = Vector2(0,0); // Offset the position by a little bit
    node_two->transform.position = Vector2(300,300);
    node_two->direction = Vector2(-1,-1);

    engine.nodes.push_back(node);
    engine.nodes.push_back(node_two);
    Vector2 vec = Vector2(2,3);
    Vector2 vec2 = Vector2(10,5);
    Vector2 vec3;

    std::cout << vec << std::endl;
    std::cout << vec2 << std::endl;

    vec3 = vec-vec2;

    std::cout << vec3 << std::endl;
}
