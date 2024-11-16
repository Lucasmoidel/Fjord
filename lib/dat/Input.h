//TODO: Make a key class with functions like isHeld(), isDown(), isUp(), etc...
#ifndef Input_H
#define Input_H
class Input{
    public:
        //Input();
        void initKeyMap();
        bool isHeld();
        bool isDown();
        bool isUp();
};
#endif