#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../lib/Fjord.h"

using namespace Utilities;

class Box : public Polygon {
    public:
        using Polygon::Polygon;

        int direction = 1;

        void Update() override;
};

void Box::Update() {
    transform.scale += Vector2(0.5,0.5) * Time::deltaTime * direction;
    rotate(15*Time::deltaTime);
    if (transform.scale.x > 3 && direction == 1){
        direction = -1;
    } else if (transform.scale.x < 0.5 && direction == -1){
        direction = 1;
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
    Box *square = engine.root.createNode<Box>(0,0,1,1,"Box");
    square->transform.position = Vector2(0,0.3);
    square->shape.setShape({Vector2(-0.1,0.1),Vector2(0.1,0.1),Vector2(0.1,-0.1),Vector2(-0.1,-0.1)});
    square->transform.scale = Vector2(0.5,0.5);
    
    Box *square2 = square->createNode<Box>(0,0,1,1,"Box1");
    square2->transform.position = Vector2(0,0.2);
    square2->shape.setShape({Vector2(-0.1,0.1),Vector2(0.1,0.1),Vector2(0.1,-0.1),Vector2(-0.1,-0.1)});
}

void Setup(){
}