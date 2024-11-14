#include <iostream>
#include "Fjord.h"

class Node1 : public Node {
    public:

        Vector2 direction = Vector2(1,1);

        void Update() override {

            transform.position += direction;
            std::cout << direction << std::endl;
            if (transform.position.x > 300){
                direction.x = -1;
            } else if (transform.position.x < 0){
                direction.x = 1;
            }
            if (transform.position.y > 300){
                direction.y = -1;
            } else if (transform.position.y < 0){
                direction.y = 1;
            }
        }
};

void thing(){
    Node1* node = new Node1();
    node->transform.position = Vector2(150,50);

    if (node == nullptr){
        printf("NULL\n");
    }

    engine.nodes.push_back(node);
    Vector2 vec = Vector2(2,3);
    Vector2 vec2 = Vector2(10,5);
    Vector2 vec3;

    std::cout << vec << std::endl;
    std::cout << vec2 << std::endl;

    vec3 = vec-vec2;

    std::cout << vec3 << std::endl;
}
