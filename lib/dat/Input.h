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
        const Uint8* keystates = SDL_GetKeyboardState(NULL);
        std::vector<SDL_Keycode> getAction(const std::string actionName);
};
#endif