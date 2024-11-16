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
    return true;
}

SDL_Keycode Input::getAction(const std::string actionName) {
    Json::Value keys = keyMap["actions"][actionName];
    SDL_Keycode keycodes[10];
    for (int i=0; i<keys.size();i++){
        keycodes[i] = SDL_GetKeyFromName(keys[i].asCString());
    }
    return ;
}