#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../lib/Fjord.h"

using namespace Utilities;

int Lscore = 0;
int Rscore = 0;
class Paddle : public Node {
    public:
        using Node::Node;
        int side = 0;
        int speed = 200;
        void Update() override;
        void Input() override;
};
class Ball : public Node {
    public:
        using Node::Node;
        Vector2 direction = Vector2(1, 1);
        int speed = 200;
        void Update() override{
            transform.position.x += direction.x * speed * Time::deltaTime;
            transform.position.y += direction.y * speed * Time::deltaTime;
            if(transform.position.y <= 0 || transform.position.y >= 600-transform.size.y){
                direction.y *= -1;
            }
            if(transform.position.x <= 0 || transform.position.x >= 800-transform.size.x){
                direction.x *= -1;
                if (transform.position.x > 400){
                    Rscore++;
                } else {
                    Lscore++;
                }
            }
            std::cout << Lscore << ", " << Rscore << std::endl;
        }
};

void Start(){
    createWindow(800, 600, "Pong");
    Paddle* paddle1 = engine.crateNode<Paddle>(10,50, 30, 150, "Lpaddle"); // Create a new node
    Paddle* paddle2 = engine.crateNode<Paddle>(760,50, 30, 150, "Rpaddle"); // Create a new node
    paddle1->side = 0;
    paddle2->side = 1;
    Ball* ball = engine.crateNode<Ball>(300, 400, 30, 30, "Ball");
    

}

void Paddle::Update(){
    transform.position.y = Utilities::ClampF(transform.position.y, 0, 600-transform.size.y);
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