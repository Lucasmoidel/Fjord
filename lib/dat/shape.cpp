#include "../Fjord.h"


std::vector<float>* Shape::GetGLPointArray(Vector2 global_position){
    std::vector<float>* glPoints = new std::vector<float>();
    //std::cout << shape.size() << "sizeeeeee" << std::endl;
    for (int i = 0; i < shape.size(); i++){
        //std::cout << "adding points" << std::endl;
        glPoints->push_back(global_position.x+shape[i].x);
        glPoints->push_back(global_position.y+shape[i].y);
    }
    //std::cout << glPoints->size() << std::endl;
    return glPoints;
};