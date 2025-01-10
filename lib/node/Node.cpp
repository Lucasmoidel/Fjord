#include "../Fjord.h"

Node::Node(int xPos, int yPos, int xSize, int ySize, std::string nameIn){
    name = nameIn;
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
    std::cout << splitPath[0] << "\n";
    Node* searchPointer = this;
    for (int i = 0; i<splitPath.size(); i++){
        std::cout << searchPointer->name << "\n";
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
                printf("null ptr !!!!!!!!!");
                return NULL;
            }
        }
    }
    std::cout << "Returning\n";
    return searchPointer;
}

void Node::kill_child(std::string namein, int killall){
    Node* child = NULL;
    for (int i = 0; i < children.size(); i++){
        if (killall = 1 || children[i]->name == namein){
            child = children[i];
            children.erase(children.begin() + i);
            child->kill_child("", 1);
            delete child;// sus
        }
    }
}

void Node::Render(RendererGL* renderer){
    for (int i = 0; i < children.size(); i++){
        children[i]->Render(renderer);
        children[i]->Update();
        children[i]->Input();
    }
    rect.x = transform.position.x;
    rect.y = transform.position.y;
    rect.w = transform.size.x;
    rect.h = transform.size.y;
    renderer->fillOval(&rect);
}