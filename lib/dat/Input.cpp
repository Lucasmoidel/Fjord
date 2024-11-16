#include "../Fjord.h"
#include <jsoncpp/json/json.h>
#include <fstream>

void Input::initKeyMap(){
    std::ifstream keyMap_file("example/keyMap.json", std::ifstream::binary);
    Json::Value keyMap;
    keyMap_file >> keyMap;

    std::cout << keyMap; //This will print the entire json object.

}