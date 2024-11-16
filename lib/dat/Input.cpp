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

Input::Input(){
    keyMap = initKeyMap();
}

Json::Value Input::initKeyMap(){
    Json::Value keys;
    std::ifstream keyMap_file("../example/keyMap.json", std::ifstream::binary);
    keyMap_file >> keys;
    return keys;
}

bool Input::isDown(const std::string actionName){
    getAction(actionName);
    std::cout << "hello" << std::endl; 
}

std::array<SDL_Keysym,10> Input::getAction(const std::string actionName) {
    std::string keys[] = keyMap["actions"][actionName];
}