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

int Node::get_children_count(){
    return children.size();
}

void Node::Render(SDL_Renderer* renderer){
    for (int i = 0; i < children.size(); i++){
        children[i]->Render(renderer);
        children[i]->Update();
        children[i]->Input();
    }
    rect.x = transform.position.x;
    rect.y = transform.position.y;
    rect.w = transform.size.x;
    rect.h = transform.size.y;
    SDL_RenderDrawRect(renderer, &rect);
}