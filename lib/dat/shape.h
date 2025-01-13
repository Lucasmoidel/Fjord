#ifndef SHAPE_H
#define SHAPE_H


#include "../Fjord.h"

class Shape {
    public:
        std::vector<Vector2> shape;

        std::vector<float> GetGLPointArray(Vector2 global_positon);
};

#endif