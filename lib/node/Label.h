#ifndef Label_H
#define Label_H

#include "../Fjord.h"

class Label : public Polygon { // game engine that will provide functions    
    public:
        using Polygon::Polygon;

        std::string fontName;
        std::string text;
        void Render() override;

        void setText(std::string intext);
        void setFont(std::string fontname, int size);

        TTF_Font* font;
};

#endif