#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../lib/Fjord.h"

using namespace Utilities;

class Box : public Polygon {
    public:
        using Polygon::Polygon;

        Vector2 direction = Vector2(0,0);

        void Update() override;
};

void Box::Update() {
    transform.rotation += 100 * Time::deltaTime;
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
    square->transform.scale = 0.5;
    

    Box *square2 = square->createNode<Box>(0,0,1,1,"Box1");
    square2->transform.position = Vector2(0,0.2);
    square2->shape.setShape({Vector2(-0.1,0.1),Vector2(0.1,0.1),Vector2(0.1,-0.1),Vector2(-0.1,-0.1)});
    
    Box *square3 = square2->createNode<Box>(0,0,1,1,"Box2");
    square3->transform.position = Vector2(0,0.2);
    square3->shape.setShape({Vector2(-0.1,0.1),Vector2(0.1,0.1),Vector2(0.1,-0.1),Vector2(-0.1,-0.1)});
    
    Box *square4 = square3->createNode<Box>(0,0,1,1,"Box3");
    square4->transform.position = Vector2(0,0.2);
    square4->shape.setShape({Vector2(-0.1,0.1),Vector2(0.1,0.1),Vector2(0.1,-0.1),Vector2(-0.1,-0.1)});
    
    Polygon *second_box = square4->createNode<Polygon>(0,0,1,1,"Box4");
    second_box->transform.position = Vector2(0,0.1);
    second_box->shape.setShape({Vector2(-0.1,0.1),Vector2(0.1,0.1),Vector2(0.1,-0.1),Vector2(-0.1,-0.1)});
}

void Setup(){
}