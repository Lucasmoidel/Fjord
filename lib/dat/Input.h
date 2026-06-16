//TODO: Make a key class with functions like isHeld(), isDown(), isUp(), etc...
#ifndef Input_H
#define Input_H
#include "../Fjord.h"
class Input{
    public:
        Input();

        nlohmann::json keyMap;
        nlohmann::json initKeyMap();
        SDL_Event event;
        bool isHeld(const std::string actionName);
        bool isDown(const std::string actionName);
        bool isUp(const std::string actionName);
        const bool* keystates = SDL_GetKeyboardState(NULL);
        std::vector<std::vector<SDL_Keycode>> getAction(const std::string actionName);
        void addActiveLayer(std::string name);
        void removeActiveLayer(std::string name);
        std::vector<std::string> activeLayers;
};
#endif