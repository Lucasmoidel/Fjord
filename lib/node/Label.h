#ifndef LABEL_H
#define LABEL_H

#include "../Fjord.h"

class Label : public Node {
    public:
        using Node::Node;
        Shape shape;
        Color color;
        void setText(std::string intext);
        void setFont(std::string fontname, int size);
        void Render() override;
        TTF_Font* font;
        std::string text;
    
    private:
        std::vector<Vector2> _rotate_points();
};

#endif