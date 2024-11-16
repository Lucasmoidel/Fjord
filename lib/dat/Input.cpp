#include <iostream>
#include "../Fjord.h"
//#include "../../config.h"
#ifdef LINUX_UBUNTU
#include "jsoncpp/json/json.h"
#elif defined(LINUX_ARCH)
#include "json/json.h"
#else
#include "jsoncpp/json/json.h"
#endif

#include <fstream>

void Input::initKeyMap(){
    std::ifstream keyMap_file("example/keyMap.json", std::ifstream::binary);
    Json::Value keyMap;
    keyMap_file >> keyMap;

    std::cout << keyMap; //This will print the entire json object.

}