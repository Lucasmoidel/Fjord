//TODO: Make a key class with functions like isHeld(), isDown(), isUp(), etc...
#ifndef Input_H
#define Input_H

class Input{
    public:
        //Input();

        Input();

        bool isHeld(const std::string actionName);
        bool isDown(const std::string actionName);
        bool isUp(const std::string actionName);

    private:

        Json::Value keyMap;
        Json::Value initKeyMap();
        std::array<SDL_Keysym,10> getAction(const std::string actionName);
};
#endif