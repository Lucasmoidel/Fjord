#include <iostream>
#include "Fjord.h"

class Node1 : public Node{};


void thing(){
    Node1 node;
    engine.nodes.push_back(node);
    Vector2 vec = Vector2(2,3);
    Vector2 vec2 = Vector2(10,5);
    Vector2 vec3;

    std::cout << vec << std::endl;
    std::cout << vec2 << std::endl;

    vec3 = vec-vec2;

    std::cout << vec3 << std::endl;
}
