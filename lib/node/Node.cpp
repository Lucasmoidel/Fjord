#include "../Fjord.h"

Node::Node(int xPos, int yPos, int xSize, int ySize, std::string nameIn){
    name = nameIn;
    transform.position.x = xPos;
    transform.position.y = yPos;
    transform.scale.x = xSize;
    transform.scale.y = ySize;
}

void Node::AttachScript(std::string filePath){
    AttachedScript = Script(filePath, &engine.lua);
    InitializeScript();
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

        // Convert parent rotation to radians
        float radians = parent->transform.global_rotation * (M_PI / 180.0f);

        // Apply rotation to child's local position
        float x_orbit = transform.position.x * cos(radians) - transform.position.y * sin(radians);
        float y_orbit = transform.position.x * sin(radians) + transform.position.y * cos(radians);

        // Adjust position based on parent's scale (move outward/inward dynamically)
        float scaled_x = x_orbit * parent->transform.global_scale.x;
        float scaled_y = y_orbit * parent->transform.global_scale.y;

        transform.global_position.x = parent->transform.global_position.x + scaled_x;
        transform.global_position.y = parent->transform.global_position.y + scaled_y;

        // Correct hierarchical scaling (multiplicative)
        transform.global_scale.x = parent->transform.global_scale.x * transform.scale.x;
        transform.global_scale.y = parent->transform.global_scale.y * transform.scale.y;

        // Combine rotations
        transform.global_rotation = parent->transform.global_rotation + transform.rotation;
    }
    else {
        // No parent: global and local properties are the same
        transform.global_position = transform.position;
        transform.global_rotation = transform.rotation;
        transform.global_scale = transform.scale;
    }

    // Ensure rotation stays within valid bounds
    transform.rotation = Utilities::wrapRotation(transform.rotation);
    transform.global_rotation = Utilities::wrapRotation(transform.global_rotation);
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

void Node::InitializeScript(){
    std::cout << "Init Script..." << AttachedScript.filePath << std::endl;
    if (AttachedScript.ScriptEmpty){
        std::cout << "Exiting Init..." << std::endl;
        return;
    }
    auto result = engine.lua.script_file(AttachedScript.filePath,AttachedScript.env,sol::script_pass_on_error);
    std::cout << "Read File" << std::endl;
    if (!result.valid()){
        sol::error err = result;
        std::cerr << "[Script Error](" << AttachedScript.filePath << ") " << err.what() << std::endl;
        return;
    }

    sol::function initFunc = sol::protected_function(AttachedScript.env["Init"]);
    AttachedScript.UpdateFunc = AttachedScript.env["Update"];

    std::cout << initFunc.valid() << std::endl;
    if (initFunc.valid()){
        std::cout << "Executing..." << std::endl;
        auto initResult = initFunc(this);
        if (!initResult.valid()) {
            sol::error err = initResult;
            std::cerr << "[Script Error] Init failed (" << AttachedScript.filePath << "): " << err.what() << std::endl;
        }
    }

    RegisterProperties();
}

void Node::RegisterProperties() {
    AttachedScript.env["transform"] = &transform;
    AttachedScript.env["get_node"] = &get_node();
}

void Node::RunUpdateFunction(){
    if (AttachedScript.UpdateFunc.valid()){
        auto updateResult = AttachedScript.UpdateFunc(Time::deltaTime);
    }
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
    if (!AttachedScript.ScriptEmpty){
        RunUpdateFunction();
    }
    update_node_position();
    Render();
    for (size_t i = 0; i < children.size(); i++){
        children[i]->_engine_update_node();
        children[i]->Update();
        children[i]->Input();
    }
}