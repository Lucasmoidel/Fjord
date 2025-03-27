#include "../Fjord.h"

void Polygon::Render() {
    std::vector<float>* vertexes = shape.GetGLPointArray(transform.global_position);
    RenderCall rc = {RenderCall::POLYGON, vertexes};
    engine.back_buffer.push_back(rc);
}