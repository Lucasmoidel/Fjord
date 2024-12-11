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

Node* Node::get_node(std::string path){
    std::vector<std::string> splitPath = Utilities::SplitString(path,"/");
    Node* searchPointer;
    for (int i = 0; i<splitPath.size(); i++){
        if (splitPath[i] == ".."){
            searchPointer = parent;
        } else {
            bool found = false;
            for (int childIndex=0;childIndex<searchPointer->children.size();childIndex++){
                if (searchPointer->children[childIndex]->name == splitPath[i]){
                    searchPointer = searchPointer->children[childIndex];
                    found = true;
                    break;
                }
            }
            if (!found){
                return NULL;
            }
        }
    }
    return searchPointer;
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