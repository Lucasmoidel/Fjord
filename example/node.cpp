#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../lib/Fjord.h"

using namespace Utilities;

class Box : public Polygon {
    public:
        using Polygon::Polygon;
        Vector2 position = Vector2(0,0);
        int direction = 1;

        void Update() override;
};

void Box::Update() {
    printf("Update");
    position.x += direction * Time::deltaTime;
    if (position.x < 1){
        direction = 1;
    } else if (position.x > 1){
        direction = -1;
    }
    transform.position = position;
}

void Start(){
    //printf("\n\n\nStarted!!\n\n\n");
    Box *square = engine.root.createNode<Box>(0,0,1,1,"Box");
    square->transform.position = Vector2(-0.4,0.2);
    square->shape.shape = {Vector2(0,0),Vector2(0.1,0),Vector2(0.1,0.1),Vector2(0,0.1)};
}

void Setup(){
}