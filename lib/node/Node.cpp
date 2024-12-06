#include "../Fjord.h"

Node::Node(int xPos, int yPos, int xSize, int ySize, std::string name){
    id = name;
    transform.position.x = xPos;
    transform.position.y = yPos;
    transform.size.x = xSize;
    transform.size.y = ySize;
}

std::vector<Node*> Node::get_children(){
    std::cout << name << "\n";
    return children;
}

template <typename T> T* Node::createNode(int xPos, int yPos, int xSize, int ySize, std::string name){
    T* node = new T(xPos, yPos, xSize, ySize, name);
    engine.nodes.push_back(node);
    children.push_back(node);
    return node;
}

void Node::Render(SDL_Renderer* renderer){
    rect.x = transform.position.x;
    rect.y = transform.position.y;
    rect.w = transform.size.x;
    rect.h = transform.size.y;
    SDL_RenderDrawRect(renderer, &rect);
}