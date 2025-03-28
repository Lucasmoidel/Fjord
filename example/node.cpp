#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../lib/Fjord.h"

using namespace Utilities;

class Box : public Polygon {
    public:
        using Polygon::Polygon;

        void Update() override;
};

void Box::Update() {
    transform.rotation += 100 * Time::deltaTime;
}

void Start(){
    //printf("\n\n\nStarted!!\n\n\n");
    Box *square = engine.root.createNode<Box>(0,0,1,1,"Box");
    square->transform.position = Vector2(0,0.2);
    square->shape.shape = {Vector2(0,0),Vector2(0.1,0),Vector2(0.1,0.1),Vector2(0,0.1)};

    Polygon *second_box = square->createNode<Polygon>(0,0,1,1,"Box2");
    second_box->transform.position = Vector2(0,0.2);
    second_box->shape.shape = {Vector2(0,0),Vector2(0.1,0),Vector2(0.1,0.1),Vector2(0,0.1)};
}

void Setup(){
}