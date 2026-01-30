#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../lib/Fjord.h"

int lscore, rscore = 0;


using namespace Utilities;
class Paddle : public Polygon {
    public:
        using Polygon::Polygon;

        int direction = 0;

        int side = 0;
        int speed = 400;

        void Update() override;
        void Input() override;
};

class Score : public Label {
    public:
        using Label::Label;
        void Update() override;
        int val = 0;
};

class Ball : public Polygon {
    public:
        using Polygon::Polygon;
        Vector2 direction = Vector2(1, 1);
        int speed = 400;
        int side = 0;
        void Update() override{
            transform.position.x = ClampF(transform.position.x, 0, engine.screen_size.x-30);
            transform.position.y = ClampF(transform.position.y, 0, engine.screen_size.y-30);
            //std::cout << transform.global_position << std::endl;
            if (transform.position.x < 400){
                side = 0;
            }else{
                side = 1;
            }
            transform.position.x += direction.x * speed * Time::deltaTime;
            transform.position.y += direction.y * speed * Time::deltaTime;
            if(transform.position.y <= 0 || transform.position.y >= engine.screen_size.y-30){
                direction.y *= -1;
            }
            if(transform.position.x <= 0 || transform.position.x >= engine.screen_size.x-30){
                direction.x *= -1;
                if (side == 1 ){
                    lscore++;
                   //engine.root.kill_child("Lpaddle");
                } else {
                    rscore++;
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

Paddle* paddle1;
Paddle* paddle2;
Ball *ball;
void Paddle::Update(){
    transform.position.y += speed * direction * Time::deltaTime; // Update the position
    transform.position.y = ClampF(transform.position.y, 0, engine.screen_size.y-150); // No need to use Utilities::ClampF. Utilities is being used at the top of the file
}
void Utilities::engineUpdate(){
    if ((ball->transform.position.x <= paddle1->transform.position.x + 30 && ball->transform.position.y >= paddle1->transform.position.y && ball->transform.position.y <= paddle1->transform.position.y + 150) || (ball->transform.position.x  + 30 >= paddle2->transform.position.x && ball->transform.position.y >= paddle2->transform.position.y && ball->transform.position.y <= paddle2->transform.position.y + 150)) {
        ball->direction.x *= -1;
    }
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

void Score::Update(){
    setText(std::to_string(lscore).append(" | ").append(std::to_string(rscore)));
}
void Start(){
    //printf("\n\n\nStarted!!\n\n\n");

    paddle1 = engine.root.createNode<Paddle>(0,0, 1, 1, "Lpaddle"); // Create a new node
    paddle1->transform.position = Vector2(10,50);
    paddle1->shape.setShape({Vector2(0,150),Vector2(30,150),Vector2(30,0),Vector2(0,0)});
    paddle1->color = Color(1.0,1.0,1.0,1.0);
    paddle1->side = 0;
    engine.root.addChild(paddle1);

    paddle2 = engine.root.createNode<Paddle>(0,0, 1, 1, "Rpaddle"); // Create a new node
    paddle2->transform.position = Vector2(680,50);
    paddle2->shape.setShape({Vector2(0,150),Vector2(30,150),Vector2(30,0),Vector2(0,0)});
    paddle2->color = Color(1.0,1.0,1.0,1.0);
    paddle2->side = 1;
    engine.root.addChild(paddle2);

    ball = engine.root.createNode<Ball>(0,0,1,1,"Box");
    ball->transform.position = Vector2(400,200);
    ball->shape.setShape({Vector2(0,30),Vector2(30,30),Vector2(30,0),Vector2(0,0)});
    ball->color = Color(1.0,1.0,1.0,1.0);
    engine.root.addChild(ball);

    Score *text = engine.root.createNode<Score>(0, 0,1,1,"text");
    text->transform.position = Vector2((engine.screen_size.x -200)/2,0);
    text->shape.setShape({Vector2(200,0),Vector2(200,100),Vector2(0,100),Vector2(0,0)});
    text->color = Color(0.8,0.6,0.2,1);
    text->setFont("../NotoSansMono-Regular.ttf", 150);
    text->setText("19  |  20");
    //text->rotate(180);
    engine.root.addChild(text);
}

void Setup(){
}
