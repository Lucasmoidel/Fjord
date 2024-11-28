#include <iostream>
#include "../lib/Fjord.h"

using namespace Utilities;

class Paddle : public Node {
    public:
        using Node::Node;
        int side = 0;
        int speed = 200;
        void Update() override;
        void Input() override;
};

void Start(){
    createWindow(800, 600, "Pong");
    Paddle* paddle1 = engine.crateNode<Paddle>(10,50, 30, 150); // Create a new node
    Paddle* paddle2 = engine.crateNode<Paddle>(760,50, 30, 150); // Create a new node
    paddle1->side = 0;
    paddle2->side = 1;

    Vector2 vecTest = Vector2::ZERO;

    std::cout << vecTest << std::endl;

    //engine.nodes.push_back(node);
    //engine.nodes.push_back(node_two);

}

void Paddle::Update(){
    Utilities::ClampF(&transform.position.y, 0, 600-transform.size.y);
}


void Paddle::Input(){
    if(side==0){
        if(input.isDown("Player1_Up")){
            transform.position.y -= speed*Time::deltaTime;
        } else if(input.isDown("Player1_Down")){
            transform.position.y += speed*Time::deltaTime;
        }
    } if(side==1){
        if(input.isDown("Player2_Up")){
            transform.position.y -= speed*Time::deltaTime;
        } else if(input.isDown("Player2_Down")){
            transform.position.y += speed*Time::deltaTime;
        }
    }
}