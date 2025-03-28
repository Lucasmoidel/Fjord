#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../lib/Fjord.h"

using namespace Utilities;

class Box : public Polygon {
    public:
        using Polygon::Polygon;
        Vector2 position = Vector2(0,0);
        Vector2 direction = Vector2(1,0.75);

        void Update() override;
};

void Box::Update() {
    position.x += direction.x * Time::deltaTime * 1;
    position.y += direction.y * Time::deltaTime * 1;
    if (position.x < -0.5){
        direction.x = 1.0f;
    } else if (position.x > 0.5){
        direction.x = -1.0f;
    }
    if (position.y < -0.5){
        direction.y = 0.75f;
    } else if (position.y > 0.5){
        direction.y = -0.75f;
    }
    transform.position = position;
}

void Start(){
    //printf("\n\n\nStarted!!\n\n\n");
    Box *square = engine.root.createNode<Box>(0,0,1,1,"Box");
    square->transform.position = Vector2(0,0.2);
    square->shape.shape = {Vector2(0,0),Vector2(0.1,0),Vector2(0.1,0.1),Vector2(0,0.1)};
}

void Setup(){
}