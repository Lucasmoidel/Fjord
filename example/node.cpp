#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../lib/Fjord.h"

using namespace Util;

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
        rotate(180*Time::deltaTime);
    } else if (input.isDown("RLeft")){
        rotate(-180*Time::deltaTime);
    }

}

void Start(){
    input.enableLayer("main");
    std::cout << Vector2(50, 20).normalized().x << "\n";
    Box *square = engine.root.createNode<Box>((engine.screen_size.x /2 )-10, (engine.screen_size.y /2 )-10,1,1,"Box");
    square->shape.setShape(Util::rect(true, 40, 40));
    square->color = Color(0.2,0.8,0.6,1);
    engine.root.addChild(square);

    std::string s = "19 | 20";
    int textSize = 160;
    Label *text = engine.root.createNode<Label>(Util::center(engine.screen_size.x,(s.length()*(textSize*0.3))),Util::center(engine.screen_size.y,textSize),1,1,"text");
    text->color = Color(0.8,0.6,0.2,1);
    text->setFont("../comic.ttf", textSize);
    text->setText(s);
    engine.root.addChild(text);
}

void Setup(){
}