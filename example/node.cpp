#include <iostream>
#include "../lib/Fjord.h"

class Node1 : public Node {
    public:

        Vector2 direction = Vector2::ZERO; // Create a direction Vector
        using Node::Node;
        void Update() override { // Main loop for Node
            //std::cout << Time::deltaTime << std::endl;
            int speed = 250;
            transform.position += direction * Time::deltaTime * speed; // Add the direction Vector to the position of the node
            /*if (transform.position.x > 300 || transform.position.x < 0){ // Check for right edge
                direction.x = 0;
            }
            if (transform.position.y > 300 || transform.position.y < 0){ // Check for bottom edge
                direction.y = 0;
            }*/
        }

        void Input(SDL_Event event) override {
            if (event.type == SDL_KEYDOWN){
                switch (event.key.keysym.sym){
                    case SDLK_UP:
                        direction.y = -1;
                        break;
                    case SDLK_DOWN:
                        direction.y = 1;
                        break;
                    case SDLK_LEFT:
                        direction.x = -1;
                        break;
                    case SDLK_RIGHT:
                        direction.x = 1;
                        break;
                    default:
                        break;
                }
            }
        }
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