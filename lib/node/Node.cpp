#include "../Fjord.h"

Node::Node(int xPos, int yPos){
    transform.position.x = xPos;
    transform.position.y = yPos;
    engine.nodes.push_back(this);
}