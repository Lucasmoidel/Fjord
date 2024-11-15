#ifndef Node_H
#define Node_H

#include <iostream> 
#include <SDL2/SDL.h>
#include "../Fjord.h"

class Node { // game engine that will provide functions    
    public:
        Node(int xVar=0, int yVar=0);
        Transform transform;
        virtual void Update(){}; // Definition of Update Function. Called once every frame
        virtual void Input(SDL_Event events){}; // Definition of Input Function. Called once very frame.

        SDL_Rect rect;
        
};

#endif // MYHEADER_H