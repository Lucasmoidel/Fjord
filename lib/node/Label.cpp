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

Label::Label(int xPos, int yPos, int xSize, int ySize, std::string nameIn) : Node(xPos, yPos, xSize, ySize, nameIn){

}