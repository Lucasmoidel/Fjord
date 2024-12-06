#ifndef Node_H
#define Node_H

#include <iostream> 
#include <SDL2/SDL.h>
#include "../Fjord.h"

class Node { // game engine that will provide functions    
    public:
        Node(int xVar=0, int yVar=0, int xSize=1, int ySize=1, std::string name = "Node2D");

        std::string name;
        std::string id;
        Transform transform;

        virtual void Update(float delta){}; // Definition of Update Function. Called once every frame
        virtual void Input(){}; // Definition of Input Function. Called once very frame.
        virtual void Render(SDL_Renderer* renderer);
        SDL_Rect rect;
        
        std::vector<Node*> get_children();

        template <typename T> T* createNode(int xPos, int yPos, int xSize, int ySize, std::string name);

    private:

        std::vector<Node*> children;
};

#endif // MYHEADER_H