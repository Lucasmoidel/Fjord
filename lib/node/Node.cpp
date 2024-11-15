#include "../Fjord.h"

void Node::Update() {}

Node::Node(){
    engine.nodes.push_back(this);
}