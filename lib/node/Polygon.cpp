#include "../Fjord.h"

void Polygon::Render() {
    std::vector<float>* vertexes = shape.GetGLPointArray(transform.global_position);
    std::cout << vertexes->size() << " vertext" << std::endl;
    engine.rendererGL.get()->fillShape(vertexes,0);
}