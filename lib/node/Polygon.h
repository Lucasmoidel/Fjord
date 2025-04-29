#ifndef POLYGON_H
#define POLYGON_H

#include "../Fjord.h"

class Polygon : public Node {
    public:
        using Node::Node;
        Shape shape;
        Color color;

        void Render() override;

        void RegisterProperties() override;
    
    private:
        std::vector<Vector2> _rotate_points();
};

#endif