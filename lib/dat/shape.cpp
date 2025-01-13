#include "../Fjord.h"


std::vector<float> Shape::GetGLPointArray(Vector2 global_position){
    std::vector<float> glPoints;
    for (int i = 0; i<shape.size(), i++;){
        glPoints.push_back(global_position.x+shape[i].x);
        glPoints.push_back(global_position.y+shape[i].y);
    }
    return glPoints;
};