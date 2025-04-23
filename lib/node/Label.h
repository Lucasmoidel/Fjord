#ifndef Label_H
#define Label_H

#include "../Fjord.h"

class Label : public Node { // game engine that will provide functions    
    public:
        Label(int xPos, int yPos, int xSize, int ySize, std::string nameIn);

        std::string fontName;
        std::string text;
        void Render() override;

        TTF_Font* font;
};

#endif