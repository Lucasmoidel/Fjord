#ifndef Transform_H
#define Transform_H

#include "Fjord.h"

class Transform {
    public:
        Vector2 position = Vector2(50, 50); // Default Value (0,0)
        Vector2 scale = Vector2(1, 1);
        Vector2 size = Vector2(1, 1);
};

#endif