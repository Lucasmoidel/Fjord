#ifndef Fjord_H
#define Fjord_H

#include <vector> 
#include <SDL2/SDL.h>
#include "datatypes/Vector2.h"

class Node{ // default node class
    public:
        Node(int xPos, int yPos, int width, int height, int zIndex);// add constructor with vars for rendering
        void update(); // update function
        Vector2 position = Vector2(0, 0);
        Vector2 scale = Vector2(50, 50);
        int zIndex; // create vars that go in rect
        SDL_Rect rect; // sdl rect for rendering
};

class Engine{ // game engine that will provide functions
        
    public:
        std::vector<Node> nodes; // create array to store all Node objects
        void createTilemap();
        Node createObject(); // creates a Node object
        bool initObjs(); // Dev difined: run createObjects and do stuff
        bool initWin(int Win_width, int Win_height, std::string name); //intitilize sdl2 window with the width, height, and name of window
        bool gameRuning; // var that controlls if the game is running
        void gameLoop(); // The main game loop
        void processInput(); // process keyboard inputs
        void render(); // render objects
        void destroyWindow(); // destroy window when game exits

        SDL_Window* window = NULL; // SDL window object
        SDL_Renderer* renderer = NULL; //SDL renderer object

};

extern Engine engine; // makes the engine object available globaly part1 see main.cpp for part 2



#endif // MYHEADER_H