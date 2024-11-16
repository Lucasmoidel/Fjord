//TODO: Make a key class with functions like isHeld(), isDown(), isUp(), etc...
#ifndef Input_H
#define Input_H

class Input{
    public:
        Input();

        Json::Value keyMap;
        Json::Value initKeyMap();
        SDL_Event event;
        bool isHeld(const std::string actionName);
        bool isDown(const std::string actionName);
        bool isUp(const std::string actionName);

       std::vector<SDL_Keycode> getAction(const std::string actionName);
};
#endif