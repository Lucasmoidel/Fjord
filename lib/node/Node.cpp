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

void Node::update_node_position(){
    if (parent != NULL){
        transform.global_position = parent->transform.global_position + transform.position;
    }
}

// "../../hello/path"

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

void Node::engine_update_node(){ // Try to find a way that only engine class can call this function. should not be usuable by user
    update_node_position();
    Render();
    for (int i = 0; i < children.size(); i++){
        children[i]->engine_update_node();
        children[i]->Update();
        children[i]->Input();
    }
}