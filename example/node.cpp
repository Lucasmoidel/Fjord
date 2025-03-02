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

        int direction = 0;

        int side = 0;
        int speed = 200;

        Vector2 testing = Vector2(5,3);

        void Update() override;
        void Input() override;
};
class Ball : public Node {
    public:
        using Node::Node;
        Vector2 direction = Vector2(1, 1);
        int speed = 200;
        int side = 0;
        void Update() override{
            //std::cout << transform.global_position << std::endl;
            if (transform.position.x < 400){
                side = 0;
            }else{
                side = 1;
            }
            transform.position.x += direction.x * speed * Time::deltaTime;
            transform.position.y += direction.y * speed * Time::deltaTime;
            if(transform.position.y <= 0 || transform.position.y >= 600-transform.size.y){
                direction.y *= -1;
            }
            if(transform.position.x <= 0 || transform.position.x >= 800-transform.size.x){
                direction.x *= -1;
                if (side == 1 ){
                    Lscore++;
                   //engine.root.kill_child("Lpaddle");
                } else {
                    Rscore++;
                    //engine.root.kill_child("Lpaddle");
                    //engine.root.kill_child("Ball");
                }
            }
            //if (get_node("../Lpaddle") != NULL){
            //get_node("../Lpaddle")->transform.position.y += direction.y * Time::deltaTime * speed;
            //}
            //std::cout << Lscore << ", " << Rscore << std::endl;
        }
};

void Start(){
    createWindow(800, 600, "Pong");
    Paddle* paddle1 = engine.root.createNode<Paddle>(10,50, 30, 150, "Lpaddle"); // Create a new node
    Paddle* paddle2 = engine.root.createNode<Paddle>(760,50, 30, 150, "Rpaddle"); // Create a new node

    paddle1->side = 0;
    paddle2->side = 1;
    
    //Ball* ball = engine.root.createNode<Ball>(100, 100, 30, 30, "Ball");
    Ball* ball = engine.root.createNode<Ball>(100, 100, 30, 30, "Ball");

}

void Paddle::Update(){
    transform.position.y += speed * direction * Time::deltaTime; // Update the position
    transform.position.y = ClampF(transform.position.y, 0, 600-transform.size.y); // No need to use Utilities::ClampF. Utilities is being used at the top of the file
}


void Paddle::Input(){ // Please keep updating the transform out of the input function
    if(side==0){
        if(input.isDown("Player1_Up")){
            direction = -1;
        } else if(input.isDown("Player1_Down")){
            //std::cout << testing.BOX.x << "\n";
            direction = 1;
        } else {
            direction = 0;
            testing.x += 1;
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