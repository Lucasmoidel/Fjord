#include "../Fjord.h"

void Label::Render(){
    SDL_Surface* textSurface = TTF_RenderText_Blended(font, text.c_str(), text.length(), (SDL_Color){255, 255, 255, 255});
    assert(!textSurface);

    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textSurface->w, textSurface->h, 0, GL_RGBA,
                 GL_UNSIGNED_BYTE, textSurface->pixels);

    SDL_DestroySurface(textSurface);

}

void Label::setText(std::string intext){
    text = intext;
}

void Label::setFont(std::string fontname, int size){
    font = TTF_OpenFont(fontname.c_str(), size);
}