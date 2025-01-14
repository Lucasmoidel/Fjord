#include "../Fjord.h"

void Polygon::Render() {
    engine.rendererGL.get()->fillShape(shape.GetGLPointArray(transform.global_position),0);
}