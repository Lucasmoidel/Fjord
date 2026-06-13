#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../lib/Fjord.h"

using namespace Utilities;

class Box : public Polygon {
    public:
        using Polygon::Polygon;

        int direction = 1;
        int rDir = 1;
        int gDir = 1;
        int bDir = 1;

        void Update() override;
};

void Box::Update() {
    color.r += rDir * Time::deltaTime;
    color.g += gDir * Time::deltaTime;
    color.b += bDir * Time::deltaTime;

    transform.scale = Vector2(2,2);
    /*
    if (transform.scale.x > 3 && direction == 1){
        direction = -1;
    } else if (transform.scale.x < 0.5 && direction == -1){
        direction = 1;
    }*/
    if (color.r > 1 || color.r < 0){rDir = rDir * -1;}
    if (color.g > 1 || color.g < 0){gDir = rDir * -1;}
    if (color.b > 1 || color.b < 0){bDir = bDir * -1;}
    
    if (input.isDown("Down")){
        transform.position.y += 500*Time::deltaTime;
    } else if (input.isDown("Up")){
        transform.position.y -= 500*Time::deltaTime;
    } if (input.isDown("Left")){
        transform.position.x -= 500*Time::deltaTime;
    } else if (input.isDown("Right")){
        transform.position.x += 500*Time::deltaTime;
    }

    if (input.isDown("RRight")){
        rotate(-180*Time::deltaTime);
    } else if (input.isDown("RLeft")){
        rotate(180*Time::deltaTime);
    }
    /*
    if (transform.position.x < 0.5){
        direction.x = 1;
    } else if (transform.position.x > 0.5) {
        direction.x = -1;
    }
    if (transform.position.y < 0.5){
        direction.y = 1;
    } else if (transform.position.y > 0.5) {
        direction.y = -1;
    }
    transform.position += direction * 10 * Time::deltaTime;
    */
    //get_node("Box2")->transform.rotation += 25 * Time::deltaTime;
}

void Start(){
    //printf("\n\n\nStarted!!\n\n\n");

    std::cout << Vector2(50, 20).normalized().x << "\n";
    Box *square = engine.root.createNode<Box>(0,0,1,1,"Box");
    square->transform.position = Vector2(0,0.3);
    square->shape.setShape({Vector2(-20,20),Vector2(20,20),Vector2(20,-20),Vector2(-20,-20)});
    square->transform.scale = Vector2(0.5,0.5);
    square->color = Color(0.2,0.8,0.6,1);
    engine.root.addChild(square);

    Label *text = engine.root.createNode<Label>(0, 0,1,1,"text");
    text->transform.position = Vector2((engine.screen_size.x -300)/2,-40);
    text->shape.setShape({Vector2(300,0),Vector2(300,200),Vector2(0,200),Vector2(0,0)});
    text->color = Color(0.8,0.6,0.2,1);
    text->setFont("../comic.ttf", 150);
    text->setText("19  |  20");
    //text->rotate(180);
    engine.root.addChild(text);
}

void Setup(){
}