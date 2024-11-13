#include <iostream> 
#include <string> 
#include <vector> 
#include "../Fjord.h"

int createObject(){
    Node node;
    engine.nodes.push_back(node);
    return engine.nodes.size()-1;
}

int main(){
    for (int i = 0; i < (int)engine.nodes.size(); i++){
        engine.nodes[i].update();
    }
    return 0;
}