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

void Node::update_node_position() {
    if (parent != nullptr) {

        // 1. Calculate the child's global position based on parent's global position and rotation
        float radians = parent->transform.global_rotation * (M_PI / 180.0f); // Convert parent rotation to radians

        // Rotate the child's local position around the parent
        float x_orbit = transform.position.x * cos(radians) - transform.position.y * sin(radians);
        float y_orbit = transform.position.x * sin(radians) + transform.position.y * cos(radians);

        transform.global_position.x = parent->transform.global_position.x + x_orbit;
        transform.global_position.y = parent->transform.global_position.y + y_orbit;

        // 2. Calculate the child's global rotation
        transform.global_rotation = parent->transform.global_rotation + transform.rotation; // Combine rotations
    }
    else {
        // If no parent, global position and rotation are the same as local
        transform.global_position = transform.position;
        transform.global_rotation = transform.rotation;
    }
    transform.rotation = Utilities::wrapRotation(transform.rotation);
    transform.global_rotation = Utilities::wrapRotation(transform.global_rotation);


    // Additional logic for child nodes (e.g., rendering, rotating points, etc.)
}

void Node::rotate(float degrees){
    transform.rotation += degrees;
}

// "../../hello/path"

Node* Node::get_node(std::string path){
    std::vector<std::string> splitPath = Utilities::SplitString(path,"/");
    std::cout << splitPath[0] << "\n";
    Node* searchPointer = this;
    for (size_t i = 0; i<splitPath.size(); i++){
        std::cout << searchPointer->name << "\n";
        if (splitPath[i] == ".."){
            searchPointer = parent;
        } else {
            bool found = false;
            for (size_t childIndex=0;childIndex<searchPointer->children.size();childIndex++){
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

void Node::kill_child(std::string namein){
    Node* child = NULL;
    for (size_t i = 0; i < children.size(); i++){
        if ( namein == "" || children[i]->name == namein){
            child = children[i];
            children.erase(children.begin() + i);
            child->kill_child("");
            delete child;// sus
        }
    }
}

void Node::_engine_update_node(){ // Try to find a way that only engine class can call this function. should not be usuable by user
    update_node_position();
    Render();
    for (size_t i = 0; i < children.size(); i++){
        children[i]->_engine_update_node();
        children[i]->Update();
        children[i]->Input();
    }
}