#ifndef Fjord_H
#define Fjord_H
#include <iostream> 
#include <string> 
#include <vector> 
#include <SDL2/SDL.h>


class Node{
    public:
        void update();
};

class Engine{
        
    public:
        std::vector<Node> nodes;
        int createObject();
};

extern Engine engine;

#endif // MYHEADER_H