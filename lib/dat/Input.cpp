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
    bool group = true;
    std::vector<std::vector<SDL_Keycode>> keycodes = getAction(actionName);
    for (size_t i = 0; i < keycodes.size(); i++){
        group = true;
        for (size_t x = 0; x < keycodes.at(i).size(); x++){
            if (!keystates[SDL_GetScancodeFromKey(keycodes[i][x], SDL_KMOD_NONE)]){
                group = false;
            }
        }
        if(group){
            down = true;
        }
    }
    return down;
}

std::vector<std::vector<SDL_Keycode>> Input::getAction(const std::string actionName) {
    nlohmann::json action = keyMap["actions"][actionName]["binds"];
    nlohmann::json layers = keyMap["actions"][actionName]["layers"];
    std::vector<std::vector<SDL_Keycode>> keycodes;
    std::vector<SDL_Keycode> codes;
    nlohmann::json binds;
    bool layer = false;
    for (size_t i = 0; i <layers.size(); i++){
        for (int x = 0; x < activeLayers.size(); x++){
            if (layers[i]["name"] == activeLayers.at(x)){
                layer = true;
            }
        }
    }
    if (layer){ 
        for (size_t i=0; i<action.size(); i++){
            binds = action[i]["keys"];
            
            for (size_t x = 0; x < binds.size(); x++){
                std::string keyName = binds[x].get<std::string>();
                codes.push_back(SDL_GetKeyFromName(keyName.c_str()));
            }
            keycodes.push_back(codes);
            codes.clear();

        }
    }
    return keycodes;
}

void Input::enableLayer(std::string name){
    bool can = true;
    for (size_t i = 0; i < activeLayers.size(); i++){
        if (name == activeLayers.at(i)){
            can = false;
        }
    }
    if (can){
        activeLayers.push_back(name);
    }
}

void Input::disableLayer(std::string name){
    for (size_t i = 0; i < activeLayers.size(); i++){
        if (name == activeLayers.at(i)){
            activeLayers.erase(activeLayers.begin()+i);
            break;
        }
    }
}