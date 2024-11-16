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
    std::vector<SDL_Keycode> keycodes = getAction(actionName);
    for (int i = 0; i < keycodes.size(); i++){
        if (event.type == SDL_KEYDOWN){
        if (event.key.keysym.sym == keycodes[i]){
            return true;
        }}
    }
    return false;
}

bool Input::isUp(const std::string actionName){
    std::vector<SDL_Keycode> keycodes = getAction(actionName);
    for (int i = 0; i < keycodes.size(); i++){
        if (event.type == SDL_KEYUP){
        if (event.key.keysym.sym == keycodes[i]){
            return true;
        }}
    }
    return false;
}

std::vector<SDL_Keycode> Input::getAction(const std::string actionName) {
    Json::Value keys = keyMap["actions"][actionName];
    std::vector<SDL_Keycode> keycodes;
    for (int i=0; i<keys.size();i++){
        keycodes.push_back(SDL_GetKeyFromName(keys[i].asCString()));
    }
    return keycodes;
}