#include <iostream>
#include "../lib/Fjord.h"

using namespace Utilities;

class Paddle : public Node {
    public:
        int direction = 0;
        void Update() override;
        void Input() override;
};

void Start(){
    createWindow(800, 500, "Pong");
    Paddle* paddle1 = new Paddle(10,50); // Create a new node
    engine.crateNode(paddle1);

    Vector2 vecTest = Vector2::ZERO;

    std::cout << vecTest << std::endl;

    //engine.nodes.push_back(node);
    //engine.nodes.push_back(node_two);

}

Paddle::Input(){

}