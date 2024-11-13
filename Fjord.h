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
        void createObject();
        bool gameRuning;
        void gameLoop();
        bool initObjs();
};

extern Engine engine;



#endif // MYHEADER_H