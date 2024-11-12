#include <iostream>
#include "../Fjord.h"

using namespace std;

int main(){
    initSDL("example", 500, 500, window, renderer);
    while(true){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    }
    return 0;
}