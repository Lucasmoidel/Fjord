#include "../Fjord.h"


std::vector<float> Shape::GetGLPointArray(){
    std::vector<float> glPoints;
    for (int i = 0; i<shape.size(), i++;){
        glPoints.push_back(shape[i].x);
        glPoints.push_back(shape[i].y);
    }
    return glPoints;
};