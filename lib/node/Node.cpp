#include "../Fjord.h"

Node::Node(int xPos, int yPos, int xSize, int ySize, std::string name){
    ID = name;
    transform.position.x = xPos;
    transform.position.y = yPos;
    transform.size.x = xSize;
    transform.size.y = ySize;
}