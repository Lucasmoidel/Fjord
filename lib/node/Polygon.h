#ifndef POLYGON_H
#define POLYGON_H

#include "../Fjord.h"

class Polygon : public Node {
    public:
        using Node::Node;
        Shape shape;

        void Render() override;
    
    private:
        void _rotate_points();
};

#endif