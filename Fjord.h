#ifndef Fjord_H
#define Fjord_H
#include <iostream> 
#include <string> 
#include <vector> 
#include <SDL2/SDL.h>


class Node{ // default node class
    public:
        Node(int xPos, int yPos, int width, int height, int zIndex);
        void update();
        int x, y, w, h, zIndex;
        SDL_Rect rect;
};

class Engine{ // game engine that will provide functions
        
    public:
        std::vector<Node> nodes; // create array to store all Node objects
        void createTilemap();
        void createObject(); // creates a Node object
        bool initObjs(); // Dev difined: run createObjects and do stuff
        bool initWin(int Win_width, int Win_height, std::string name); //intitilize sdl2 window with the width, height, and name of window
        bool gameRuning; // var that controlls if the game is running
        void gameLoop(); // The main game loop
        void processInput();
        void destroyWindow();
        void render();
        SDL_Window* window = NULL; // SDL window object
        SDL_Renderer* renderer = NULL; //SDL renderer object

};

extern Engine engine; // makes the engine object available globaly part1 see main.cpp for part 2



#endif // MYHEADER_H