#include "../Fjord.h"

Input::Input(){
    keyMap = initKeyMap();
}

nlohmann::json Input::initKeyMap(){
    nlohmann::json keys;
    std::ifstream keyMap_file("keyMap.json", std::ifstream::binary);
    keyMap_file >> keys;
    //keys = nlohmann::json::parse(keyMap_file);
    return keys;
}

bool Input::isDown(const std::string actionName){
    bool down = false;
    std::vector<SDL_Keycode> keycodes = getAction(actionName);
    for (size_t i = 0; i < keycodes.size(); i++){
        if (keystates[SDL_GetScancodeFromKey(keycodes[i])]){
            down = true;
            break;
        }
    }
    return down;
}

std::vector<SDL_Keycode> Input::getAction(const std::string actionName) {
    nlohmann::json keys = keyMap["actions"][actionName];
    std::vector<SDL_Keycode> keycodes;
    for (size_t i=0; i<keys.size();i++){
        std::string keyName = keys[i].get<std::string>();
        keycodes.push_back(SDL_GetKeyFromName(keyName.c_str()));
    }
    return keycodes;
}