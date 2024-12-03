#include <iostream>
#include "../lib/Fjord.h"

using namespace Utilities;

class Paddle : public Node {
    public:
        using Node::Node;

        int direction = 0;

        int side = 0;
        int speed = 200;

        void Update(float delta) override;
        void Input() override;
};

/*class Ball : public Node {
    public:
        using Node::Node;
        int speed = 200;
        void Update() override;
};*/

void Start(){
    createWindow(800, 600, "Pong");
    Paddle* paddle1 = engine.createNode<Paddle>(10,50, 30, 150, "Lpaddle"); // Create a new node
    Paddle* paddle2 = engine.createNode<Paddle>(760,50, 30, 150, "Rpaddle"); // Create a new node
    paddle1->side = 0;
    paddle2->side = 1;

    Vector2 vecTest = Vector2::ZERO;

    std::cout << vecTest << std::endl;

    //engine.nodes.push_back(node);
    //engine.nodes.push_back(node_two);

}

void Paddle::Update(float delta){
    transform.position.y += speed * direction * delta; // Update the position
    transform.position.y = ClampF(transform.position.y, 0, 600-transform.size.y); // No need to use Utilities::ClampF. Utilities is being used at the top of the file
}


void Paddle::Input(){ // Please keep updating the transform out of the input function
    if(side==0){
        if(input.isDown("Player1_Up")){
            direction = -1;
        } else if(input.isDown("Player1_Down")){
            direction = 1;
        } else {
            direction = 0;
        }
    } if(side==1){
        if(input.isDown("Player2_Up")){
            direction = -1;
        } else if(input.isDown("Player2_Down")){
            direction = 1;
        } else {
            direction = 0;
        }
    }
}