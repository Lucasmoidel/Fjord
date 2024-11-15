#ifndef Node_H
#define Node_H

#include <iostream> 
#include <SDL2/SDL.h>
#include "../Fjord.h"

class Node { // game engine that will provide functions    
    public:
        Node();
        Transform transform;
        virtual void Update(){};

        SDL_Rect rect;
        
};

#endif // MYHEADER_H