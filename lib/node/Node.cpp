#include "../Fjord.h"

Node::Node(int xPos, int yPos, int xSize, int ySize, std::string name){
    ID = name;
    transform.position.x = xPos;
    transform.position.y = yPos;
    transform.size.x = xSize;
    transform.size.y = ySize;
}

void Node::Render(SDL_Renderer* renderer){
    rect.x = transform.position.x;
    rect.y = transform.position.y;
    rect.w = transform.size.x;
    rect.h = transform.size.y;
    SDL_RenderDrawRect(renderer, &rect);
}

void Label::setText(std::string textin){
    Reload();
    text = textin;
}

void Label::Reload(){
    //SDL_FreeSurface(textSurface);
    textSurface = TTF_RenderText_Solid(Font, text.c_str(), color); 
    std::cout << SDL_GetError() << std::endl;
}

void Label::Render(SDL_Renderer* renderer){
    std::cout << SDL_GetError() << std::endl;
    rect.x = transform.position.x;
    rect.y = transform.position.y;
    rect.w = transform.size.x;
    rect.h = transform.size.y;
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    std::cout << SDL_GetError() << std::endl;
    SDL_RenderCopy(renderer, textTexture, NULL, &rect);

    //SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}