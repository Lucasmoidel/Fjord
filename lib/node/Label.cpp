#include "../Fjord.h"

void Label::Render() {
    //printf("Made it here\n");
    shape.shape = _rotate_points();
    std::vector<float>* vertexes = shape.GetGLPointArray(transform.global_position);
    RenderCall rc = {RenderCall::TEXT, vertexes, color, font, text};
    engine.back_buffer.push_back(rc);
}

std::vector<Vector2> Label::_rotate_points() {
    float radians = transform.global_rotation * (M_PI / 180.0f); // Use the node's own rotation (local or global)
    std::vector<Vector2> rotatedPoints;

    for (const Vector2& point : shape.originalShape) { // Use the original unrotated points
        // Apply rotation relative to the node's local (0, 0)
        //point * transform.scale;
        float rotated_x = point.x * cos(radians) - point.y * sin(radians);
        float rotated_y = point.x * sin(radians) + point.y * cos(radians);

        // Store the rotated points
        rotatedPoints.emplace_back(rotated_x*transform.scale.x, rotated_y*transform.scale.y);
    }

    return rotatedPoints; // Return rotated points
}

void Label::setText(std::string intext){
    text = intext;
}

void Label::setFont(std::string fontname, int size){
    font = TTF_OpenFont(fontname.c_str(), size);
}

