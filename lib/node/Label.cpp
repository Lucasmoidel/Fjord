#include "../Fjord.h"

void Label::Render(){
    std::vector<float>* vertexes = shape.GetGLPointArray(transform.global_position);
    RenderCall rc = {RenderCall::TEXT, vertexes, font, text};
    engine.back_buffer.push_back(rc);
}

void Label::setText(std::string intext){
    text = intext;
}

void Label::setFont(std::string fontname, int size){
    font = TTF_OpenFont(fontname.c_str(), size);
}