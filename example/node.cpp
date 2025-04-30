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

    transform.scale += Vector2(0.5,0.5) * Time::deltaTime * direction;
    rotate(15*Time::deltaTime);
    if (transform.scale.x > 3 && direction == 1){
        direction = -1;
    } else if (transform.scale.x < 0.5 && direction == -1){
        direction = 1;
    }
    if (color.r > 1 || color.r < 0){rDir = rDir * -1;}
    if (color.g > 1 || color.g < 0){gDir = rDir * -1;}
    if (color.b > 1 || color.b < 0){bDir = bDir * -1;}
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
    #if 0
    Box *square = engine.root.createNode<Box>(0,0,1,1,"Box");
    square->transform.position = Vector2(0,0.3);
    square->shape.setShape({Vector2(-0.1,0.1),Vector2(0.1,0.1),Vector2(0.1,-0.1),Vector2(-0.1,-0.1)});
    square->transform.scale = Vector2(0.5,0.5);
    
    square->color = Color(0.2,0.8,0.6,1);
    engine.root.addChild(square);
    
    Box *square2 = square->createNode<Box>(0,0,1,1,"Box1");
    square2->transform.position = Vector2(0,0.2);
    square2->shape.setShape({Vector2(-0.1,0.1),Vector2(0.1,0.1),Vector2(0.1,-0.1),Vector2(-0.1,-0.1)});
    square2->color = Color(0.8,0.6,0.2,1);
    square->addChild(square2);
    #endif
    
#if 1
    Label *text = engine.root.createNode<Label>(0,0,1,1,"text");
    text->transform.position = Vector2(0,0.2);
    text->shape.setShape({Vector2(-0.1,0.1),Vector2(0.1,0.1),Vector2(0.1,-0.1),Vector2(-0.1,-0.1)});
    text->color = Color(0.8,0.6,0.2,1);
    text->setFont("../NotoSansMono-Regular.ttf", 12);
    text->setText("test");
    engine.root.addChild(text);
#endif
    

}

void Setup(){
}