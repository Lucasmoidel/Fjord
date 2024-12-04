#ifndef Node_H
#define Node_H

#include <iostream> 
#include <SDL2/SDL.h>
#include "../Fjord.h"

class Node { // game engine that will provide functions    
    public:
        Node(int xVar=0, int yVar=0, int xSize=1, int ySize=1, std::string name = "NO_NAME");
        std::string ID;
        Transform transform;
        int speed = 250;
        virtual void Update(float delta){}; // Definition of Update Function. Called once every frame
        virtual void Input(){}; // Definition of Input Function. Called once very frame.
        virtual void Render(SDL_Renderer* renderer);
        SDL_Rect rect;
        
};
class Label : public Node{
    private:
        std::string text = "";
    public:
        TTF_Font* Font = NULL;
        using Node::Node;
        void setText(std::string = "");
        void Reload();
        void Render(SDL_Renderer* renderer) override; 
};

#endif // MYHEADER_H